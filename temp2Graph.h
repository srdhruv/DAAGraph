#define max 1001
#include <cstdlib>
#include <iostream>
using namespace std;

struct edgelist{
    int value;
    int weight;
    struct edgelist *next;
};

class Graph{
    public:
        edgelist *edges[max];
        int InDegree[max];
        int OutDegree[max];
        int vertex_count = 0;
        int edge_count = 0;
        int directed = 0;
        void showGraph();
        void addVertex(int n);
        void addEdge(int x,int y);
};

//n is number of new vertices
void Graph::addVertex(int n)
{
    for(int i = vertex_count + 1; i <= vertex_count + n; i++)
    {
        edges[i] = NULL;
        InDegree[i] = 0;
        OutDegree[i] = 0;
    }
    vertex_count += n;
};


void Graph::addEdge(int x,int y)
{
    struct edgelist *temp1 = (struct edgelist *) malloc(sizeof(struct edgelist *));
    temp1->value = y;
    InDegree[y]++;
    OutDegree[x]++;
    
    if(edges[x] == NULL)//IF edgelist of vertex x is empty
    {
        edges[x] = temp1;
    }
    else
    {
        temp1->next = edges[x];
        edges[x] = temp1;
    }    
    edge_count++;

    if(directed == 0)
    {
        struct edgelist *temp2 = (struct edgelist *) malloc(sizeof(struct edgelist *));
        temp2->value = x;
        InDegree[x]++;
        OutDegree[y]++;
        if(edges[y] == NULL)
        {
            edges[y] = temp2;
        }
        else
        {
            temp2->next = edges[y];
            edges[y] = temp2;
        }
        edge_count++;
    }

};

void Graph::showGraph()
{
    cout << "Graph is  " << endl;
    for(int i = 1; i <= vertex_count; i++)
    {
        cout << i << " -> ";
        struct edgelist *current;
        current = edges[i];

        while(current != NULL)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
}
