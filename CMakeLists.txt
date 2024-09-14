cmake_minimum_required(VERSION 3.28)
project(pomodoro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBNOTIFY REQUIRED libnotify)
include_directories(${LIBNOTIFY_INCLUDE_DIRS})

add_executable(pomodoro main.cpp
        pomodoro.cpp
        main_window.cpp)
target_link_libraries(pomodoro
        Qt::Core
        Qt::Gui
        Qt::Widgets
        ${LIBNOTIFY_LIBRARIES}
)
add_definitions(${LIBNOTIFY_CFLAGS_OTHER})