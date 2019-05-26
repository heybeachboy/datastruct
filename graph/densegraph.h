//
//用于稠密图的创建
// Created by DELL on 2019/4/20.
//

#ifndef DATASTRUCT_DENSEGRAPH_H
#define DATASTRUCT_DENSEGRAPH_H

#include<vector>
#include<cassert>

using namespace std;

class DenseGraph {
private:
    int n, m;
    bool directed;
    vector<vector<bool>> g;

    void initDenseGraph() {
        for (int i = 0; i < this->n; i++) {
            this->g.push_back(vector<bool>(n, false));
        }
    }

    bool isHave(int v, int w) {
        return this->g[v][w];
    }

public:
    DenseGraph(int n, bool directed) {
        this->m = 0;
        this->n = n;
        this->directed = directed;
        this->initDenseGraph();
    }

    ~DenseGraph() {

    }

    int GetNodeOfNum() {
        return n;
    }

    int GetEdgeOfNum() {
        return m;
    }

    void ShowNode() {
         for(int i = 0; i < n; i++) {
             vector<bool> currentNode = this->g[i];
             cout << i << ":";
             for(int j =0; j< currentNode.size(); j++ ){
                if(!currentNode[j]) {
                    continue;
                }
                cout << " " << j;
             }
             cout << endl;
         }
    }

    bool AddNewEdge(int v, int w) {
        assert(v >= 0 && v < this->n);
        assert(w >= 0 && w < this->n);
        if (this->isHave(v, w)) {
            return false;
        }
        this->g[v][w] = true;
        if (!this->directed) {
            g[w][v] = true;
        }
        this->m++;
        return true;

    }

    class Iterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        Iterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;

        }

        int begin() {
            this->index = 0;
            if (this->G.g[v].size()) {
                return this->G.g[v][index];
            }
            return -1;
        }

        int next() {

            for (int i = index; i < G.g[v].size(); i++) {
                if (!G.g[v][i]) {
                    continue;
                }
                this->index = i + 1;
                return i;
            }
            this->index = G.g[v].size();
            return -1;
        }

        bool end() {
             return this->index >= G.g[v].size();

        }
    };

};

#endif //DATASTRUCT_DENSEGRAPH_H
