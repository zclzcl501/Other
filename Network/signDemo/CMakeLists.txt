cmake_minimum_required(VERSION 3.17)
project(HMAC_SHA256)

set(SSL_H_DIR /usr/local/opt/openssl/include)
set(SSL_L_DIR /usr/local/opt/openssl/lib)

set(CMAKE_CXX_STANDARD 14)

include_directories(${SSL_H_DIR})
link_directories(${SSL_L_DIR})
link_libraries(openssl)

add_executable(HMAC_SHA256 main.cpp algo_hmac.h algo_hmac.cpp)

target_link_libraries(HMAC_SHA256 openssl)