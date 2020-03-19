//case 3 is under development only .if end is not connected to start it souldnt display anything right? that part is not delt with
void dfs(Graph G)
{
    int visit[G.vertices+1]={0};
    stack<vertex> stack;
    for(int i=1;i<=G.vertices;i++)
    {
        if(visit[i]!=1)
        {
            stack.push(G.Graph[i]);
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
    }
    
}

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

void dfs(Graph G,int start,int end)
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
                    if(s.data==end)
                    return;
                for(auto k:s.edges)
                {
                    if(visit[k]==0)
                    stack.push(G.Graph[k]);
                }    


                
            }
    
}