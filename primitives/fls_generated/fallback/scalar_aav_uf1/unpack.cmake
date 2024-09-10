add_library(fallback_scalar_aav_1024_uf1_unpack OBJECT
        fallback_scalar_aav_1024_uf1_unpack_src.cpp)
target_compile_definitions(fallback_scalar_aav_1024_uf1_unpack PRIVATE IS_SCALAR)

LIST(APPEND FLS_GENERATED_OBJECT_FILES
        $<TARGET_OBJECTS:fallback_scalar_aav_1024_uf1_unpack>)
get_target_property(TARGET_NAME fallback_scalar_aav_1024_uf1_unpack NAME)
get_target_property(TARGET_COMPILE_OPTIONS fallback_scalar_aav_1024_uf1_unpack COMPILE_OPTIONS)
#------------------------------------------------------------------------------------------------------
if (ENABLE_TESTING)
    add_executable(fallback_scalar_aav_1024_uf1_unpack_test fallback_scalar_aav_1024_uf1_unpack_test.cpp)
    target_link_libraries(fallback_scalar_aav_1024_uf1_unpack_test PRIVATE fallback_scalar_aav_1024_uf1_unpack)
    target_link_libraries(fallback_scalar_aav_1024_uf1_unpack_test PRIVATE fallback_scalar_aav_1024_uf1_pack fallback_scalar_aav_1024_uf1_ffor)
    target_link_libraries(fallback_scalar_aav_1024_uf1_unpack_test PRIVATE gtest_main)
    target_include_directories(fallback_scalar_aav_1024_uf1_unpack_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    gtest_discover_tests(fallback_scalar_aav_1024_uf1_unpack_test)
endif ()
#------------------------------------------------------------------------------------------------------
configure_file(${CMAKE_SOURCE_DIR}/fls_bench/fls_bench.hpp ${CMAKE_CURRENT_BINARY_DIR}/fallback_scalar_aav_1024_uf1_unpack_bench.hpp)
add_executable(fallback_scalar_aav_1024_uf1_unpack_bench fallback_scalar_aav_1024_uf1_unpack_bench.cpp)
target_link_libraries(fallback_scalar_aav_1024_uf1_unpack_bench PRIVATE fallback_scalar_aav_1024_uf1_unpack)
target_link_libraries(fallback_scalar_aav_1024_uf1_unpack_bench PRIVATE fallback_scalar_aav_1024_uf1_pack fallback_scalar_aav_1024_uf1_ffor)
target_include_directories(fallback_scalar_aav_1024_uf1_unpack_bench PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_fls_benchmark(fallback_scalar_aav_1024_uf1_unpack_bench)
