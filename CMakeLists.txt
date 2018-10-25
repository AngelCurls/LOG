cmake_minimum_required(VERSION 3.12)
project(LOG)

set(CMAKE_CXX_STANDARD 17)

add_executable(LOG main.cpp ADTStructures/Graph.cpp ADTStructures/Graph.h ADTStructures/LinkedList.cpp ADTStructures/LinkedList.h ADTStructures/NodeGraph.cpp ADTStructures/NodeGraph.h ADTStructures/NodeLinkedList.cpp ADTStructures/NodeLinkedList.h Algorithms/AStar.cpp Algorithms/AStar.h Enemy/Enemy.cpp Enemy/Enemy.h Enemy/ADN.cpp Enemy/ADN.h)
target_link_libraries(LOG -lallegro -lallegro_font -lallegro_image -lallegro_ttf)