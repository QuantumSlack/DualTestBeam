### Defines the cmake version
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

### Defines the name of the project with version
project(DualTestBeam VERSION 1.0)

### Set the c++ -std flag to c++20
set(CMAKE_CXX_STANDARD 17)

### Find the source and header files

file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cc")
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/include/*.h")

### Find all the ROOT and GEANT4 packages
find_package(ROOT REQUIRED)
find_package(Geant4 REQUIRED)

### Create a shared library 
add_library(DualTestBeam_lib SHARED)

### include sources for the library
target_sources(DualTestBeam_lib
	PRIVATE ${SRC_FILES}
	PUBLIC ${HEADER_FILES}
)

### add the header files into the target
target_include_directories(DualTestBeam_lib PUBLIC ${HEADER_FILES})

### link all the external and /include headers
target_link_libraries(DualTestBeam_lib PUBLIC ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})

### set target locations
set_target_properties(DualTestBeam_lib PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
)

### install the library
install(TARGETS DualTestBeam_lib DESTINATION lib)

