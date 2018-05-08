FROM	gcc
RUN	apt-get -qq update &&\
	apt-get install -y ocl-icd-opencl-dev
COPY	demo.c /usr/src/demo.c
RUN	gcc /usr/src/demo.c -o /usr/bin/demo -lOpenCL -O3 -Wall -Wextra
CMD	demo
