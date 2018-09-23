#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll arr[maxn];
ll prefix[maxn];
ll suffix[maxn];
ll seg[6 * maxn];
int n, m, a, b;
ll build(int ss, int se, int si) {
	if (se < ss) {
		return INT_MIN;
	}
	if (ss == se) {
		if (prefix[ss] > suffix[ss]) {
			if ((ss - 1) > 1) {
				seg[si] = prefix[ss] - prefix[ss - 1];
			}
			else {
				seg[si] = prefix[ss];
			}
		}
		else {
			if ((ss + 1) < n) {
				seg[si] = suffix[ss] - suffix[ss + 1];
			}
			else {
				seg[si] = suffix[ss];
			}
		}
		printf("%d  %d  %d  %d\n", ss, prefix[ss], suffix[ss], seg[si]);
		return seg[si];
	}
	ll mid = ss + (se - ss) / 2;
	ll left = build(ss, mid, 2 * si);
	ll right = build(mid + 1, se, 2 * si + 1);
	return (seg[si] = max(left, right));
}
ll query(ll x, ll y, ll ss, ll se, ll si) {
	if (ss > x || se < y || se < ss) {
		return INT_MIN;
	}
	if (ss >= x && se <= y) {
		return seg[si];
	}
	ll mid = ss + (se - ss) / 2;
	ll left = query(x, y, ss, mid, 2 * si);
	ll right = query(x, y, mid + 1, se, 2 * si + 1);
	return max(left, right);
}
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	prefix[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d  ", prefix[i]);
	}
	printf("\n");
	suffix[n] = arr[n];
	for (int i = n - 1; i > 0; --i) {
		suffix[i] = suffix[i + 1] + arr[i];
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d  ", suffix[i]);
	}
	printf("\n");
	build(1, n, 1);
	for (int i = 1; i <= 2 * n; ++i) {
		printf("%d  ", seg[i]);
	}
	printf("\n");
	scanf("%d", &m);
	while (m--) {
		scanf ("%d%d", &a, &b);
		printf("%d\n", query(a, b, 1, n, 1));
	}
	return 0;
}