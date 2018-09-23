#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T, N, temp;
bool pow_of_two(ll n)
{
	return (n && (!(n & (n - 1))));
}
int main()
{
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &N);
		printf("%lld\n", (ll)pow(2, log2(N)));
		/*
		temp = N;
		while(N > 1)
		{
			if(pow_of_two(N))
			{
				N -= (ll)pow(2, log2(N));
			}
		}
		*/
	}
	return 0;
}