cmake_minimum_required(VERSION 3.9)
project (image)


add_library (image_drawing Project_imageDrawing.cpp)
#add_executable(image_drawing source.cpp Project.cpp Project_imageDrawing.cpp)

target_link_libraries(image_drawing dependencies)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/dependencies/include)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(image_drawing ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

