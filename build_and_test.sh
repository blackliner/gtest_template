set -e

mkdir -p build
cd build
cmake ..
make
cd my_project
./my_project_spec
