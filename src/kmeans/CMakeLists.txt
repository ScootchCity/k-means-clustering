# K-means clustering executable

add_executable( kmeans
    main.cpp
    KMeans.cpp
)

target_include_directories( kmeans PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries( kmeans PRIVATE common )
