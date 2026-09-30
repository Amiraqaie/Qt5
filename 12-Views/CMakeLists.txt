cmake_minimum_required(VERSION 3.19)
project(12-Views LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(12-Views
    main.cpp
)

target_link_libraries(12-Views
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS 12-Views
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
