
#include <cstdlib>
#include <iostream>
#include<stack>
using namespace std;
//#define max 1001;
struct edgelist{
    int value;
    int weight;
    struct edgelist *next;
};

class Graph{
    public:
        edgelist *edges[1000];
        int InDegree[1000];
        int OutDegree[1000];
        int vertex_count ;
        int edge_count;
        int directed ;
        void showGraph();
        void addVertex(int n);
        void addEdge(int x,int y);
        Graph()
        {
      //  edges[]={};
        vertex_count = 0;
        edge_count = 0;
        directed = 0;
        }
};

//n is number of new vertices
void Graph::addVertex(int n)
{
    for(int i = vertex_count + 1; i <= vertex_count + n; i++)
    {
        
        InDegree[i] = 0;
        OutDegree[i] = 0;
    
        edges[i] = NULL;
    }
    vertex_count += n;
};


void Graph::addEdge(int x,int y)
{
    struct edgelist *temp1 = (struct edgelist *) malloc(sizeof(struct edgelist));
    temp1->value = y;
    InDegree[y]++;
    OutDegree[x]++;
    
    if(edges[x] == NULL)//IF edgelist of vertex x is empty
    {
        edges[x] = temp1;
        edges[x]->next=NULL;
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
              edges[y]->next=NULL;
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

void dfs(Graph G)
{
    int visit[G.vertex_count+1]={0};
    stack<int> stack;
    for(int i=1;i<=G.vertex_count;i++)
    {
        if(visit[i]!=1)
        {
            stack.push(i);
            while(!stack.empty())
            {
                int s=stack.top();
                stack.pop();
                    if(visit[s]==0)
                    {
                        cout<<" "<<s<<" ";
                        visit[s]=1;
                    }    
                
                
                    struct edgelist *temp=G.edges[s];
                    while(temp!=NULL)
                    {
                        int k=temp->value;
                    if(visit[k]==0)
                    stack.push(k);
                    temp=temp->next;
                    }
                



                
            }







        }
    }
    
}