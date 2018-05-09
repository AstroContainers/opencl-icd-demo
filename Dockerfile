FROM	gcc AS builder
RUN	apt-get -qq update &&\
	apt-get install -y ocl-icd-opencl-dev
COPY	demo.c /usr/src/demo.c
RUN	gcc /usr/src/demo.c -o /usr/bin/demo -lOpenCL -O3 -Wall -Wextra

FROM	debian:stretch-slim
RUN	apt-get -qq update &&\
	apt-get install -y --no-install-recommends \
		libbsd0 libdrm-dev libxext6 libxfixes3 \
		ocl-icd-libopencl1 &&\
	apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
COPY	--from=builder /usr/bin/demo /usr/bin/demo
CMD	demo
