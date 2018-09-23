#include <bits/stdc++.h>
using namespace std;
void findLPS(string str, int n)
{
	if(n == 0)
	{
		return;
	}
	int N = 2 * n + 1;
	int max_time = 0;
	int L[N];
	int C = 1;
	int R = 2;
	int i = 0;
	int iMirror;
	int expand;
	int diff;
	int maxLPSLength = 0;
	int maxLPSCenterPosition = 0;
	int start = -1;
	int end = -1;
	for(i = 2; i < N; i++)
	{
		iMirror = 2 * C - i;
		expand = 0;
		diff = R - i;
		if(diff > 0)
		{
			if(L[iMirror] < diff)
			{
				L[i] = L[iMirror];
			}
			else if(L[iMirror] == diff && i == N - 1)
			{
				L[i] = L[iMirror];
			}
			else if(L[iMirror] == diff && i < N - 1)
			{
				expand = 1;
				L[i] = L[iMirror];
			}
			else if(L[iMirror] > diff)
			{
				L[i] = diff;
				expand = 1;
			}
		}
		else
		{
			expand = 1;
			L[i] = 0;
		}
		if(expand == 1)
		{
			while(((i + L[i]) < N && (i - L[i]) > 0) && (((i + L[i] + 1) % 2 == 0) || (str[(i + L[i] + 1) / 2] == str[(i - L[i] - 1) / 2])))
			{
				L[i]++;
			}
		}
		if(L[i] > maxLPSLength)
		{
			maxLPSLength = L[i];
			maxLPSCenterPosition = i;
		}
		if((i + L[i]) > R)
		{
			C = i;
			R = i + L[i];
		}
	}
	if(maxLPSLength == 1)
	{
		max_time = n;
	}
	else
	{
		for(i = 2; i < N; i++)
		{
			if(maxLPSLength == L[i])
			{
				max_time++;
			}
		}
	}
	cout << maxLPSLength << " " << max_time << "\n";
}
int main()
{
	int T;
	string str;
	cin >> T;
	while(T--)
	{
		cin >> str;
		findLPS(str, str.length());
	}
	return 0;
}