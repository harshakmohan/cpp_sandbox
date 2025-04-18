#pragma once
#include <vector>
#include <cstddef>

namespace lin_alg {

// Naive dense N×N matrix multiply:
//   C = A * B
// A, B, and C are row‑major flattened length N*N.
void mat_mul(const std::vector<double>& A,
             const std::vector<double>& B,
             std::vector<double>& C,
             std::size_t N);

} // namespace lin_alg
