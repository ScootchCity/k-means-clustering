# Common library used by both executables

add_library( common STATIC
    Point.cpp
    Cluster.cpp
    CSVReader.cpp
    CSVWriter.cpp
)

target_include_directories( common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
