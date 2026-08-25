# Security and numerical boundaries

Sky Math Core is an engineering-beta local library. Matrix dimensions and vector lengths are bounded, indexes are checked, and non-finite values/results are rejected. CI runs warnings-as-errors plus AddressSanitizer and UndefinedBehaviorSanitizer tests.

The library does not process network data, files, credentials, or arbitrary code. Its primary risk surface is correctness and resource use rather than remote attack exposure.

This implementation is not validated for cryptography, financial calculations, safety-critical control, scientific certification, or adversarial numerical workloads. Floating-point arithmetic follows ordinary C++ `double` behavior and no conditioning/error-bound guarantees are claimed.
