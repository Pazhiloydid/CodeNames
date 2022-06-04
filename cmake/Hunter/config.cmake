hunter_config(
    OpenSSL
    VERSION 1.0.2g
    CMAKE_ARGS
    CMAKE_C_FLAGS=-fPIC
    CMAKE_CXX_FLAGS=-fvisibility=hidden
)

hunter_config(
    Qt
    VERSION 5.11.3
)
