conan remote add bincrafters https://bincrafters.jfrog.io/artifactory/api/conan/public-conan
conan remote add conancenter https://center.conan.io/?verifySsl=false
conan config set general.revisions_enabled=1
mkdir build
cd build
conan install .. --build missing
cmake ..
make
sqlite3 bin/babel.db < ../babel_schema.sql