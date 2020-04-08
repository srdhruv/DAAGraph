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
pair<int,int> bfsLpath(Graph G,int s)
{
    int dist[G.vertex_count + 1];
    for(int i = 1; i <= G.vertex_count; i++)
        dist[i] = 0;
    queue<int> Q;
    Q.push(s);
    int maxDis = -1;
    int node = s;
    dist[s] = 0;
    while(!Q.empty())
    {
        int u =  Q.front();
        Q.pop();
        edgelist *temp = G.edges[u];
        while(temp != NULL)
        {
            int v = temp->value;
            if(dist[v] == 0)
            {
                Q.push(v);
                dist[v] = dist[u] + 1;
                if(dist[v] > maxDis)
                {
                    maxDis = dist[v];
                    node = v;
                }
            }
            temp = temp->next;
        }

    }
    return make_pair(node,maxDis);
}

int dfs_top(Graph G,int i,int s,int visited[],int top[])
{
    visited[s] = 1;
    edgelist *temp = G.edges[s];
    while(temp != NULL)
    {
        if(visited[temp->value] == 0)
        {
            i = dfs_top(G,i,temp->value,visited,top);
        }
        temp = temp->next;
    }
    top[i] = s;
    return i - 1;
}
void topsort(Graph G,int top[])
{
        int visited[G.vertex_count + 1];
        for(int i = 1; i <= G.vertex_count; i++)    
            visited[i] = 0;
        int i = G.vertex_count - 1;
        for(int j = 1; j <= G.vertex_count; j++)
        {
            if(visited[j] == 0)
                i = dfs_top(G,i,j,visited,top);
        }
}


//Enter flag 0 tree flag 1 enter DAG 
void Lpath(Graph G,int flag)
{   //Longest path in tree
    if(flag == 0)
    {
        pair<int,int> u,v;
        u = bfsLpath(G,1);
        v = bfsLpath(G,u.first);
        cout << "Longest path is between " << u.first << " and " << v.first << " and distance is " << v.second << "\n";
    }
    else
    {
        //FOR DAG
        //First topsort it
        //Then multiplying edges by -1
        //Find shortest path on DAG using topsort array
        int topsorted[G.vertex_count];
        
        topsort(G,topsorted);
        //for(int i = 0; i < G.vertex_count; i++)
        //    cout << topsorted[i] << " ";
        int parent[G.vertex_count + 1];
        int dist[G.vertex_count + 1];
        for(int j = 1; j <= G.vertex_count; j++)
        {
            parent[j] = j;
            dist[j] = INT32_MAX;
        }     
        dist[topsorted[0]] = 0;
        int min_dist = INT32_MAX, node = topsorted[0];
        for(int i = 0; i < G.vertex_count; i++)
        {
           int u = topsorted[i];
           if(dist[u] == INT32_MAX)
            dist[u] = 0;
           edgelist *temp = G.edges[u];
           while(temp != NULL)
           {
               if(dist[temp->value] > (dist[u] - temp->weight))
               {
                //   cout << u << " - " << temp->value << " ori dis " << dist[temp->value]<< " new " << dist[u] << " - " << temp->weight <<endl ;
                   dist[temp->value] = dist[u] -temp->weight;
                   parent[temp->value] = u;
                   if(dist[temp->value] < min_dist)
                   {
                       min_dist = dist[temp->value];
                       node = temp->value;
                   }
               }
               temp = temp->next;
           }
        }
       // cout << endl;
       // for(int i = 1; i <= G.vertex_count; i++)
       //     cout << dist[i] << " ";
        cout << "MAX DISTANCE IS " << 0 - min_dist  << " and Longest path is " << node ;
        while(parent[node] != node)
        {
            cout << " <--- ";
            node = parent[node];
            cout << node ;
        }

    }
    
}


void MAX_Weight_MST(Graph G)
{
    int n = G.vertex_count;
    int added[n+1],distance[n+1],parent[n+1];
    int u = 1,v;
    int maxDistance;
    struct edgelist *temp;
    
    for(int i = 1; i <= n; i++)
    {
        added[i] = 0;
        distance[i] = INT32_MIN;  
        parent[i] = i;
    }
    u = 1;
    distance[u] = 0;
    parent[u] = 1;

    while(added[u] == 0)
    {
        added[u] = 1;
        temp = G.edges[u];
        while(temp != NULL)
        {
            v = temp->value;
            if(added[v] == 0 && temp->weight > distance[v])
            {
                distance[v] = temp->weight;
                parent[v] = u;
            }
            temp = temp->next;
        }

        v = 1;
        //For selecting nearest available node
        maxDistance = INT32_MIN;
        for(int i = 1; i <= n; i++)
        {
            if(added[i] == 0 && maxDistance < distance[i])
            {
                v = i;
                maxDistance = distance[i];
            }
        }
        
        u = v;
    }
    int sum = 0;
    cout << "Max distance spanning tree is :\n";
    for(int i = 1; i <= n; i++)
    {
        cout << i << " - " << parent[i] << " = " << distance[i] << endl;
        sum += distance[i];
    }
    cout << "Total distance = " << sum << endl;
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
        cin >> x >> y >> w ;
        G.addEdge(x,y,w);
    }
    MAX_Weight_MST(G);

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



0
10
9
1 2
2 3
3 4
3 10
3 5
5 6
2 7
7 8
7 9


lpath 1
1
8
13
1 2 3
1 3 6
2 3 4
2 4 4
2 5 11
3 4 8
3 7 11
4 5 -4
4 6 5
4 7 2
5 8 9
6 8 1
7 8 2

*/