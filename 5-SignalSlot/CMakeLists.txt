cmake_minimum_required(VERSION 3.16)

project(5-SignalSlot LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(5-SignalSlot
  main.cpp
  source.h source.cpp
  destination.h destination.cpp
  radio.h radio.cpp
  station.h station.cpp
  test.h test.cpp
  watcher.h watcher.cpp
  owner.h owner.cpp
  dog.h dog.cpp
)
target_link_libraries(5-SignalSlot PRIVATE Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS 5-SignalSlot
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
