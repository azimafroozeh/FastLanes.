add_library(fallback_scalar_aav_1024_uf1_ffor OBJECT
        fallback_scalar_aav_1024_uf1_ffor_src.cpp)
target_compile_definitions(fallback_scalar_aav_1024_uf1_ffor PRIVATE IS_SCALAR)

LIST(APPEND FLS_GENERATED_OBJECT_FILES
        $<TARGET_OBJECTS:fallback_scalar_aav_1024_uf1_ffor>)
get_target_property(TARGET_NAME fallback_scalar_aav_1024_uf1_ffor NAME)
get_target_property(TARGET_COMPILE_OPTIONS fallback_scalar_aav_1024_uf1_ffor COMPILE_OPTIONS)
