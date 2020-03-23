//only for undirectedgraph i guess
#include<list>
void bfs(Graph G)
{
    int visit[G.vertex_count+1]={0};
    int bfsnow[G.vertex_count +1];
    int bfs_size=0;
    list<int> queue;
   int flag;
   for(int l=1;l<=G.vertex_count;l++)
    {
    if(visit[l]==0)
    flag=1;
    else
    flag=0;
    
    if(flag==1)
    {
            
    visit[l]=1;
    queue.push_back(l);
  //  cout<<endl<<l<<endl;
    while (!queue.empty())
    {
        int s=queue.front();
        bfsnow[bfs_size++]=s;
    //    cout<<s;
        queue.pop_front();
        
                    struct edgelist *temp=G.edges[s];
                    while(temp!=NULL)
                    {
                    int k=temp->value;
                    if(visit[k]==0)
                    {
                    visit[k]=1;    
                    queue.push_back(k);
                    }
                    temp=temp->next;
                    }


    }
    }
    }
    cout<<endl<<"bfs"<<endl;
    for(int i=0;i<bfs_size;i++)
    cout<<" "<<bfsnow[i]<<" ";
}   



void bfs(Graph G,int start)
{
    int visit[G.vertex_count+1]={0};
    int bfsnow[G.vertex_count +1];
    int bfs_size=0;
    list<int> queue;
    
    visit[start]=1;
    queue.push_back(start);
    while (!queue.empty())
    {
        int s=queue.front();
        bfsnow[bfs_size++]=s;
        queue.pop_front();
        
                    struct edgelist *temp=G.edges[s];
                    while(temp!=NULL)
                    {
                    int k=temp->value;
                    if(visit[k]==0)
                    {
                    visit[k]=1;    
                    queue.push_back(k);
                    }
                    temp=temp->next;
                    }


    }
    cout<<endl<<"bfs"<<endl;
    for(int i=0;i<bfs_size;i++)
    cout<<" "<<bfsnow[i]<<" ";
}   

void bfs(Graph G,int start,int end)
{
    int visit[G.vertex_count+1]={0};
    int bfsnow[G.vertex_count +1];
    int bfs_size=0;
    list<int> queue;
    
    visit[start]=1;
    queue.push_back(start);
    while (!queue.empty())
    {
        int s=queue.front();
        bfsnow[bfs_size++]=s;
        if(s==end)
        break;
        queue.pop_front();
        
                    struct edgelist *temp=G.edges[s];
                    while(temp!=NULL)
                    {
                    int k=temp->value;
                    if(visit[k]==0)
                    {
                    visit[k]=1;    
                    queue.push_back(k);
                    }
                    temp=temp->next;
                    }


    }
    int flag;
    for(int i=0;i<bfs_size;i++)
    if(bfsnow[i]==end)
    flag=1;
    else
    flag=0;
    
    if(flag==0)
    cout<<endl<<end<<" not reachable from "<<start<<"using bfs"<<endl;
    else
    {
         cout<<endl<<end<<"  reachable from "<<start<<"using bfs"<<endl<<"path :";
         for(int k=0;k<bfs_size;k++)
         {
         cout<<" "<<bfsnow[k]<<" ";
         if(bfsnow[k]==end)
         break;
         }
    }
}   




/*

*/
