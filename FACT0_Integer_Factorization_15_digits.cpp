#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 6;
int isPrime[maxn], prime[maxn];
ll prime_size, n;
void init() {
	for (int i = 2; i * i <= maxn; ++i) {
		if (isPrime[i] == 0) {
			for (int j = i * i; j <= maxn; j += i) {
				isPrime[j] = 1;
			}
		}
	}
	for (int i = 2; i < maxn; ++i) {
		if (isPrime[i] == 0) {
			prime[prime_size++] = i;
		}
	}
}
int main() {
	prime_size = 0;
	memset(isPrime, 0, sizeof(isPrime));
	init();
	while (1) {
		scanf ("%lld", &n);
		if (n == 0) {
			break;
		}
		for (int i = 0; i < prime_size && n > 1; ++i) {
			ll exponent = 0;
			while (n % prime[i] == 0) {
				n /= prime[i];
				exponent++;
			}
			if (exponent > 0) {
				printf("%lld^%lld ", prime[i], exponent);
			}
		}
		if (n > 1) {
			printf("%lld^%lld ", n, 1);
		}
		printf("\n");
	}
	return 0;
}