# Cpp example : --------------------------------------------------------------------------------------------------------
add_executable(cpp_example ${CMAKE_CURRENT_SOURCE_DIR}/cpp_example.cpp)
target_link_libraries(cpp_example PUBLIC fastlanes)
target_compile_options(cpp_example PRIVATE "-fsanitize=address")
target_link_options(cpp_example PRIVATE "-fsanitize=address")

# Check if the system is Windows
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Set the linker flag only for this specific target
    target_compile_options(cpp_example PRIVATE -fuse-ld=lld)
endif ()


# C Example : ----------------------------------------------------------------------------------------------------------
add_executable(c_api ${CMAKE_CURRENT_SOURCE_DIR}/c_api.c)
target_link_libraries(c_api PUBLIC fastlanes)

