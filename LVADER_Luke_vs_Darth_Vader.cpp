#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 200008;
ll dp[maxn];
#define mod 1000000007
ll modex(ll x, ll n){
	if(n == 0){
		return 1;
	}
	ll t = modex(x, n / 2);
	if(n % 2 == 0){
		return (t * t) % mod;
	}
	else{
		return (((t * t) % mod) * x) % mod;
	}
}
ll binomial(ll n, ll r){
	ll x = dp[n];
	ll y = dp[r];
	y *= dp[n - r];
	y %= mod;
	y = modex(y, mod - 2);
	x *= y;
	x %= mod;
	return x;
}
int main(){
	dp[0] = 1;
	for(ll i = 1; i < 200004; ++i){
		dp[i] = dp[i - 1] * i;
		dp[i] %= mod;
	}
	ll t, ans = 0, x1, x2, y1, y2;
	scanf("%lld", &t);
	for(ll ii = 1; ii <= t; ++ii){
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		ll m = x2 - x1;
		ll n = y2 - y1;
		ans = 0;
		for(ll i = 0; i <= min(n, m); i++){
			ll a = binomial(n + m - i, n);
			ll b = binomial(n, i);
			a *= b;
			a %= mod;
			ans += a;
			ans %= mod;
		}
		printf("Case %lld: %lld\n", ii, ans);
	}
	return 0;
}