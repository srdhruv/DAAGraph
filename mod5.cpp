
#include <iostream>
#include "template2graph.h"

#define infi 	2147483647
using namespace std;
void mst_Prim(Graph G);
int main()
{
    Graph G;
    int w,x,y,z;
    cout << "Enter 1 for directed and 0 for undirected: ";
    cin >> x;
    if(x == 1)
        G.directed = 1;
    
    cout << "Enter number of vertices: ";
    cin >> x;
    G.addVertex(x);

    cout << "Enter number of edges: ";
    cin >> z;
   // G.weighted = 1;
    for(int i = 1; i <= z; i++)
    {
        cout << "Enter edge " << i << ": ";
        cin >> x >> y >> w;
        G.addEdge(x,y,w);
    }
    G.showGraph();
    cout << endl;
    mst_Prim(G);

    return 0;
}
//Enter a Connected Graph
void mst_Prim(Graph G)
{
    int n = G.vertex_count;
    int added[n+1],distance[n+1],mst[n+1];
    int u = 1,v;
    int minDistance,count = 0;
    struct edgelist *temp;
    
    for(int i = 1; i <= n; i++)
    {
        added[i] = 0;
        distance[i] = infi;  
    }
    u = 1;
    distance[u] = 0;
    

    while(added[u] == 0)
    {
        added[u] = 1;
        mst[++count] = u;
        temp = G.edges[u];
        int wei = temp->weight;

        while(temp != NULL)
        {
            //Update the distances from edge u to  its neighbourhood if it is minimum edge
            v = temp->value;
            //IF we have not added v in added and also if he edgecost u-v is less distance[v]
            if(added[v] == 0 && temp->weight < distance[v])
            {
                distance[v] = temp->weight;
         
            }
            temp = temp->next;
        }

        v = 1;
        minDistance = infi;
        for(int i = 1; i <= n; i++)
        {
            if(added[i] == 0 && minDistance > distance[i])
            {
                v = i;
                minDistance = distance[i];
            }
        }
        u = v;
    }


    //TO PRINT MST
    cout <<"  " << mst[1] << endl;
    cout <<  "  |" << endl;
    cout <<  "  | "  << distance[mst[2]] << endl;
    cout << "  |" << endl;

    for(int i = 2; i <= n - 1; i++)
    {
        cout <<"  " << mst[i] << endl;
        cout <<  "  |" << endl;
        cout <<  "  | "  << distance[mst[i + 1]] << endl;
        cout << "  |" << endl;
    }

    cout << "  " << mst[n] << endl;
}
/*
Sample 
0
9
14
1 2 4
1 8 8
2 8 11
2 3 8
3 9 2
3 4 7
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 9 6
7 8 1
8 9 7

*/