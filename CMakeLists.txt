cmake_minimum_required(VERSION 3.16)
project(MessManagementSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

  find_package(Qt6 COMPONENTS Core Gui Widgets PrintSupport REQUIRED)

# Add source files
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/student.cpp
    src/menu.cpp
    src/meal.cpp
    src/user.cpp           # <--- Add this if missing
    src/menusuggestion.cpp # <--- Add this if missing
    src/welcomewindow.cpp
    src/logindialog.cpp
)
# Add header files
set(HEADERS
    include/mainwindow.h
    include/student.h
    include/menu.h
    include/meal.h
    include/menusuggestion.h
    include/user.h
    include/welcomewindow.h
    include/logindialog.h
)

# Add UI files
  set(UI_FILES
      src/mainwindow.ui
      src/login.ui
      src/register.ui
      ui/welcomewindow.ui
      ui/logindialog.ui
  )

message(STATUS "UI FILES: ${UI_FILES}")
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_SOURCE_DIR}/ui")
set(UI_FILES
    ui/mainwindow.ui
    ui/login.ui
    ui/register.ui
    ui/welcomewindow.ui
    ui/logindialog.ui
)
# Create executable
qt_add_resources(RESOURCES resources/resources.qrc)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCES}
)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::PrintSupport
) 