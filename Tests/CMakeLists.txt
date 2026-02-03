# ------------
# Dependencies
# ------------
include(FetchContent)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(catch2)


# ---------------
# Project modules
# ---------------
add_subdirectory(Core)

# All tests
set(ALL_TESTS_SOURCES
        ${CORE_TESTS_SOURCES}
)

add_executable(AllTests
        ${ALL_TESTS_SOURCES}
)

target_link_libraries(AllTests
        PRIVATE SlidingGameCore Catch2::Catch2WithMain
)

target_compile_features(AllTests PUBLIC cxx_std_23)

include(CTest)
include(Catch)
catch_discover_tests(AllTests)