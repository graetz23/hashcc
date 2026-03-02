cmake_minimum_required(VERSION 3.10)
project(hashcc CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

include_directories(source)

set(SOURCES
    source/hashcc/hashccErrException.cpp
    source/hashcc/hashccErrFailure.cpp
    source/hashcc/hashccErrError.cpp
    source/hashcc/hashccDmyNoob.cpp
    source/hashcc/hashccDmyObject.cpp
    source/hashcc/hashccStc.cpp
    source/hashcc/hashccFncNoob.cpp
    source/hashcc/hashccFncHash.cpp
    source/hashcc/hashccTypKeyTest.cpp
    source/hashcc/hashccTypKeyConv.cpp
    source/hashcc/hashccTypTree.cpp
    source/hashcc/hashccTypTreeLimb.cpp
    source/hashcc/hashccTypTreeLeaf.cpp
    source/hashcc/hashccTypTreeController.cpp
    source/hashcc/hashccObjHashMap.cpp
    source/hashcc/hashccObjHashMapDec.cpp
    source/hashcc/hashccObjHashMapDec10.cpp
    source/hashcc/hashccObjHashMapDec10Elf.cpp
    source/hashcc/hashccObjHashMapDec24.cpp
    source/hashcc/hashccObjHashMapDec24Fnv.cpp
    source/hashcc/hashccObjHashMapDec24Adler.cpp
    source/hashcc/hashccObjHashMapBuilder.cpp
    source/hashcc/hashccJnk.cpp
    source/main.cpp
)

add_executable(hashcc ${SOURCES})

set(TEST_SOURCES
    source/hashcc/hashccErrException.cpp
    source/hashcc/hashccErrFailure.cpp
    source/hashcc/hashccErrError.cpp
    source/hashcc/hashccDmyNoob.cpp
    source/hashcc/hashccDmyObject.cpp
    source/hashcc/hashccStc.cpp
    source/hashcc/hashccFncNoob.cpp
    source/hashcc/hashccFncHash.cpp
    source/hashcc/hashccTypKeyTest.cpp
    source/hashcc/hashccTypKeyConv.cpp
    source/hashcc/hashccTypTree.cpp
    source/hashcc/hashccTypTreeLimb.cpp
    source/hashcc/hashccTypTreeLeaf.cpp
    source/hashcc/hashccTypTreeController.cpp
    source/hashcc/hashccObjHashMap.cpp
    source/hashcc/hashccObjHashMapDec.cpp
    source/hashcc/hashccObjHashMapDec10.cpp
    source/hashcc/hashccObjHashMapDec10Elf.cpp
    source/hashcc/hashccObjHashMapDec24.cpp
    source/hashcc/hashccObjHashMapDec24Fnv.cpp
    source/hashcc/hashccObjHashMapDec24Adler.cpp
    source/hashcc/hashccObjHashMapBuilder.cpp
    source/hashcc/hashccJnk.cpp
    source/hashcc/hashccUnitTest.cpp
)

add_executable(hashcc-test ${TEST_SOURCES})
target_link_libraries(hashcc-test Catch2::Catch2WithMain)
