#include <iostream>
#include "temp2Graph.h"
using namespace std;

int main()
{
    Graph G;
    int x,y,z;
    cout << "Enter 1 for directed and 0 for undirected: ";
    cin >> x;
    if(x == 1)
        G.directed = 1;
    
    cout << "Enter number of vertices: ";
    cin >> x;
    G.addVertex(x);

    cout << "Enter number of edges: ";
    cin >> z;

    for(int i = 1; i <= z; i++)
    {
        cout << "Enter edge " << i << ": ";
        cin >> x >> y;
        G.addEdge(x,y);
    }
    G.showGraph();

    return 0;
}