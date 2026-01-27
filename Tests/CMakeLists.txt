file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/CLI/*.cpp"
)

add_executable(SlidingGameTests ${TEST_SOURCES})

target_link_libraries(SlidingGameTests
        PRIVATE SlidingGameCore Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(SlidingGameTests)
