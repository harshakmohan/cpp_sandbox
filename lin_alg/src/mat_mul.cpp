#include "lin_alg/mat_mul.h"

namespace lin_alg {

void mat_mul(const std::vector<double>& A,
             const std::vector<double>& B,
             std::vector<double>& C,
             std::size_t N) {
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            double sum = 0;
            for (std::size_t k = 0; k < N; ++k) {
                sum += A[i*N + k] * B[k*N + j];
            }
            C[i*N + j] = sum;
        }
    }
}

} // namespace lin_alg
