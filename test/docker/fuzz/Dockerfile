FROM alpine:latest as build

WORKDIR /usr/src/minisign

RUN apk add --no-cache build-base cmake curl pkgconfig
RUN apk add --no-cache upx ||:
RUN curl https://download.libsodium.org/libsodium/releases/LATEST.tar.gz | tar xzvf - && cd libsodium-stable && env CFLAGS="-Os" CPPFLAGS="-DED25519_NONDETERMINISTIC=1" ./configure --disable-dependency-tracking && make -j$(nproc) check && make install && cd .. && rm -fr libsodium-stable

COPY ./ ./
RUN wget https://github.com/jedisct1/minisign/releases/download/0.11/minisign-0.11.tar.gz
RUN tar -xf minisign-0.11.tar.gz
RUN mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=MinSizeRel -DBUILD_STATIC_EXECUTABLES=1 .. && make -j$(nproc)
RUN upx --lzma build/minisign ||:

FROM aflplusplus/aflplusplus
COPY --from=build /usr/src/minisign/build/minisign /usr/local/bin/

ARG USER_ID
ARG GROUP_ID
ARG ZIG_VERSION
ARG ZIG_PUBKEY

RUN if [ ${USER_ID:-0} -ne 0 ] && [ ${GROUP_ID:-0} -ne 0 ]; then \
    userdel -f www-data &&\
    if getent group www-data ; then groupdel www-data; fi &&\
    groupadd -g ${GROUP_ID} www-data &&\
    useradd -l -u ${USER_ID} -g www-data www-data && \
    install -d -m 0755 -o www-data -g www-data /home/www-data &&\
    chown --changes --silent --no-dereference --recursive \
          --from=33:33 ${USER_ID}:${GROUP_ID} \
        /home/www-data \
;fi

WORKDIR /usr/local/bin

RUN wget --inet4-only https://ziglang.org/builds/$ZIG_VERSION.tar.xz && \
    wget --inet4-only "https://ziglang.org/builds/$ZIG_VERSION.tar.xz.minisig" && \
    minisign -Vm $ZIG_VERSION.tar.xz -P $ZIG_PUBKEY && \
    tar -xvf $ZIG_VERSION.tar.xz && \
    rm $ZIG_VERSION.tar.xz $ZIG_VERSION.tar.xz.minisig

USER www-data
WORKDIR /home/www-data


ENV PATH="$PATH:/usr/local/bin/$ZIG_VERSION"
