cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME "TestCraft")
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

if(WIN32)
    set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows" CACHE STRING "")
elseif(UNIX)
    set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux" CACHE STRING "")
endif()

if(MSVC)
    add_compile_options(/utf-8)
endif()

find_package(Boost CONFIG REQUIRED COMPONENTS beast asio filesystem system thread date_time smart_ptr optional variant algorithm)
find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)
find_package(hiredis CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(OpenSSL REQUIRED)
# Add all the other packages you need here

if(WIN32)
    set(lightlib_DIR "${CMAKE_SOURCE_DIR}/libs/lightlib/x64-windows")
elseif(UNIX)
    set(lightlib_DIR "${CMAKE_SOURCE_DIR}/libs/lightlib/x64-linux")
endif()

add_library(lightlib SHARED IMPORTED)

if(WIN32)
    set_target_properties(lightlib PROPERTIES
        IMPORTED_IMPLIB "${lightlib_DIR}/lib/lightlib_shared.lib"
        IMPORTED_LOCATION "${lightlib_DIR}/bin/lightlib_shared.dll"
        INTERFACE_INCLUDE_DIRECTORIES "${lightlib_DIR}/include"
    )
elseif(UNIX)
    set_target_properties(lightlib PROPERTIES
        IMPORTED_IMPLIB "${lightlib_DIR}/lib/liblightlib.a"
        IMPORTED_LOCATION "${lightlib_DIR}/bin/liblightlib.dylib"
        INTERFACE_INCLUDE_DIRECTORIES "${lightlib_DIR}/include"
    )
endif()

target_include_directories(lightlib INTERFACE
    "${lightlib_DIR}"
    "${lightlib_DIR}/include"
)

target_link_libraries(lightlib INTERFACE
    Boost::beast  
    Boost::asio
    Boost::filesystem
    Boost::system
    Boost::thread
    Boost::date_time
    Boost::smart_ptr
    Boost::optional
    Boost::variant
    Boost::algorithm
    fmt::fmt
    nlohmann_json::nlohmann_json
    jwt-cpp::jwt-cpp
    hiredis::hiredis
    ZLIB::ZLIB
    PostgreSQL::PostgreSQL
    OpenSSL::SSL
    OpenSSL::Crypto

    # Add all the other packages you need here
)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE lightlib)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

if(WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include)
endif()

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    
        COMMAND ${CMAKE_COMMAND} -E copy
            "${lightlib_DIR}/bin/lightlib_shared.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>

        COMMENT "Copying lightlib.dll to output directory"
    )
elseif(UNIX)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${lightlib_DIR}/bin/liblightlib.dylib"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>

        COMMENT "Copying liblightlib.dylib to output directory"
    )
endif()