# Data generator executable

add_executable( generate_data
    generate_data.cpp
    DataGenerator.cpp
)

target_include_directories( generate_data PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries( generate_data PRIVATE common )
