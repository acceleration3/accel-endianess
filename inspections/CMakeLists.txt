project(inspect)

include (TestBigEndian)

TEST_BIG_ENDIAN(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
    message(STATUS "Platform is big endian.")
    list(APPEND ADDITIONAL_DEFINITIONS -DPLATFORM_BIG_ENDIAN)
else()
    message(STATUS "Platform is little endian.")
    list(APPEND ADDITIONAL_DEFINITIONS -DPLATFORM_LITTLE_ENDIAN)
endif()

set(ADDITIONAL_DEFINITIONS ${ADDITIONAL_DEFINITIONS} PARENT_SCOPE)