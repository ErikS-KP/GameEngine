cmake_minimum_required(VERSION 3.10)
project(GameEngine VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Define paths to your local SDL2 folders
set(SDL2_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SDL2")

# 2. Include Directories (Where the .h files are)
include_directories(${SDL2_PATH}/include)

# 3. Library Directories (Where the .lib or .a files are)
link_directories(${SDL2_PATH}/lib)

# 4. Add your executable
add_executable(${PROJECT_NAME} src/core/main.cpp)

# 5. Link the libraries
# Note: On Windows, you usually need SDL2main and SDL2.
# On Linux/Mac, it's usually just SDL2 and SDL2_image.
target_link_libraries(${PROJECT_NAME}
        SDL2
        SDL2main
        SDL2_image
)

# 6. Copy DLLs to the build folder (Windows specific)
# This ensures the game actually runs when you hit "start"
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_PATH}/bin/SDL2.dll"
            "${SDL2_PATH}/bin/SDL2_image.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()