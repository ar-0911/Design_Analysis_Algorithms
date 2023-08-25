#include<string.h>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

// graph[no of edges[][3] always 3 as we have only 3 values src,dst,and weight

void bellmanFord(int graph[][3],int V,int E,int src){
	
	//initialzing distance vertex
	int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
	
	//initializing distance of src as 0
	dist[src]=0;
	
	//relaxation
	//dist[graph[j][0]] = distance of start vertex of edge from source
	//graph[j][2] = weight of edge 
	//dist[graph[j][1]] = distance of end vertex of edge from source
	for(int i=0;i<V-1;i++){
		for(int j = 0;j<E;j++){
			if(dist[graph[j][0]]!=INT_MAX && dist[graph[j][0]]+graph[j][2]<dist[graph[j][1]]){
				dist[graph[j][1]] = dist[graph[j][0]]+graph[j][2];
			}
		}
	}
	
	//checking for negative cycle
	for(int i = 0;i<E;i++){
		int x = graph[i][0];  //start vertex of edge
		int y = graph[i][1];   //end vertex of edge
		int weight = graph[i][2];    //weight of edge
		if(dist[x]!=INT_MAX && dist[x]+weight < dist[y]){
			cout<<"Negative cycle present in graph"<<endl;
			return;
		}
	}
	
	cout<<"Vertex\tDistance from source"<<endl;
	for(int i=0;i<V;i++){
		cout<<i<<"\t\t"<<dist[i]<<endl;
	}
	
}

int main()
{
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
 
    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 },
                       { 1, 4, 2 }, { 3, 2, 5 },
                       { 3, 1, 1 }, { 4, 3, -3 } };
 
    bellmanFord(graph, V, E, 0);
    return 0;
}