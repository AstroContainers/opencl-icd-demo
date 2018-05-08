FROM	gcc
RUN	apt-get -qq update &&\
	apt-get install -y ocl-icd-opencl-dev
COPY	ocl-test.c /usr/src/ocl-test.c
RUN	gcc /usr/src/ocl-test.c -o /usr/bin/ocl-test -lOpenCL -O3 -Wall -Wextra
