set(UNIT_TEST unittest)

set(TEST_SRC
  "${SRC_PATH}/servo_motor.cpp"
  "${TEST_SRC_PATH}/servo_motor_test.cpp"
)

include_directories(AFTER "${INCLUDE_PATH}" "${SRC_PATH}")
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${UNIT_TEST} ${TEST_SRC})

target_link_libraries(
    ${UNIT_TEST}
    gtest_main
    gmock
    )

add_test(
  NAME
    unit
  COMMAND
    ${UNIT_TEST}
  )

add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})
add_custom_command(
     TARGET ${UNIT_TEST}
     COMMENT "Run tests"
     POST_BUILD 
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
     COMMAND ${TEST_PATH}/${UNIT_TEST}
)