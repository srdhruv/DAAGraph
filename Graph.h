#include <iostream>
#include <vector>
using namespace std;

struct vertex{
    int data;
    std::vector<int> edges;
};
class Graph
{
    
    public:
        int vertices;
        std::vector<vertex> Graph;
        void showGraph();
        void addVertices(int n);
        void addEdge(int u,int v);
        

};
void Graph::addVertices(int n)
{
    for(int i = 0; i <= n; i++)
    {
        struct vertex v;
         v.data=i;
        Graph.push_back(v);
    }

}
void Graph::addEdge(int u,int v)
{
    Graph[u].edges.push_back(v);
    Graph[v].edges.push_back(u);
}
void Graph::showGraph()
{
    int i = 0;
    for(auto u:Graph)
    {
        if(i != 0)
        {
            cout << i << " -> " ;
            for(auto x: u.edges)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        i++;
    }
}
/*
void bfs(Graph G);
void bfs(Graph G,int start);
void bfs(Graph G,int start,int end);
void dfs(Graph G);
void dfs(Graph G,int start);
void dfs(Graph G,int start,int end);
*/
