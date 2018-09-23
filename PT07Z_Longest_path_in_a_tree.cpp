#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
int n, a, b;
int ans , node = 0, len = 0;
vector < int > adj[maxn];
int visited[maxn];
void dfs(int u, int len) {
        visited[u] = 1;
        vector < int > :: iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {
                if(visited[*itr] == 0) {
                        dfs(*itr, len + 1);
                }
        }
        //printf("%d  %d\n", u, len);
        if(len > ans) {
                ans = len;
                node = u;
        }
}
int main() {
        freopen("in.txt", "r", stdin);
        memset(visited, 0, sizeof(visited));
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i) {
                scanf("%d%d", &a, &b);
                adj[a].push_back(b);
                adj[b].push_back(a);
        }
        ans = -9999;
        dfs(1, 0);
        ans = -1;
        len = 0;
        memset(visited, 0, sizeof(visited));
        //printf("node  =  %d\n", node);
        dfs(node, 0);
        printf("%d\n", ans);
        return 0;
}
