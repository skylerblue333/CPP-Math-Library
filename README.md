# Sky Math

A small validated C++20 linear-algebra primitive for reusable local computation in the SKYCOIN4444 engineering portfolio.

## Implemented

- Header-only `sky::math::Matrix` interface with contiguous storage.
- Positive matrix-dimension validation and overflow-safe allocation sizing.
- Bounds-checked matrix access.
- Dimension-checked matrix multiplication.
- 2×2 determinant calculation with explicit shape validation.
- Equal-length, finite-value dot products.
- Detection of non-finite arithmetic results.
- CMake interface-library target and executable demonstration.
- Tests wired against the real library rather than a duplicate implementation.
- Release warnings-as-errors, CTest, ASan/UBSan verification, non-root container packaging, and smoke execution in CI.

## Use

```cpp
#include "sky/math.hpp"

sky::math::Matrix matrix(2, 2);
matrix.at(0, 0) = 1.0;
```

## Product boundary

Status: **engineering beta**.

Sky Math is intentionally small. It does not claim BLAS/LAPACK/Eigen/Armadillo parity, SIMD acceleration, sparse matrices, arbitrary-size determinants, decompositions, GPU execution, automatic differentiation, 3D graphics specialization, numerical-condition guarantees, or benchmarked production performance.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

## License

See `LICENSE`.
