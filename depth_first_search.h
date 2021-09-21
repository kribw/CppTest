#pragma once

// concepts
#include <predef_shared/concepts/graphs.h>

// stl
#include <vector>
#include <set>
#include <stack>

template<predef::concepts::graph::BidirectionalGraph Graph_T>
std::vector<typename Graph_T::vertex_descriptor>
depthFirstSearch([[maybe_unused]] Graph_T const &graph,
                 [[maybe_unused]] typename Graph_T::vertex_descriptor const &start) {
    using VertexDescriptor = typename Graph_T::vertex_descriptor;
    std::vector<VertexDescriptor> path{};
    std::unordered_set<VertexDescriptor> visited{};
    std::stack<VertexDescriptor> stack;

    stack.push(start);

    while (!stack.empty()) {
        auto vertex = stack.top();
        stack.pop();

        if (visited.contains(vertex)) {
            // Vertex has already been visited
            // Skip vertex and continue loop
            continue;
        }

        visited.insert(vertex);

        if (vertex != start) {
            path.push_back(vertex);
        }

        // Get vertices from current vertex's edges
        // and add them to the queue
        auto edges = boost::out_edges(vertex, graph);
        for (auto it = edges.second; it != edges.first;) {
            --it;
            VertexDescriptor edge_vertex = boost::target(*it, graph);
            stack.push(edge_vertex);
        }
    }
    return path;
}