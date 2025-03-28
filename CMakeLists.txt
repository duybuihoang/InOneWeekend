cmake_minimum_required(VERSION 3.10.0)
project(inOneWeekend VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source file
set(SOURCES
    inOneWeekend.cpp
    src/vec3.cpp 
    src/color.cpp
    src/ray.cpp
    src/sphere.cpp
    src/hitRecord.cpp
    src/hittableList.cpp
    src/interval.cpp
    src/camera.cpp
    src/lambertian.cpp
    src/metal.cpp
    src/dielectric.cpp
)
# Header files      
set(HEADERS
    lib/vec3.h
    lib/color.h
    lib/ray.h
    lib/hittable.h
    lib/sphere.h
    lib/hitRecord.h
    lib/utils.h
    lib/hittableList.h
    lib/interval.h
    lib/camera.h
    lib/material.h
    lib/lambertian.h
    lib/metal.h
    lib/dielectric.h
)


# Add the library
add_library(inOneWeekend_lib ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(inOneWeekend_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Add the executable
add_executable(inOneWeekend inOneWeekend.cpp)

# Link the library to the executable
target_link_libraries(inOneWeekend inOneWeekend_lib)

