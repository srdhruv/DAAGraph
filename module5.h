/*
MST_Prim(Graph G)
MST_Kruskal(Graph G)
MST_youralgo(Graph G)
*/
#include "Graph.h"
#include <iostream>
#define infi 2147483647
using namespace std;

void mst_Prim(Graph G)
{
    int n = G.vertex_count;
    int added[n+1],distance[n+1],mst[n+1],parent[n+1];
    int u = 1,v;
    int minDistance,count = 0;
    struct edgelist *temp;
    
    for(int i = 1; i <= n; i++)
    {
        added[i] = 0;
        distance[i] = infi;  
        parent[i] = 0;
    }
    u = 1;
    distance[u] = 0;
    parent[u] = 0;

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
                parent[v] = u;
            }
            temp = temp->next;
        }

        v = 1;
        //For selecting nearest available node
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
    int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        cout << i << " - " << parent[i] << " = " << distance[i] << endl;
        sum += distance[i];
    }
    cout << "Total distance = " << sum << endl;

}