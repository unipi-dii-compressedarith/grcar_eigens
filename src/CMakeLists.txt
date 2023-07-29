find_package(Eigen3 3.3 REQUIRED NO_MODULE)
add_library(grcar_eigens eigens.cpp)
target_link_libraries(grcar_eigens PRIVATE Eigen3::Eigen)
target_compile_options(grcar_eigens PRIVATE -march=native -O3)
target_include_directories(grcar_eigens PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/../cppposit/include )

