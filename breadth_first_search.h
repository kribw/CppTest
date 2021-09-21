#pragma once

// concepts

// stl
#include <vector>

template<predef::concepts::graph::BidirectionalGraph Graph_T>
std::vector<typename Graph_T::vertex_descriptor>
breadthFirstSearch([[maybe_unused]] Graph_T const &graph,
                   [[maybe_unused]] typename Graph_T::vertex_descriptor const &start) {
    using VertexDescriptor = typename Graph_T::vertex_descriptor;
    std::unordered_set<VertexDescriptor> visited{};
    std::queue<VertexDescriptor> queue;
    std::vector<VertexDescriptor> path{};

    queue.push(start);

    while (!queue.empty()) {
        auto vertex = queue.front();
        queue.pop();

        if (visited.contains(vertex)) {
            // Vertex has already been visited.
            // Skip this element and continue loop
            continue;
        }

        visited.insert(vertex);

        if (vertex != start) {
            path.push_back(vertex);
        }

        // Get vertices from current vertex's edges
        // and add them to the queue.
        auto edges = boost::out_edges(vertex, graph);
        for (auto it = edges.first; it != edges.second; ++it) {
            VertexDescriptor vertex_out = boost::target(*it, graph);
            queue.push(vertex_out);
        }
    }
    return path;
}