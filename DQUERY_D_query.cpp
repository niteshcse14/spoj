#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 5;
typedef struct node {
	ll id;
	ll l;
	ll r;
} node;
node queries[maxn];
ll arr[maxn], ans[maxn], cnt[maxn];
ll t, n, q, k, a, b, block;
bool cmp (node a, node b) {
	if (a.l / block != b.l / block) {
		return a.l / block < b.l / block;
	}
	return a.r < b.r;
}
void query_result () {
	ll curr_l = 0, curr_r = 0, res = 0;
	for (ll i = 0; i < q; ++i) {
		ll l = queries[i].l;
		ll r = queries[i].r;
		while (curr_l < l) {
			cnt[arr[curr_l]]--;
			if (cnt[arr[curr_l]] == k - 1) {
				res -= 1;
			}
			curr_l++;
		}
		while (curr_l > l) {
			cnt[arr[curr_l - 1]]++;
			if (cnt[arr[curr_l - 1]] == k) {
				res += 1;
			}
			curr_l--;
		}
		while (curr_r <= r) {
			cnt[arr[curr_r]]++;
			if (cnt[arr[curr_r]] == k) {
				res += 1;
			}
			curr_r++;
		}
		while (curr_r > (r + 1)) {
			cnt[arr[curr_r - 1]]--;
			if (cnt[arr[curr_r - 1]] == k - 1) {
				res -= 1;
			}
			curr_r--;
		}
		ans[queries[i].id] = res;
	}
}
int main () {
	memset (ans, 0, sizeof (ans));
	memset (cnt, 0, sizeof (cnt));
	scanf ("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf ("%lld", &arr[i]);
	}
	k = 1;
	scanf ("%lld", &q);
	for (ll i = 0; i < q; ++i) {
		scanf ("%lld%lld", &a, &b);
		queries[i].id = i;
		queries[i].l = a - 1;
		queries[i].r = b - 1;
	}
	block = sqrt (n);
	sort (queries, queries + q, cmp);
	query_result();
	for (ll i = 0; i < q; ++i) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}