This is a potential solution to make a single OpenCL Docker image run
on different hosts with different accelerators.

The simple C code "src/demo.c" is linked against a generic OpenCL
Installable Client Driver (ICD) Loader.  When the Docker container is
run "as is", no OpenCL platform is available and the demo will print

    $ docker run astrocontainers/opencl-icd-demo
    Failed to obtain platform IDs

Nevertheless, when the host OpenCL platform is passed to the container
by using the `bin/opencl-icd-flags` script, the ICD loader can
dynamically load the platform.  If the "beignet-opencl-icd" is
installed,

    sudo apt install beignet-opencl-icd

then the demo will print

    $ docker run $(bin/opencl-icd-flags) astrocontainers/opencl-icd-demo
    1 platform is found:
    	* Intel Gen OCL Driver by Intel: OpenCL 2.0 beignet 1.3


Known Issues
------------

- The demo code can only find OpenCL library if the library is
  described by an absolute path in "/etc/OpenCL/vendors/*.icd"

- The demo code only prints the platform name.  We should add a
  minimal computation example to make sure that the OpenCL JIT
  compiler works correctly.
