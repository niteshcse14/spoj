#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
int t, n, k;
int inp[maxn];
struct node {
	int lc, rc;
	node *left, *right;
	node() : lc(0), rc(0), left(NULL), right(NULL){};
};
node *insert(node *root, int val, int level) {
	if (level == -1) return root;
	int x = (val >> level) & 1;
	if (x) {
		root->rc++;
		if (root->right == NULL)
			root->right = new node();
		root->right = insert(root->right, val, level - 1);
	}
	else {
		root->lc++;
		if (!root->left)
			root->left = new node();
		root->left = insert(root->left, val, level - 1);
	}
	return root;
}
int query(node *root, int pre_xor,int level) {
	if (level == -1 || root == NULL) return 0;
	int x = (pre_xor >> level) & 1;
	int y = (k >> level) & 1;
	if (y) {
		if (x == 0)
			return root->lc + query(root->right, pre_xor, level - 1);
		else return root->rc + query(root->left, pre_xor, level - 1);
	}
	else {
		if (x == 0)	return query(root->left, pre_xor, level - 1);
		else return query(root->right, pre_xor, level - 1);
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) 
			scanf("%d", &inp[i]);
		node *root = new node();
		insert(root, 0, 20);
		long long int res = 0;
		int pre = 0;
		for (int i = 0; i < n; ++i) {
			pre ^= inp[i];
			res += query(root, pre, 20);
			root = insert(root, pre, 20);
		}
		printf("%lld\n", res);
	}
	return 0;
}
/*
#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;
int T, N, K, A[100010];
LL calc(int X, int mask) {
    map<int,int> mp;
    LL ans = 0;
    mp[0] = 1;
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum ^= A[i];
        ans += mp[(sum ^ X) & mask];
        mp[sum & mask]++;
    }
    return ans;
}
int main() {
    scanf("%d", &T);
    for (;T--;) {
        scanf("%d%d", &N, &K);
        for (int i=0; i<N; i++) 
        	scanf("%d", A+i);
        LL ans = 0;
        int X = 0, mask = 0;
        for (int i=4; i>=0; i--) {
            mask |= 1<<i;
            if (K & (1<<i)) {
                ans += calc(X, mask);
                X |= 1<<i;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
*/