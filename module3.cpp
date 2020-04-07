/*
Module 3
BFS_SPATH(G,s,flag=0) -- returns spath in unweighted graphs
BFS_SPATH(G,s,flag=1) -- returns spath in weighted graphs
LPATH(Tree T, flag=0) - returns the longest path in T (undirected tree)
LPATH(Tree T, flag=1) - returns the longest path in a DAG
MAX_Weight_MST(Graph G)
*/
#include "Graph.h"
#include <algorithm>
#include <queue>
using namespace std;
Graph BFS_SPATH(Graph G,int s,int flag)
{
    int VC = G.vertex_count;
    start:
    Graph SPATH;
    SPATH.addVertex(G.vertex_count);

    int distance[G.vertex_count + 1];
    int visited[G.vertex_count + 1];
    for(int i = 1; i <= G.vertex_count ; i++)
    {
        distance[i] = -1;
        visited[i] = 0;
    }
    distance[s] = 0;
    if(flag == 0)
    {
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            visited[u] = 1;
            struct edgelist *temp = G.edges[u];
            while(temp != NULL)
            {
                int v = temp->value;
                if(visited[v] == 0)
                {
                    visited[v] = 1;
                    distance[v] = distance[u] + 1;
                    Q.push(v);
                    SPATH.addEdge(u,v);
                }
                temp = temp->next;
            } 
        }
        for(int i = 1; i <= VC; i++)
        {
            std::cout << "Distance between " << s << " and " << i <<" is ";
            if(distance[i] == -1)
                std::cout << " infinity\n";
            else
            {
                std::cout << distance[i] <<"\n";
            }
            
        }
    }
    else
    {
        //If flag is one we need to convert weighted graph into unweighted
        
        for(int i = 1; i <= VC;i++)
        {
            edgelist *temp = G.edges[i];
            edgelist *pre = G.edges[i];
            
            while(temp != NULL)
            {
                if(temp->weight > 1)
                {
 
                    int p = i;
                    G.addVertex(1);
                    int c = G.vertex_count;
                    G.addEdge(p,c);
                    p = c;
                    c++;
                    int toadd = temp->weight - 2;
                    for(int j = 0; j < toadd - 1; j++)
                    {
                        G.addVertex(1);
                        G.addEdge(p,c);
                        p = c;
                        c++;
                    }
                    
                   
                    G.addEdge(p,temp->value);
                    pre->next = pre->next->next;
                    
                }
                pre = temp;
                temp = temp->next;
            }
        }

        flag = 0;
        goto start;

    }
    
  
  
    return SPATH;
}
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
    BFS_SPATH(G,1,1);

    return 0;
}
/*
0
8
10
2 3
2 1
1 4
4 8
4 5
5 8
7 8
6 7
5 6
5 7

0
8
10
2 3 5
2 1 10
1 4 2
4 8 1
4 5 3
5 8 1
7 8 4
6 7 8
5 6 25
5 7 5


0
3
3
1 2 5
1 3 1
2 3 2
*/