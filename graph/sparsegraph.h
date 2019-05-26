//
 //用于稀疏图的创建
// Created by DELL on 2019/4/20.
//

#ifndef DATASTRUCT_SPARSEGRAPH_H
#define DATASTRUCT_SPARSEGRAPH_H
#include<vector>
#include<cassert>
using namespace std;

class SparseGraph {
private:
    int n,m;
    bool directed;
    vector<vector<int>> g;
    void initSparseGraph() {
         for(int i = 0; i<this->n; i++) {
             this->g.push_back(vector<int>());
         }
    }
public:
    SparseGraph(int n, bool directed) {
         this->n = n;
         this->m = 0;
         this->directed = directed;
         initSparseGraph();
    }

    bool AddNewEdge(int v, int w) {
         assert(v >= 0 && v < this->n);
         assert(w >= 0 && w < this->n);
         this->g[v].push_back(w);
         if(!this->directed) {
             this->g[w].push_back(v);
         }
         this->m++;
         return true;
    }
    int GetNodeOfNum() {
        return this->n;
    }

    int GetEdgeOfNum() {
        return this->m;
    }
    void ShowNode() {
        for(int i = 0; i < n; i++) {
            vector<int> currentNode = this->g[i];
            cout << i << ":";
            for(int j =0; j< currentNode.size(); j++ ){
                cout << " " << j;
            }
            cout << endl;
        }
    }

    class Iterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        Iterator(SparseGraph &graph, int v): G(graph) {
            this->v = v;
            this->index = 0;

        }
        int begin() {
            this->index = 0;
            if(this->G.g[v].size() > 0 ){
                return this->G.g[v][index];
            }
            return -1;
        }

        int next(){
            if(this->index < G.g[v].size()){
                return G.g[v][++this->index];
            }
            return -1;

        }
        bool end() {
            return this->index >= G.g[v].size();
        }


    };



};

#endif //DATASTRUCT_SPARSEGRAPH_H
