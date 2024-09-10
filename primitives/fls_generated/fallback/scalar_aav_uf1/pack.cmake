add_library(fallback_scalar_aav_1024_uf1_pack OBJECT
        fallback_scalar_aav_1024_uf1_pack_src.cpp)
target_compile_definitions(fallback_scalar_aav_1024_uf1_pack PRIVATE IS_SCALAR)

LIST(APPEND FLS_GENERATED_OBJECT_FILES
        $<TARGET_OBJECTS:fallback_scalar_aav_1024_uf1_pack>)
get_target_property(TARGET_NAME fallback_scalar_aav_1024_uf1_pack NAME)
get_target_property(TARGET_COMPILE_OPTIONS fallback_scalar_aav_1024_uf1_pack COMPILE_OPTIONS)
