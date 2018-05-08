FROM	gcc
RUN	apt-get -qq update &&\
	apt-get install -y ocl-icd-opencl-dev
COPY	opencl.c /usr/src/opencl.c
RUN	gcc /usr/src/opencl.c -o /usr/bin/opencl -lOpenCL -O3 -Wall -Wextra
