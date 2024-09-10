add_library(fallback_scalar_aav_1024_uf1_untranspose OBJECT
        fallback_scalar_aav_1024_uf1_untranspose_src.cpp)
target_compile_definitions(fallback_scalar_aav_1024_uf1_untranspose PRIVATE IS_SCALAR)

LIST(APPEND FLS_GENERATED_OBJECT_FILES
        $<TARGET_OBJECTS:fallback_scalar_aav_1024_uf1_untranspose>)
get_target_property(TARGET_NAME fallback_scalar_aav_1024_uf1_untranspose NAME)
get_target_property(TARGET_COMPILE_OPTIONS fallback_scalar_aav_1024_uf1_untranspose COMPILE_OPTIONS)
#------------------------------------------------------------------------------------------------------
if (ENABLE_TESTING)
    add_executable(fallback_scalar_aav_1024_uf1_untranspose_test fallback_scalar_aav_1024_uf1_untranspose_test.cpp)
    target_link_libraries(fallback_scalar_aav_1024_uf1_untranspose_test PRIVATE fallback_scalar_aav_1024_uf1_untranspose)
    target_link_libraries(fallback_scalar_aav_1024_uf1_untranspose_test PRIVATE fallback_scalar_aav_1024_uf1_unrsum fallback_scalar_aav_1024_uf1_untranspose)
    target_link_libraries(fallback_scalar_aav_1024_uf1_untranspose_test PRIVATE gtest_main)
    target_include_directories(fallback_scalar_aav_1024_uf1_untranspose_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    gtest_discover_tests(fallback_scalar_aav_1024_uf1_untranspose_test)
endif ()
#------------------------------------------------------------------------------------------------------
configure_file(${CMAKE_SOURCE_DIR}/fls_bench/fls_bench.hpp ${CMAKE_CURRENT_BINARY_DIR}/fallback_scalar_aav_1024_uf1_untranspose_bench.hpp)
add_executable(fallback_scalar_aav_1024_uf1_untranspose_bench fallback_scalar_aav_1024_uf1_untranspose_bench.cpp)
target_link_libraries(fallback_scalar_aav_1024_uf1_untranspose_bench PRIVATE fallback_scalar_aav_1024_uf1_untranspose)
target_link_libraries(fallback_scalar_aav_1024_uf1_untranspose_bench PRIVATE fallback_scalar_aav_1024_uf1_unrsum fallback_scalar_aav_1024_uf1_untranspose)
target_include_directories(fallback_scalar_aav_1024_uf1_untranspose_bench PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_fls_benchmark(fallback_scalar_aav_1024_uf1_untranspose_bench)
