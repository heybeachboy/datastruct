//
// Created by DELL on 2019/4/28.
//

#ifndef DATASTRUCT_COMPONENT_H
#define DATASTRUCT_COMPONENT_H
template <class Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int count;
    void dfs(int i) {
        visited[i] = true;
        typename Graph::Iterator adj(G,i);
        for(int i = adj.begin(); !adj.end(); i = adj.next())
            if(!visited[i]){
                dfs(i);
            }

    }
public:
    Component(Graph &graph): G(graph) {
        visited = new bool[G.GetNodeOfNum()];
        count = 0;
        for(int i = 0; i<G.GetNodeOfNum(); i++)
            visited[i] = false;

        for(int j = 0; j < G.GetNodeOfNum(); j++){
            if(!visited[j]) {
                dfs(j);
                count++;
            }
        }

    }
    int GetCount() {
        return count;
    }
    ~Component(){
        delete[] visited;
    }

};
#endif //DATASTRUCT_COMPONENT_H
