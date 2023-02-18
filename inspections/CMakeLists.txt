project(inspect)

file(GLOB INSPECT_FILES "*.c")
foreach(FILE ${INSPECT_FILES})
    get_filename_component(INSPECT_NAME ${FILE} NAME_WE)
    message("Inspection found: ${INSPECT_NAME}, File: ${FILE}")
    try_run(
        ${INSPECT_NAME}_RUN_RESULT
        ${INSPECT_NAME}_COMPILE_RESULT
        ${CMAKE_CURRENT_BINARY_DIR}/
        ${FILE}
    )
endforeach()

if (endianness_RUN_RESULT)
    message(STATUS "Platform is little endian.")
    list(APPEND ADDITIONAL_DEFINITIONS -DPLATFORM_LITTLE_ENDIAN)
else()
    message(STATUS "Platform is big endian.")
    list(APPEND ADDITIONAL_DEFINITIONS -DPLATFORM_BIG_ENDIAN)
endif()

set(ADDITIONAL_DEFINITIONS ${ADDITIONAL_DEFINITIONS} PARENT_SCOPE)