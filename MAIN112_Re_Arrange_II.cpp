#include <bits/stdc++.h>
using namespace std;
int const maxn = 100;
struct node {
	int val;
	int cost;
};
node query[maxn];
int t, n, sum;
int cost[maxn], arr[maxn];
int cmp (node a, node b) {
	return a.val - b.val;
}
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &arr[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf ("%d", cost[i]);
		}
		for (int i = 0; i < n; ++i) {
			query[i].val = arr[i];
			query[i].cost = cost[i];
		}
		sum = 0;
		sort (query, query + n, cmp);
		for (int i = 1; i < n; ++i) {
			sum += abs (query[i].val - query[i - 1].val) * cost[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}