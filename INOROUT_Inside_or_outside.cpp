#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long int
ll n, q, l, r, mid, len;
struct node {
	ll x, y;
};
node inp[maxn];
node pt;
ll orinetation(node a, node b, node c) {
	ll a_ = (b.y - a.y) * (c.x - b.x);
	ll b_ = (b.x - a.x) * (c.y - b.y);
	return a_ - b_;
}
int main() {
	scanf("%lld%lld", &n, &q);
	for (ll i = 0; i < n; ++i)
		scanf("%lld%lld", &inp[i].x, &inp[i].y);
	while (q--) {
		scanf("%lld%lld", &pt.x, &pt.y);
		l = 1;
		r = n;
		while (l < r) {
			mid = (l + r) / 2;
			ll ori = orinetation(inp[0], inp[mid], pt);
			if (ori < 0) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		ll x = orinetation(inp[0], inp[n - 1], pt);
		ll y = orinetation(inp[l - 1], inp[l], pt);
		if (x < 0 || y > 0) 
			printf("F\n");
		else printf("D\n");
	}
	return 0;
}