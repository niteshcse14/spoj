#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
typedef pair < int, int > PII;
vector < int > adj[maxn];
int t, n, j, m;
int visited[maxn];
int a[maxn][maxn], b[maxn][maxn];
typedef struct node {
	int tm;
	int val;
} node;
node ans[maxn];
void dfs (int u, int tm, int val, int lev = 1) {
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		if (!visited[adj[u][i]]) {
			dfs (adj[u][i], tm + a[u][adj[u][i]], val + b[u][adj[u][i]], lev + 1);
		}
	}
	if ((u == (n - 1)) && (lev == n) && (tm <= t)) {
		ans[j].tm = tm;
		ans[j++].val = val;
	}
	visited[u] = 0;
}
bool cmp (node a, node b) {
	if (a.val == b.val) {
		return a.tm < b.tm;
	}
	return a.val < b.val;
}
int main () {
	freopen ("in.txt", "r", stdin);
	memset (visited, 0, sizeof (visited));
	scanf ("%d%d", &n, &t);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf ("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf ("%d", &b[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			adj[i].push_back (j);
			adj[j].push_back (i);
		}
	}
	j = 0;
	dfs (0, 0, 0);
	sort (ans, ans + j, cmp);
	/*
	for (int i = 0; i < j; ++i) {
		printf("%d %d\n", ans[i].tm, ans[i].val);
	}
	*/
	scanf ("%d%d", &m, &n);
	printf("%d %d\n", ans[0].tm, ans[0].val);
	return 0;
}