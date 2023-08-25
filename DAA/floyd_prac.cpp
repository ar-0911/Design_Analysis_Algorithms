#include<bits/stdc++.h>
using namespace std;

#define INF 999999
//here dist is the adjacency matrix
#define V 4

void print_solution(int dist[][V]);
void floyd_warshall(int dist[][V]){
	int i,j,k;
	for(int k = 0;k<V;k++){
		for(int i = 0;i<V;i++){
			for(int j = 0;j<V;j++){
				if(dist[i][j]>(dist[i][k]+dist[k][j]) && (dist[i][k]!=INF && dist[k][j]!=INF)){
					dist[i][j] = dist[i][k]+dist[k][j] ;
				}
			}
		}
	}
	print_solution(dist);
}

void print_solution(int dist[][V]){
	int vertices = V;
	for(int i = 0;i<vertices;i++){
		for(int j = 0;j<vertices;j++){
			if(dist[i][j]==INF){
				cout<<" INF ";
			}
			else{
				cout<<" "<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

int main(){
	 int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    // Function call
    floyd_warshall(graph);
    return 0;
}

