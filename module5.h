
#include <iostream>
#include "Graph.h"
#define infi 	2147483647
using namespace std;
struct k_Edge
{
    int u;
    int v;
    int weight;
};
int root(int arr[],int x);
int find(int arr[],int x,int y);
void union_set(int arr[],int x,int y);
void kedge_sort(struct k_Edge arr[],int start,int end);
void kedge_swap(struct k_Edge *x,struct k_Edge *y);

//Main functions
void mst_Prim(Graph G);
void mst_kruskal(Graph G);




void mst_kruskal(Graph G)
{
    struct k_Edge edges[G.edge_count];
    int k = 0;
    for(int i = 1;i <= G.vertex_count;i++)
    {
        struct edgelist *temp = G.edges[i];
        while(temp != NULL)
        {
            edges[k].u = i;
            edges[k].v = temp->value;
            edges[k].weight = temp->weight;
            k++;
            temp = temp->next;
        }
    }
    kedge_sort(edges,0,k - 1);
  
    Graph MST;
    MST.weighted = 1;
    MST.addVertex(G.vertex_count);
    
    int disjoint[G.vertex_count + 1];
    for(int i = 1; i <= G.vertex_count; i++)
        disjoint[i] = i;
    printf("MST of Given graph by krushkal's algorithm is\nu -> v  == weight\n");
    int count_krushkal = 0;
    int sum_krushkal = 0;
    for(int i = 0; i < G.edge_count; i++)
    {
        if(count_krushkal == G.vertex_count - 1)
            break;
        if(find(disjoint,edges[i].u,edges[i].v))
        {
            continue;
        }
        else
        {
            union_set(disjoint,edges[i].u,edges[i].v);
            MST.addEdge(edges[i].u,edges[i].v,edges[i].weight);
            printf("%d -> %d  == %d\n",edges[i].u,edges[i].v,edges[i].weight);
            sum_krushkal += edges[i].weight;
            count_krushkal++;
        }
    }
    printf("Total weight = %d\n",sum_krushkal);
    
    


}

//Enter a undirected weighted graph G
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

void kedge_swap(struct k_Edge *x,struct k_Edge *y)
{
    struct k_Edge temp;
    temp.u = x->u;
    temp.v = x->v;
    temp.weight = x->weight;
    x->u = y->u;
    x->v = y->v;
    x->weight = y->weight;
    y->u = temp.u;
    y->v = temp.v;
    y->weight = temp.weight;
}

//Sort edges for k_edges in krushkal
void kedge_sort(struct k_Edge arr[],int start,int end)
{
    if(start < end)
    {
        
        int p_weight = arr[end].weight;
        int b = start;
        for(int i = start; i < end ;i++)
        {
            if(arr[i].weight < p_weight)
            {
                kedge_swap(&arr[i],&arr[b]);
                b++;
            }
        }
        kedge_swap(&arr[end],&arr[b]);
        kedge_sort(arr,start,b-1);
        kedge_sort(arr,b + 1,end);
    }
}



//return root of x
int root(int arr[],int x)
{
    while(arr[x] != x)
    {
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
//joins both set
void union_set(int arr[],int x,int y)
{
    int root_x = root(arr,x);
    int root_y = root(arr,y);
    arr[root_x] = root_y;
}

//Return 1 when both have same root
int find(int arr[],int x, int y)
{
    int root_x = root(arr,x);
    int root_y = root(arr,y);
    if(root_x == root_y)
        return 1;
    return 0;
}
