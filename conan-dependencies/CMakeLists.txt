
        cmake_minimum_required(VERSION 3.15)
        project(conan-setup)
        include("C:/Qt/Tools/QtCreator/share/qtcreator/package-manager/conan.cmake")
        conan_cmake_run(
          CONANFILE "C:/Users/Vladimir/Desktop/CodeNames/conanfile.txt"
          INSTALL_FOLDER "C:/Users/Vladimir/Desktop/CodeNames/conan-dependencies"
          GENERATORS cmake_paths json
          BUILD missing
          ENV CONAN_CMAKE_TOOLCHAIN_FILE="C:/Users/Vladimir/Desktop/CodeNames/conan-dependencies/toolchain.cmake"
        )