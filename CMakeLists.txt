cmake_minimum_required(VERSION 3.13)
project(datastruct)

set(CMAKE_CXX_STANDARD 14)

add_executable(datastruct main.cpp mathfunction/Math.cpp mathfunction/Math.h util/tools.cpp util/tools.h util/Sort.h util/Tree.cpp util/Tree.h util/myVector.h util/leecode.h util/matrix.h line/Stack.h line/Queue.h tree/BinaryTree.h graph/sparsegraph.h graph/densegraph.h graph/ReadGraphConfig.h graph/Component.h)