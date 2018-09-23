#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n;
struct node {
	int x, y;
	node () : x(0), y(0) {};
};
node inp[maxn];
node pt;
int cross_product(node p, node q, node r) {
	return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}
int dist(node p) {
	return p.x * p.x + p.y * p.y;
}
bool cmp(node a, node b) {
	int ori = cross_product(pt, a, b);
	if (ori == 0)
		return dist(a) < dist(b);
	return ori < 0;
}
int main() {
	pt.x = pt.y = INT_MAX;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &inp[i].x, &inp[i].y);
		if (pt.x >= inp[i].x) {
			if (pt.y > inp[i].y) {
				pt.x = inp[i].x;
				pt.y = inp[i].y;
			}
		}
	}
	sort(inp, inp + n, cmp);
	printf("After sorting %d %d\n", pt.x, pt.y);
	for (int i = 0; i < n; ++i) {
		printf("%d  %d\n", inp[i].x, inp[i].y);
	}
	return 0;
}