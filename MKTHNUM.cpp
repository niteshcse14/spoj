#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector< pair<int, int> > A;
struct node
{
	node *left;
	node *right;
	int val;
	node(){}
	node(node *a, node *b,int c)
	{
		left = a;
		right = b;
		val = c;
	}
};
node *version[MAX];
void build(node *n, int low, int high)
{
	if(low == high)
	{
		n->val = 0;
		return;
	}
	int mid = (low + high) / 2;
	n->left = new node(NULL, NULL, 0);
	n->right = new node(NULL, NULL, 0);
	build(n->left, low, mid);
	build(n->right, mid + 1, high);
	n->val = n->left->val + n->right->val;
}
void upgrade(node *prev, node *curr, int low, int high, int idx)
{
	if(idx > high || idx < low)
	{
		return;
	}
	if(low == high)
	{
		curr->val = 1;
		return;
	}
	int mid = (low + high) / 2;
	if(idx <= mid)
	{
		curr->right = prev->right;
		curr->left = new node(NULL, NULL, 0);
		upgrade(prev->left, curr->left, low, mid, idx);
	}
	else
	{
		curr->left = prev->left;
		curr->right = new node(NULL, NULL, 0);
		upgrade(prev->right, curr->right, mid + 1, high, idx);
	}
	curr->val = curr->left->val + curr->right->val;
}
int query(node *n, int low, int high, int l, int r)
{
	if(l > high || r < low || low > high)
	{
		return 0;
	}
	if(l <= low && high <= r)
	{
		return n->val;
	}
	int mid = (low + high) / 2;
	int p1 = query(n->left, low, mid, l, r);
	int p2 = query(n->right, mid + 1, high, l, r);
	return p1 + p2;
}
int main()
{
	int data, l, r, k, N , Q;
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &data);
		A.push_back(make_pair(data, i));
	}
	sort(A.begin(), A.end());
	node *root = new node(NULL, NULL, 0);
	version[0] = root;
	build(root, 1, N);
	for(int i = 1; i <= N; i++)
	{
		version[i] = new node(NULL, NULL, 0);
		upgrade(version[i - 1], version[i], 1, N, A[i - 1].second);
	}
	while(Q--)
	{
		scanf("%d %d %d", &l, &r, &k);
		int a = 1;
		int b = N;
		int p = (a + b) / 2;
		while(b > (a + 1))
		{
			if(query(version[p], 1, N, l, r) < k)
			{
				a = p;
			}
			else
			{
				b = p;
			}
			p = (a + b) / 2;
		}
		if(query(version[a], 1, N, l, r) == k)
		{
			printf("%d\n", A[a - 1].first);
		}
		else
		{
			printf("%d\n", A[b - 1].first);
		}
	}
	return 0;
} 