//only for undirectedgraph
#include<stack>
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

void dfs(Graph G,int start)
{
    int visit[G.vertex_count+1]={0};
    stack<int> stack;
    for(int i=start;i!=start-1;i=(i+1)%G.vertex_count)
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
                        if(s!=0)
                        {
                        cout<<" "<<s<<" ";
                        visit[s]=1;
                        } 
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

void dfs(Graph G,int start,int end)
{
    int visit[G.vertex_count+1]={0};
    stack<int> stack;
    int i=start;
    int inpath[G.vertex_count+1];
    int l=0;
    int flag=0;
            stack.push(i);
            while(!stack.empty())
            {
                int s=stack.top();
                stack.pop();
                    if(visit[s]==0)
                    {   
                        if(s!=0)
                        {
                        inpath[l++]=s;
                        visit[s]=1;
                        } 
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
    for(int k=0;k<l;k++)
    if(inpath[k]==end)
    flag=1;
    if(flag==0)
    cout<<endl<<end<<" not reachable from "<<start<<endl;
    else
    {
         cout<<endl<<end<<"  reachable from "<<start<<endl<<"path :";
         for(int k=0;k<l;k++)
         {
         cout<<" "<<inpath[k]<<" ";
         if(inpath[k]==end)
         break;
         }
    }
    
    
    
}



/*
void dfs(Graph G,int start)
{
    int visit[G.vertices+1]={0};
    stack<vertex> stack;
    
          stack.push(G.Graph[start]);
            while(!stack.empty())
            {
                vertex s=stack.top();
                stack.pop();
                    if(visit[s.data]==0)
                    {
                        cout<<" "<<s.data<<" ";
                        visit[s.data]=1;
                    }    
                for(auto k:s.edges)
                {
                    if(visit[k]==0)
                    stack.push(G.Graph[k]);
                }    


                
            }
    
}


*/