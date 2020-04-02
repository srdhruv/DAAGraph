//Biparite .. disconnected seems working , check for variety cases
#include<list>
void Test_Bipartite(Graph G)
{
    int visit[G.vertex_count+1]={0};
    int colour[G.vertex_count+1];
    for(int p=0;p<G.vertex_count+1;p++)
    colour[p]=-1;
    //int bfsnow[G.vertex_count +1];
    //int bfs_size=0;
    bool check=true;
    
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

      //    cout<<"bla"<<endl;  
    visit[l]=1;
    colour[l]=1;
   // cout<<endl<<l<<" "<<1<<endl;
    queue.push_back(l);
  //  cout<<endl<<l<<endl;
    while (!queue.empty())
    {
        int s=queue.front();
     //   bfsnow[bfs_size++]=s;
    //    cout<<s;
        queue.pop_front();
        
                    struct edgelist *temp=G.edges[s];
                    while(temp!=NULL)
                    {
                    int k=temp->value;
                    if(visit[k]==0)
                    {
                    visit[k]=1;   
                    if(colour[k]==-1)
                    {
                    colour[k]=1-colour[s]; 
                   // cout<<endl<<k<<" "<<colour[k];
                    }
                    queue.push_back(k);
                    }
                    else if(visit[k]==1&&(colour[k]==colour[s]))
                    {
                        check=false;
                     //   cout<<endl<<k<<" "<<s<<colour[k]<<" "<<colour[s];
                        goto qqq;
                    }
                    temp=temp->next;
                    }


    }
    }
    }
    qqq:
    if(check==true)
    cout<<endl<<"IT is bipartite";
    else
    cout<<endl<<"IT is not bipartite";
        
    //cout<<endl<<"bfs"<<endl;
    //for(int i=0;i<bfs_size;i++)
    //cout<<" "<<bfsnow[i]<<" ";
}   
