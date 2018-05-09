run:
	docker run `bin/opencl-icd-flags` astrocontainers/opencl-icd-demo

build:
	docker build -t astrocontainers/opencl-icd-demo .

push: build
	docker push astrocontainers/opencl-icd-demo
