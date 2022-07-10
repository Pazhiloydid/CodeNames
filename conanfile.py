from conans import ConanFile, CMake


class HelloWorld(ConanFile):
    name = "HelloWorld"
    license = "BSD"
    author = "your name"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package_multi", "cmake_paths"

    def build_requirements(self):
         self.build_requires("gtest/1.8.1")

    def requirements(self):
         self.requires("qt/5.15.2")
         self.requires("boost/1.79.0")