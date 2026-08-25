FROM gcc:14 AS build
WORKDIR /src
COPY include ./include
COPY src ./src
RUN g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2 -Iinclude src/sky_math.cpp src/main.cpp -o /sky-math-demo

FROM debian:bookworm-slim
RUN apt-get update \
    && apt-get install -y --no-install-recommends libstdc++6 \
    && rm -rf /var/lib/apt/lists/* \
    && useradd --system --uid 10001 --no-create-home app
COPY --from=build /sky-math-demo /usr/local/bin/sky-math-demo
USER 10001:10001
ENTRYPOINT ["/usr/local/bin/sky-math-demo"]
