conan remote add bincrafters https://bincrafters.jfrog.io/artifactory/api/conan/public-conan
conan remote add conancenter https://center.conan.io
conan config set general.revisions_enabled=1
mkdir build
cd build
conan install .. --build missing -s cppstd=gnu20
cmake .. -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
make