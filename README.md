# CodeNames
How to start deploy Windows
* install conan from https://conan.io/center/
* create build directory
* copy conan profile "msvc" from \\${this repo}$\\conan_profiles to C:\\Users\\${Your user name}$\\.conan\\profiles
* install cmake, python if it's nessesary
* open cmd and move to \\${this repo}\$\\build
* run conan install .. --profile=msvc --build=missing
