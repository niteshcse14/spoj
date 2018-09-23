#include <bits/stdc++.h>
using namespace std;
#define root 0
#define N 10100
#define LN 14
vector < int > adj[N], costs[N], indexx[N];
int ptr, chainNo, ans;
int baseArray[N];
int posInBase[N], chainInd[N], chain_heads[N], depth[N], subsize[N];
int st[6 * N], qt[6 * N];
int otherEnd[N], pa[LN][N];
void make_tree(int si, int s, int e) {
	if(s == e-1) {
		st[si] = baseArray[s];
		return;
	}
	int c1 = (si<<1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[si] = st[c1] > st[c2] ? st[c1] : st[c2];
}
/*
void update_tree(int si, int ss, int se, int x, int val){
	if(ss > x || x >= se){
		return;
	}
	if(ss == x && ss == se - 1){
		st[si] = val;
		return;
	}
	int c1 = (si << 1), c2 = c1 | 1, m =  (ss + se) >> 1;
	update_tree(c1, ss, m, x, val);
	update_tree(c2, m, se, x, val);
	st[si] = max(st[c1], st[c2]);
}
*/
int query_tree(int si, int ss, int se, int qs, int qe){
	if(ss >= qe || se <= qs){
		return -1;
	}
	if(ss >= qs && se <= qe){
		return st[si];
	}
	int c1 = (si << 1), c2 = c1 | 1, m =  (ss + se) >> 1;
	return (query_tree(c1, ss, m, qs, qe) + query_tree(c2, m, se, qs, qe));
}
int query_up(int u, int v){
	int uchain, vchain = chainInd[v];
	while(1){
		uchain = chainInd[u];
		if(uchain == vchain){
			if(u == v){
				break;
			}
			else{
				ans += query_tree(1, 0, ptr, posInBase[v] + 1, posInBase[u] + 1);
				cout << "if  " << ans << "\n";
			}
			break;
		}
		ans += query_tree(1, 0, ptr, posInBase[chain_heads[uchain]], posInBase[u] + 1);
		u = pa[0][chain_heads[uchain]];
		cout << "else  " << ans << "\n";
	}
	return ans;
}
int LCA(int u, int v){
	if(depth[u] < depth[v]){
		swap(u, v);
	}
	int diff = depth[u] - depth[v];
	for(int i = 0; i < LN; ++i){
		if((diff >> i) & 1){
			u = pa[i][u];
		}
	}
	if(u == v){
		return u;
	}
	for(int i = LN - 1; i >= 0; --i){
		if(pa[i][u] != pa[i][v]){
			u = pa[i][u];
			v = pa[i][v];
		}
	}
	return pa[0][u];
}
void query(int u, int v) {
	int lca = LCA(u, v);
	int ans = query_up(u, lca); // One part of path
	int temp = query_up(v, lca); // another part of path
	if(temp > ans) ans = temp; // take the maximum of both paths
	printf("%d\n", ans);
}
/*
void change(int i, int val){
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}
*/
void HLD(int curr, int cost, int prev){
	if(chain_heads[chainNo] == -1){
		chain_heads[chainNo] = curr;
	}
	chainInd[curr] = chainNo;
	posInBase[curr] = ptr;
	baseArray[ptr++] = cost;
	int sc = -1, ncost;
	for(int i = 0; i < adj[curr].size(); ++i){
		if(adj[curr][i] != prev){
			if(sc == -1 || subsize[sc] < subsize[adj[curr][i]]){
				sc = adj[curr][i];
				ncost = costs[curr][i];
			}
		}
	}
	if(sc != -1){
		HLD(sc, ncost, curr);
	}
	for(int i = 0; i < adj[curr].size(); ++i){
		if(adj[curr][i] != prev){
			if(adj[curr][i] != sc){
				chainNo++;
				HLD(adj[curr][i], costs[curr][i], curr);
			}
		}
	}
}
void dfs(int curr, int prev, int dep = 0){
	depth[curr] = dep;
	subsize[curr] = 1;
	pa[0][curr] = prev;
	for(int i = 0; i < adj[curr].size(); ++i){
		if(adj[curr][i] != prev){
			otherEnd[indexx[curr][i]] = adj[curr][i];
			dfs(adj[curr][i], curr, dep + 1);
			subsize[curr] += subsize[adj[curr][i]];
		}
	}
}

int main() {
	int t;
	scanf("%d ", &t);
	while(t--) {
		ptr = 0;
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chain_heads[i] = -1;
			for(int j=0; j<LN; j++) pa[j][i] = -1;
		}
		for(int i=1; i<n; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			u--; v--;
			adj[u].push_back(v);
			costs[u].push_back(c);
			indexx[u].push_back(i-1);
			adj[v].push_back(u);
			costs[v].push_back(c);
			indexx[v].push_back(i-1);
		}
		chainNo = 0;
		dfs(root, -1);
		HLD(root, -1, -1); 
		make_tree(1, 0, ptr);
		for(int i=1; i<LN; i++){
			for(int j=0; j<n; j++){
				if(pa[i-1][j] != -1){
					pa[i][j] = pa[i-1][pa[i-1][j]];
				}
			}
		}
		while(1) {
			char s[100];
			scanf("%s", s);
			if(s[1]=='O') {
				break;
			}
			int a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='K') {
				query(a - 1, b - 1);
			} else {
				query(a - 1, b - 1);
			}
		}
	}
}