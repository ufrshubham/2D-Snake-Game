cmake_minimum_required(VERSION 3.0.0)
project(2D-Snake-Game VERSION 0.1.0)

# As std::auto_ptr was removed in C++17, sfml-audio fails to compile
# with following CXX standards. So instead of setting a global standard
# this template sets CXX_STANDARD to 17 using set_property.
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Copy all the required SFML libs and main executable to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)

# Build SFML
add_subdirectory(vendors/sfml/)

# Collect all the source and header files
file(GLOB ALL_SOURCE_FILES src/*.cpp)
file(GLOB ALL_HEADER_FILES include/*.hpp)

# Add the main target.
add_executable(${PROJECT_NAME} ${ALL_SOURCE_FILES} ${ALL_HEADER_FILES})

# Use C++17 standards
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Include directories for main target
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include/
    PRIVATE ${PROJECT_SOURCE_DIR}/vendors/sfml/include/
)

# Link required libraries (add sfml-audio and sfml-network if needed)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
