#include<iostream>
#include<queue>
#include<string.h> // for memset
#include<limits.h>

using namespace std;

#define V 6   // number of vertices

bool augmenting_path(int rGraph[V][V],int source,int sink,int parent[V]){
	bool visited[V];
	memset(visited,0,sizeof(visited)); //making all the values in visited 0;
	
	//initializing beginning values
	queue<int>q;
	q.push(source);
	visited[source]=1;
	parent[source]=-1;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		//finding path
		for(int v=0;v<V;v++){
			if(visited[v]==false && rGraph[u][v]>0){

				if(v==sink){
					parent[v]=u;
					return true;
				}
				
				visited[v]=true;
				q.push(v);
				parent[v]=u;
			}
		}
	}
	return false; //didnt find augmenting path
	
}

int fordFulkerson(int graph[V][V],int s,int t){
	
	int maxFlow = 0;
	
	int rGraph[V][V];
	//creating a residual graph
	int u,v;
	for(u =0;u<V;u++){
		for(v=0;v<V;v++){
			rGraph[u][v] = graph[u][v];
		}
	}
	
	int parent[V]; //filled by augmenting path
	
	while(augmenting_path(rGraph,s,t,parent)){
		//now that there is an augmenting path we need to find bottleneck
		int bottleNeck = INT_MAX;
		for(v=t;v!=s;v=parent[v]){
			u = parent[v];
			bottleNeck = min(bottleNeck,rGraph[u][v]);
		}
		
		//update the residual graph using the bottleNeck value
		for(v=t;v!=s;v=parent[v]){
			u = parent[v];
			rGraph[u][v]-=bottleNeck;
			rGraph[v][u]+=bottleNeck;
		}
		maxFlow += bottleNeck;
	}
	return maxFlow;
}

int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);
 
    return 0;
}