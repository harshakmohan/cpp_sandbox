# Dockerfile
FROM ubuntu:22.04

RUN apt-get update \
 && apt-get install -y \
    build-essential \
    cmake \
    g++-12 \
    ccache \
    git \
    libeigen3-dev \
    libglm-dev \
    libglfw3-dev \
 && rm -rf /var/lib/apt/lists/*


WORKDIR /app
COPY . .

# configure & build
RUN mkdir -p build && cd build && \
    cmake .. && cmake --build .

# execute default command to run playground
CMD ["./build/playground"]
