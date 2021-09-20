#pragma once

// concepts
#include <predef_shared/concepts/graphs.h>

#include <boost/graph/adjacency_list.hpp>

// stl
#include <vector>

template<predef::concepts::graph::BidirectionalGraph Graph_T>
std::vector<typename Graph_T::vertex_descriptor>
breadthFirstSearch([[maybe_unused]] Graph_T const &graph,
                   [[maybe_unused]] typename Graph_T::vertex_descriptor const &start) {
    using VertexDescriptor = typename Graph_T::vertex_descriptor;
    std::vector<VertexDescriptor> path {};
    std::queue<VertexDescriptor> queue(start);
    std::vector<VertexDescriptor> visited {};


    return path;
}