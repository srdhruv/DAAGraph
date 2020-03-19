#include <iostream>
#include <vector>
#include "Graph.h"
#include "module1.h"
using namespace std;

int main()
{
    int n,m;
    Graph G;
    cout << "Enter number of vertices ";
    cin >> n;
    G.vertices=n;
    G.addVertices(n);
    
    cout << "Enter number of edges ";
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cout << "Enter edge " << i << ": " ;
        int x, y;
        cin >> x >> y;
        G.addEdge(x ,y );
    }
    G.showGraph();
    cout<<"DFS\n\n"<<endl;
    dfs(G);

    return 0;
}
