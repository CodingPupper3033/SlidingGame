# Qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(
        SlidingGameGUI
        main.cpp
        MainWindow.cpp
        ${PROJECT_SOURCE_DIR}/Inc/SlidingGame/GUI/MainWindow.h
        MainWindow.ui
)

target_link_libraries(SlidingGameGUI PRIVATE Qt6::Widgets SlidingGameCore SlidingGameUtils)