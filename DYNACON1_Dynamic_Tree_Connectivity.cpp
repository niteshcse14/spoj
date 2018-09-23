#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > adj[maxn];
int n, q;
char ch[5];
bool dfs(int u, int v, bool visited[]){
	if(u == v){
		return true;
	}
	visited[u] = true;
	vector < int > :: iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
		if((*itr) > -1 && !visited[*itr]){
			dfs(*itr, v, visited);
		}
	}
	visited[u] = false;
	return false;
}
int main(){
	scanf("%d%d", &n, &q);
	while(q--){
		scanf("%s", ch);
		if(ch[0] == 'a'){
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		else if(ch[0] == 'r'){
			scanf("%d%d", &u, &v);
			adj[u][v] = -1;
		}
		else if(ch[0] == 'c'){
			scanf("%d%d", &u, &v);
			bool visited[maxn];
			for(int i = 0; i < maxn; ++i){
				visited[i] = false;
			}
			if(dfs(u, v, visited)){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}