cmake_minimum_required(VERSION 3.3)
project(BS)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")
message(STATUS "Runtime: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

set(PLATFORM_LIBS )
if(WIN32)
else()
endif()

set (CMAKE_CXX_STANDARD 11)
find_package(JNI)
include_directories(${JNI_INCLUDE_DIRS})

include_directories(
${PROJECT_SOURCE_DIR}/../3rdParty/boost/
${PROJECT_SOURCE_DIR}/include
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
	#JNI
	src/jni_bool.cpp
	src/jni_float.cpp
	src/jni_int.cpp
	src/jni_wrapper.cpp
)

add_library(BS SHARED ${SOURCE_FILES})
target_link_libraries(BS
        ${JNI_LIBRARIES}
		${PLATFORM_LIBS})
