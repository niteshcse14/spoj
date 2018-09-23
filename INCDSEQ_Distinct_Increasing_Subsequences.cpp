#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 5000000;
const ll MAXN = 100005;
const ll MAXK  = 55;
ll dp[MAXK][MAXN];
ll arr[MAXN];
ll temp[MAXN];
ll N, K;
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
	ll n = 1;
	scanf("%lld %lld", &N, &K);
	for(ll i = 0; i < N; i++)
	{
		scanf("%lld", &temp[i]);
	}
	arr[0] = temp[0];
	for(ll i = 1; i < N; i++)
	{
		if(temp[i - 1] != temp[i])
		{
			arr[n++] = temp[i] % MOD;
		}
	}
	N = n;
	update(1, arr[0], 1);
	for(ll i = 1; i < N; i++)
	{
		ll x = arr[i];
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