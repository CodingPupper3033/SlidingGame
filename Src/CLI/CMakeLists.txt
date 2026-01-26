add_executable( SlidingGameCLI
        main.cpp
        CliRenderer.cpp
)

target_link_libraries( SlidingGameCLI PRIVATE SlidingGameCore )