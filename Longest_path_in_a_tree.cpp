#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e6 + 1;
vector<int> adj[MAX];
int N, u, v, first_max = 0, first_max_node, max_count = 0;
int dfs(int i, bool visited[], int count)
{
	visited[i] = true;
	vector<int>::iterator itr;
	for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs(*itr, visited, count + 1);
		}
	}
	if(first_max < count)
	{
		first_max = count;
		first_max_node = i;
	}
	return first_max_node;
}
int dfs_length(int i, bool visited[], int count)
{
	visited[i] = true;
	//printf("occur  %d\n", i);
	vector<int>::iterator itr;
	for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs_length(*itr, visited, count + 1);
		}
	}
	max_count = max(max_count, count);
	//printf("%d  %d\n", i, count);
	return max_count;
}
int main()
{
	scanf("%d", &N);
	bool visited[N];
	visited[0] = false;
	for(int i = 1; i < N; i++)
	{
		scanf("%d %d",  &u, &v);
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
		visited[i] = false;
	}
	int first_vertex = dfs(0, visited, 0);
	//printf("%d\n", first_vertex);
	for(int i = 0; i < N; i++)
	{
		visited[i] = false;
	}
	printf("%d\n", dfs_length(first_vertex ,visited, 0));
	return 0;
}