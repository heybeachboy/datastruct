#include <iostream>
#include "mathfunction/math.h"
#include <vector>
#include "util/myVector.h"
#include "util/Sort.h"
#include "util/leecode.h"
#include "line/Stack.h"
#include "line/Queue.h"
#include "graph/sparsegraph.h"
#include "graph/densegraph.h"
#include "graph/ReadGraphConfig.h"
#include "graph/Component.h"

using namespace Calculation;
using namespace Util;
using namespace TestAssistant;
using namespace LeeCode;
int main() {
    int a,b;
    a = 33;
    b = 44;
    int number = 10;
    int * data = GetRandomArray(number,100,200);
    ShowArrayElement(data,number);
   // SelectSort(data,number);
    //InsertSort(data,number);
    //BubbleSort(data,number);
    //MergeSort(data,number);
   /* QuickSort(data,number);
    ShowArrayElement(data,number);
    delete[] data;
    Math cal;
    Stack<string> s(10);
    s.Push("A");
    s.Push("B");
    ZQueue<int> q;
    q.Insert(1);
    q.Insert(2);
    q.Insert(3);
    q.Insert(4);
    std::cout << "zqueue size : " << q.Size() << endl;
    std::cout << "queue head : " << q.Front() << endl;
    q.Pop();
    std::cout << "queue tail : " << q.Tail() << endl;
    q.Pop();
    std::cout << "zqueue size : " << q.Size() << endl;
    std::cout << "location :" << s.Size() << std::endl;
    std::cout << "Peek 2 : " << s.Peek() << std::endl;
    std::cout << "Sum : " << cal.Sum(a,b) << std::endl;
    std::cout << "Pow : " << cal.Pow(2,10) << std::endl;
    std::cout << "Hello, World!" << std::endl;*/

   /*int total = 100;
   int N = 20;
   srand(time(NULL));
   SparseGraph g1(total, false);
   for(int i = 0; i < total;i++) {
       int a = rand() % N;
       int b = rand() % N;
       g1.AddNewEdge(a,b);
   }
   cout << "Total of edge : " << g1.GetEdgeOfNum() << " Total Node : " << g1.GetNodeOfNum() << endl;
   for(int i = 0; i < N; i++) {
       cout << i << " : ";
       SparseGraph::Iterator adj(g1,i);
       for(int node = adj.begin();!adj.end();node = adj.next()){
           cout << node << " ";
       }
       cout << endl;
   }

   DenseGraph g2(total, false);
    for(int i = 0; i < total;i++) {
        int a = rand() % 40;
        int b = rand() % 40;
        g2.AddNewEdge(a,b);
    }

    cout << "Total of edge : " << g2.GetEdgeOfNum() << " Total Node : " << g2.GetNodeOfNum() << endl;
    for(int i = 0; i < N; i++) {
        cout << i << " : ";
        DenseGraph::Iterator adj(g2,i);
        for(int node = adj.begin();!adj.end();node = adj.next()){
            cout << node << " ";
        }
        cout << endl;
    }*/

  /* const string fileName = "C:\\Users\\DELL\\CLionProjects\\datastruct\\graph\\graph1";
   SparseGraph g1(13, false);
   BuildGraph<SparseGraph> buildGraph(g1,fileName);
   g1.ShowNode();
   Component<SparseGraph> component1(g1);
   cout << "graph Component Count : " << component1.GetCount() << endl;
    const string fileName2 = "C:\\Users\\DELL\\CLionProjects\\datastruct\\graph\\graph2";
   DenseGraph  g2(6, false);
   BuildGraph<DenseGraph> buildGraph1(g2,fileName2);
   g2.ShowNode();
   Component<DenseGraph> component2(g2);
   cout << "graph Component Count : " << component2.GetCount() << endl;*/

  /*vector<string> str = letterCombinations("2346");
   cout << str.size() << ":";
  for(int i = 0; i< str.size(); i++) {
      cout << " " << str[i];
  }
  cout << endl;*/
  //vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
 // vector<vector<char>> grid = {{'X','O','X','X'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'}};
  //int num = numIslands(grid);
  //solve(grid);
 // cout << "island num : " << num << endl;
 /*for(int i=0; i < grid.size(); i++) {
     for(int j=0; j <grid[0].size(); j++) {
         cout  << " " << grid[i][j];
     }
     cout << endl;
 }*/
 /*vector<vector<int>> matrix = {{1,2,2,3,5},
                               {3,2,3,4,4},
                               {2,4,5,3,1},
                               {6,7,1,4,5},
                               {5,1,1,2,4}},rest;
 rest = pacificAtlantic(matrix);
 for(int i = 0; i < rest.size(); ++i) {
     for(int j = 0; j<rest[0].size(); ++j) {
         cout << " " << rest[i][j];
     }
     cout << endl;
 }*/
 /*vector<int> test = {1,2,3,4,5};
    bool rest = containsDuplicate(test);
    cout << rest << endl;*/
    //vector<int> test = {9,8,7,6,5,4,3,2,1,0};
    /*vector<int> test = {9,7,6,5,4,3,2,1,0,0};
    test = plusOne(test);
    for(auto i : test) {
        cout << " " << i;
    }
    cout << endl;*/
    //cout << "reverse :" << reverse(-2147483412) << endl;
    vector<int> list = {2,5,8,12,19};
   // if(binarySearch(list,0,4,5))cout << "congratulations :" << 5 << endl;
   vector<string> rest = partition("sjkfgsjfdgsfkhhgsdg");
   for(auto s :rest)cout << " " << s;

 return 0;
}