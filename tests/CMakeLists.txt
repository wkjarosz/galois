include_directories(${GaloisPlusPlus_SOURCE_DIR}/include)

add_executable(galoistest main.cpp)
target_link_libraries(galoistest galois++)
set_target_properties(galoistest PROPERTIES CXX_STANDARD 11)

ADD_TEST(galoisfield galoistest)

