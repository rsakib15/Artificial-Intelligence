// Depth First Search.cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#define NL '\n'
using namespace std;
const int SIZE = 1e6;

vector< int > G[100];
int visited[100];

void dfs(int u)
{
    int I, v;
    visited[u] = 1;
    printf("%d ", u);

    for(I = 0; I < G[u].size(); I++)
    {
        v = G[u][I];
        if (!visited[v])
            dfs(v);
    }
}

int main()
{


    int node,edge,x,y;

    printf("Enter the number of node/vertex and edge: ");
	scanf("%d%d", &node, &edge);
    int src=0;
	printf("Adjacency List:\n");

	for (int I = 0; I < edge; I++){
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(src);
    printf("\n");

    return 0;
}