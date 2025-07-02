FROM ubuntu:oracular

WORKDIR /metacall-node-cpp-example

# Install Git
RUN apt-get update \
    && apt-get install -y --no-install-recommends git ca-certificates

# Clone MetaCall repository, build and install it
RUN git clone --branch v0.9.12 --depth 1 https://github.com/metacall/core.git \
	&& mkdir core/build && cd core/build \
	&& ../tools/metacall-environment.sh release base nodejs c backtrace \
	&& ../tools/metacall-configure.sh release nodejs c ports install \
	&& ../tools/metacall-build.sh release nodejs c ports install \
	&& cd ../.. \
	&& rm -rf core

# Copy the whole project
COPY . .

# Install the NodeJS dependencies
RUN npm install

# Build the C++ test library
RUN cd cpp \
    && cmake . \
    && cmake --build .

# Run the script
RUN node index.js
