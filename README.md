# DAAGraph
Elementary Graph Algorithms

Module 1

DFS(Graph G) -- choose start vertex arbitrarily and perform DFS
DFS(Graph G, vertex s)
DFS(Graph G, vertex s, vertex t) -- is t reachable from s

Module 2

BFS(Graph G)
BFS(Graph G, vertex s)
BFS(Graph G, vertex s, vertex t)

Module 3
BFS_SPATH(G,s,flag=0) -- returns spath in unweighted graphs
BFS_SPATH(G,s,flag=1) -- returns spath in weighted graphs
LPATH(Tree T, flag=0) - returns the longest path in T (undirected tree)
LPATH(Tree T, flag=1) - returns the longest path in a DAG
MAX_Weight_MST(Graph G)

Module 4

Test_bipartite(Graph G)
Test_articulationpoints(Graph G)
Test_bridges(Graph G)

Module 5

MST_Prim(Graph G)
MST_Kruskal(Graph G)
MST_youralgo(Graph G)


Module 1 to 5

Graph.h contains graph template

mod5.cpp contains working code for module 5 which will be lator converted into module5.h

Do not modify module5.h,mod5.cpp,module1_fortemplate2.h,module1.h and Graph.h. Only its creators must update them .

Step 1. Copy the repository link

Step 2. Open terminal use command git clone "The copied url"

Step 3. Use git pull to get latest commits

Step 4  Use git add filename to add file

Step 5  Use git commit to commit the changes

Step 6  and finally git push to commit changes in master branch.

git diff Tells the difference between branch and your local files

git status Tells the statuses

