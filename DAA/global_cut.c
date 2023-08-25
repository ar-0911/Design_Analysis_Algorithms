#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100

typedef struct edge {
    int u, v;
} Edge;

int find(int *parent, int i) {
    while (i != parent[i]) {
        i = parent[i];
    }
    return i;
}

void merge(int *parent, int *size, int i, int j) {
    int root_i = find(parent, i);
    int root_j = find(parent, j);
    if (root_i == root_j) {
        return;
    }
    if (size[root_i] < size[root_j]) {
        parent[root_i] = root_j;
        size[root_j] += size[root_i];
    } else {
        parent[root_j] = root_i;
        size[root_i] += size[root_j];
    }
}

int karger_stein(Edge *edges, int n) {
    int parent[MAX_N];
    int size[MAX_N];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    while (n > 2) {
        int index = rand() % n;
        Edge e = edges[index];
        merge(parent, size, e.u, e.v);
        edges[index] = edges[n-1];
        n--;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (find(parent, edges[i].u) != find(parent, edges[i].v)) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Edge edges[MAX_N*MAX_N];
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edges[m].u = i;
            edges[m].v = j;
            m++;
        }
    }
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            scanf("%d", &value);
            if (value) {
                for (int k = 0; k < m; k++) {
                    if ((edges[k].u == i && edges[k].v == j) ||
                        (edges[k].u == j && edges[k].v == i)) {
                        edges[k] = edges[m-1];
                        m--;
                        break;
                    }
                }
            }
        }
    }
    int min_cut = n*(n-1)/2;
    for (int i = 0; i < n*n; i++) {
        int cut = karger_stein(edges, m);
        if (cut < min_cut) {
            min_cut = cut;
        }
    }
    printf("The minimum cut is %d\n", min_cut);
    return 0;
}
