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


void Test_articulationpoint(Graph G)
{
    int artic[G.vertex_count+1];
    int b=0;//no of points
int visit[G.vertex_count+1]={0};
int noofparts=0;
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
    noofparts++;          
    visit[l]=1;
    queue.push_back(l);
      while (!queue.empty())
    {
        int s=queue.front();
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

for(int p=1;p<=G.vertex_count;p++)
{
    int tempgraph[G.vertex_count+1][G.vertex_count+1]={0};
    for(int i = 1; i <= G.vertex_count; i++)
    {
        if(i==p)
        for(int j=0;j<=G.vertex_count;j++)
        tempgraph[j][i]=tempgraph[i][j]=0;
        else
        {
        struct edgelist *current;
        current = G.edges[i];
        //struct edgelist *prev=NULL;
        //if(current->value==p)
        //{
           // if(k->edges[i]->next==NULL)
            //k->edges[i]=NULL;
        //else
        //k->edges[i]=k->edges[i]->next;
        //}
        //else
        //{
        while(current != NULL)
        {
            if(current->value==p)
            {
               // if(p==2&&i==5)
               // {
                  //  cout<<current->value<<endl;
                //}
                //prev->next=current->next;
                //break;
            current=current->next;          
            }
            else
            {
                tempgraph[current->value][i]=tempgraph[i][current->value]=1;
                current=current->next; 
            }
            
        }
        }
        }
/*        
 for(int i=1;i<=G.vertex_count;i++)
{
    cout<<endl;
 for(int j=1;j<=G.vertex_count;j++)
 cout<<tempgraph[i][j]<<" ";
 cout<<endl;
}*/
    
    
int visitnow[G.vertex_count+1]={0};
int noofpartsnow=0;
list<int> queuenow;
//int flag;
for(int l=1;l<=G.vertex_count;l++)
    {
    if(visitnow[l]==0)
    flag=1;
    else
    flag=0;
    
    if(flag==1)
    {
    noofpartsnow++;          
    visitnow[l]=1;
    queuenow.push_back(l);
      while (!queuenow.empty())
    {
        int s=queuenow.front();
          queuenow.pop_front();
        
                    for(int j=1;j<=G.vertex_count;j++)
                    {
                        if(tempgraph[s][j]==1)
                        {
                        if(visitnow[j]==0)
                        {
                        visitnow[j]=1;    
                        queuenow.push_back(j);
                        }
                        }
                    }
    }
    }
    }
   // cout<<endl<<" "<<p<<" "<<noofpartsnow;
    if(noofpartsnow>(noofparts+1))
    {
        artic[b++]=p;
    }
}              
    


cout<<endl<<"No of articulation points : "<<b<<endl;
cout<<endl<<"Points:  ";
for(int l=0;l<b;l++)
cout<<" "<<artic[l];

    
    
    
    
 }
