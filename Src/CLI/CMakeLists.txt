add_executable( SlidingGameCLI
        main.cpp
        CliRenderer.cpp
)

target_compile_features( SlidingGameCLI PRIVATE cxx_std_23 )

target_link_libraries( SlidingGameCLI PRIVATE SlidingGameCore SlidingGameUtils )