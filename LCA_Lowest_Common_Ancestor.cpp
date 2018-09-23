#include <bits/stdc++.h>
using namespace std;
#define MAX 10005
vector<int> adj[MAX];
int parent[MAX];
int main()
{
	int T, N, M, u, v, Q;
	scanf("%d", &T);
	for(int test = 1; test <= T; test++)
	{
		for(int i = 0; i < MAX; i++)
		{
			adj[i].clear();
		}
		scanf("%d", &N);
		parent[1] = -1;
		for(int i = 1; i <= N; i++)
		{
			scanf("%d", &M);
			for(int j = 1; j <= M; j++)
			{
				scanf("%d", &v);
				parent[v] = i;
				adj[i].push_back(v);
			}
		}
		int arr[MAX];
		scanf("%d", &Q);
		printf("Case %d:\n", test);
		while(Q--)
		{
			memset(arr, 0, sizeof(arr));
			int ans = 1;
			scanf("%d %d", &u, &v);
			while(parent[u] != -1)
			{
				arr[u] = 1;
				u = parent[u];
			}
			while(parent[v] != -1)
			{
				if(arr[v] == 1)
				{
					ans = v;
					break;
				}
				v = parent[v];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}