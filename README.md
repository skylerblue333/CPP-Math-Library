# Sky Math Core

**Status: engineering beta.** A small reusable C++17 linear-algebra core with bounded matrix/vector dimensions and deterministic tests.

## Implemented

- `sky::math::Matrix` with 1–256 row/column bounds.
- Bounds-checked element access.
- Matrix multiplication with dimension validation.
- 2x2 determinant calculation.
- Dot products for equal-length vectors up to 256 elements.
- Rejection of non-finite inputs/results.
- Static-library CMake target plus a small demo executable.
- Release tests, ASan/UBSan tests, and non-root container verification.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure
```

Public header: `include/sky_math.hpp`.

## Scope limitations

This is a compact educational/engineering math core, not Eigen/BLAS/LAPACK replacement software. It does **not** provide SIMD tuning, sparse matrices, decompositions, arbitrary determinants/inverses, GPU acceleration, numerical-condition analysis, benchmarking claims, or production scientific-computing certification.

## SKYCOIN4444 integration

Use the library only for small bounded matrix/vector operations whose numerical requirements fit the implemented contracts. Advanced analytics, scientific-computing validation, and performance-sensitive workloads should use separately evaluated numerical libraries.
