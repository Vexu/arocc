FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

env NO_ARCH_OPT 1

RUN apt-get update && \
    apt-get -y install --no-install-suggests --no-install-recommends \
    automake \
    ninja-build \
    bison flex \
    build-essential \
    git \
    python3 python3-dev python3-setuptools python-is-python3 \
    libtool libtool-bin \
    libglib2.0-dev \
    wget jupp nano bash-completion less \
    apt-utils apt-transport-https ca-certificates gnupg dialog \
    libpixman-1-dev \
    gnuplot-nox \
    && rm -rf /var/lib/apt/lists/*

RUN echo "deb http://apt.llvm.org/focal/ llvm-toolchain-focal-13 main" >> /etc/apt/sources.list && \
    wget -qO - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -

RUN echo "deb http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu focal main" >> /etc/apt/sources.list && \
    apt-key adv --recv-keys --keyserver keyserver.ubuntu.com 1E9377A2BA9EF27F

RUN apt-get update && apt-get full-upgrade -y && \
    apt-get -y install --no-install-suggests --no-install-recommends \
    gcc-10 g++-10 gcc-10-plugin-dev gcc-10-multilib gcc-multilib gdb lcov \
    clang-13 clang-tools-13 libc++1-13 libc++-13-dev \
    libc++abi1-13 libc++abi-13-dev libclang1-13 libclang-13-dev \
    libclang-common-13-dev libclang-cpp13 libclang-cpp13-dev liblld-13 \
    liblld-13-dev liblldb-13 liblldb-13-dev libllvm13 libomp-13-dev \
    libomp5-13 lld-13 lldb-13 llvm-13 llvm-13-dev llvm-13-runtime llvm-13-tools \
    && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 0
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 0

ENV LLVM_CONFIG=llvm-config-13
ENV AFL_SKIP_CPUFREQ=1
ENV AFL_TRY_AFFINITY=1
ENV AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1

RUN git clone --depth=1 https://github.com/vanhauser-thc/afl-cov /afl-cov
RUN cd /afl-cov && make install && cd ..

RUN git clone https://github.com/AFLplusplus/AFLplusplus.git

WORKDIR /AFLplusplus

RUN export CC=gcc-10 && export CXX=g++-10 && make clean && \
    make distrib && make install && make clean

WORKDIR /

RUN wget https://ziglang.org/builds/zig-linux-x86_64-0.9.0-dev.1625+d3a099c14.tar.xz && \
    echo 9f71f95abbef1cf4be8656c80401a4d35781c19a07b4383fc2a18cc5822ea0ea zig-linux-x86_64-0.9.0-dev.1625+d3a099c14.tar.xz | sha256sum --check --strict && \
    tar -xvf zig-linux-x86_64-0.9.0-dev.1625+d3a099c14.tar.xz && \
    rm zig-linux-x86_64-0.9.0-dev.1625+d3a099c14.tar.xz

ENV PATH="/zig-linux-x86_64-0.9.0-dev.1625+d3a099c14:$PATH"
