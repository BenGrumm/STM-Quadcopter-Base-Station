# Fetch ubuntu image
FROM ubuntu:22.04

# Install build tools
RUN apt update && \
    apt install -y wget build-essential
    
# Copy project into image
RUN mkdir /project && mkdir /project/build
COPY Src /project/Src
COPY test /project/test
COPY Inc /project/Inc
COPY Makefile /project/Makefile

# Download Unity
RUN mkdir /project/tools/ && \
    cd /project/ && \
    wget https://github.com/ThrowTheSwitch/Unity/archive/refs/tags/v2.5.2.tar.gz && \
    tar xf v2.5.2.tar.gz && \
    rm v2.5.2.tar.gz && \
    mv Unity-2.5.2/ tools/Unity/
    
# Execute script
ENTRYPOINT ["make", "test", "-C", "/project/"]