cmake_minimum_required(VERSION 3.14)
project(GettingStarted)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/LawnMower.cpp
        )

add_executable(mowerUserA src/mowerUserA.cpp ${SOURCE_FILES})
add_executable(mowerUserB src/mowerUserB.cpp ${SOURCE_FILES})
add_executable(pointDemo src/passByValueOrReference.cpp ${SOURCE_FILES})
add_executable(missingCopyConstructor src/missingCopyConstructor.cpp ${SOURCE_FILES})
add_executable(expectedCopyBehavior src/expectedCopyBehavior.cpp ${SOURCE_FILES})
add_executable(sampleTemplateUsage src/sampleTemplateUsage.cpp ${SOURCE_FILES})