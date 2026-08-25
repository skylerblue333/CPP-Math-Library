FROM debian:bookworm-slim AS build
RUN apt-get update \
    && apt-get install -y --no-install-recommends g++ \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /src
COPY include ./include
COPY src ./src
RUN g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2 -static -Iinclude src/sky_math.cpp src/main.cpp -o /sky-math-demo

FROM scratch
COPY --from=build /sky-math-demo /sky-math-demo
USER 10001:10001
ENTRYPOINT ["/sky-math-demo"]
