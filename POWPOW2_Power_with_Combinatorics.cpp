#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
ll mul_inv(ll a, ll m) {
	int t, y = 0, x = 1, m0 = m, q;
	while (a > 1) {
		q = a / m;
		t = m;
		m = a % m;
		a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}
ll power(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}
void pre() {
	mul[0] = mul[1] = 1;
	for (int i = 2; i < N; ++i)
		mul[i] = (mul[i - 1] * i) % mod;
}
ll nCr (ll n_, ll r) {
	ll m = 500000002;
	if (r > n_) return 0;
	if (r == 0) return 1;
	ll a = mul[n_] % m;
	ll b = mul[r] % m;
	ll c = mul[n_- r] % m;
	b = (b * c) % m;
	c = (a * mul_inv(b, m)) % m;
	return c % mod;
}
ll chinese() {
	ll m = ;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &n);
	}
	return 0;
}