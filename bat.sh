set -x
set -u
set -e
cd build
cmake ..
make
./interp2d/interp2d_spec
