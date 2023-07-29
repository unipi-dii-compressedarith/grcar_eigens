add_executable(test_grcar_eigens test_grcar_eigens.cpp)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

target_link_libraries(test_grcar_eigens PRIVATE grcar_eigens Eigen3::Eigen)
target_compile_options(test_grcar_eigens PRIVATE -march=native -O3)
target_include_directories(test_grcar_eigens PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/../cppposit/include)

