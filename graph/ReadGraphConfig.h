//
// Created by DELL on 2019/4/27.
//

#ifndef DATASTRUCT_READGRAPHCONFIG_H
#define DATASTRUCT_READGRAPHCONFIG_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;
/**
 *
 * @tparam Graph
 */
template<typename Graph>
class BuildGraph {
public:
    BuildGraph(Graph &graph, const string &configName) {
        ifstream file(configName);
        string line;
        int N, E;
        assert(file.is_open());
        assert(getline(file, line));
        stringstream ss(line);
        ss >> N >> E;
        assert(N == graph.GetNodeOfNum());
        for (int i = 0; i < E; i++) {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            ss >> a >> b;
            graph.AddNewEdge(a, b);
        }

    }
};


#endif //DATASTRUCT_READGRAPHCONFIG_H
