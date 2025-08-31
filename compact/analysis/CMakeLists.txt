### Defines the cmake version
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

### Defines the name of the project with version
project(DualTestBeam VERSION 1.0)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

### Set the c++ -std flag to c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()
set(DD4HEP_ROOT /home/atlas/DD4hep/install)
### Find the source and header files
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cc")
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/include/*.h")
set(DICT_HEADERS ${HEADER_FILES})
set(DICT_LINKDEF ${PROJECT_SOURCE_DIR}/include/LinkDef.h)

message("SRC_FILES = ${SRC_FILES}")
message("HEADER_FILES = ${HEADER_FILES}")

### Find all the ROOT and GEANT4 packages
find_package(ROOT REQUIRED)
find_package(Geant4 REQUIRED)
find_package(DD4hep REQUIRED PATHS ${DD4HEP_ROOT}/cmake NO_DEFAULT_PATH)

### Create a shared library 
ROOT_GENERATE_DICTIONARY(ResolutionDict ${DICT_HEADERS} LINKDEF ${DICT_LINKDEF})
add_library(DualTestBeam_lib SHARED ${SRC_FILES} ${ResolutionDict})
#add_library(DD4hep::DD4hep STATIC IMPORTED)

### include sources for the library
target_sources(DualTestBeam_lib
	PRIVATE ${SRC_FILES}
	PUBLIC ${HEADER_FILES} ${DICT_HEADERS} ${DICT_LINKDEF}
)
#ROOT_GENERATE_DICTIONARY(ResolutionDict ${DICT_HEADERS} LINKDEF ${DICT_LINKDEF})
### add the header files into the target
target_include_directories(DualTestBeam_lib PUBLIC ${PROJECT_SOURCE_DIR}/include ${DD4HEP_ROOT}/include)

### link all the external and /include headers
target_link_libraries(DualTestBeam_lib PUBLIC ${ROOT_LIBRARIES} ${Geant4_LIBRARIES}
	${DD4HEP_ROOT}/lib/libDDCore.so
	${DD4HEP_ROOT}/lib/libDDG4.so
	
)
set_target_properties(DualTestBeam_lib PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib 
)

### install the library
install(TARGETS DualTestBeam_lib DESTINATION lib)


### add executable for running Resolution.C
add_executable(runResolution runResolution.cpp)
target_link_libraries(runResolution PRIVATE DualTestBeam_lib ${ROOT_LIBRARIES})
target_include_directories(runResolution PRIVATE include)
