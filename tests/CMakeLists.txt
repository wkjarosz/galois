include_directories(${GaloisPlusPlus_SOURCE_DIR}/include)

add_executable(galoistest main.cpp)
target_link_libraries(galoistest galois++)

ADD_TEST(galoisfield galoistest)

