FROM ubuntu:24.04 AS builder
WORKDIR /work
RUN apt update && \
    apt install -y clang-17 git cmake ninja-build \
    curl zip unzip tar build-essential pkg-config
    
COPY vcpkg.json vcpkg.json
COPY Makefile Makefile

RUN make vcpkg
COPY . .

ENV CXX clang++-17
ENV CC clang-17

RUN mkdir build && \ 
    cd build && \
    cmake -DCMAKE_TOOLCHAIN_FILE=/work/lib/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DUSE_GTEST=ON \
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DSTATIC=ON \
    -DCMAKE_C_COMPILER=${CC} \
    -DCMAKE_CXX_COMPILER=${CXX} \
    -G Ninja .. && \
    ninja

RUN rm -rf /var/lib/apt/lists/*

WORKDIR /work/build
CMD ["ctest", "-c", "Release"]
