#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include <Eigen/Dense>
#include <lin_alg/mat_mul.h>

int main() {
    const std::size_t N = 200;
    std::vector<double> A(N*N), B(N*N), C(N*N);
    Eigen::MatrixXd eA(N, N), eB(N, N), eC(N, N);

    // Mersenne-Twister generator
    std::mt19937 gen;
    gen.seed(0);

    std::uniform_real_distribution<> dist(-1.0, 1.0);
    for (std::size_t i = 0; i < N*N; ++i) {
        A[i] = B[i] = dist(gen);
        eA.data()[i] = eB.data()[i] = A[i];
    }

    // Using local implementation
    auto t0 = std::chrono::high_resolution_clock::now();
    lin_alg::mat_mul(A, B, C, N);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dt_naive = t1 - t0;
    std::cout << "Local multiply took " << dt_naive.count() << " s\n";

    // Using Eigen implementation
    t0 = std::chrono::high_resolution_clock::now();
    eC = eA * eB;
    t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dt_eigen = t1 - t0;
    std::cout << "Eigen multiply took " << dt_eigen.count() << " s\n";

    // Verify
    double max_err = 0;
    for (std::size_t i = 0; i < N*N; ++i) {
        max_err = std::max(max_err, std::abs(C[i] - eC.data()[i]));
    }
    std::cout << "Max abs error = " << max_err << "\n";

    return 0;
}
