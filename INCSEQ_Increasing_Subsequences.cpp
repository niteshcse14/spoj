#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAXN = 100005;
const ll MAXK = 55;
const ll MOD = 5000000;
ll dp[MAXK][MAXN];
ll arr[MAXN];
void update(ll K, ll index, ll val)
{
	index += 1;
	while(index < MAXN)
	{
		dp[K][index] += val;
		dp[K][index] %= MOD;
		index += index & (-index);
	}
}
ll getVal(ll K, ll index)
{
	ll sum = 0;
	while(index > 0)
	{
		sum += dp[K][index];
		sum %= MOD;
		index -= index & (-index);
	}
	return sum % MOD;
}
int main()
{
	ll N, K;
	scanf("%lld %lld", &N, &K);
	for(ll i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	update(1, arr[0], 1);
	for(ll i = 1; i < N; i++)
	{
		ll x = arr[i] % MOD;
		update(1, x, 1);
		for(ll j = 1; j < K; j++)
		{
			ll y = getVal(j, x) % MOD;
			update(j + 1, x, y);
		}
	}
	printf("%lld\n", getVal(K, MAXN) % MOD);
	return 0;
}