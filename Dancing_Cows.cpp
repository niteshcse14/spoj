#include <bits/stdc++.h>
using namespace std;
#define ll long long int
long long int bulls[5001], cow[5001];
long long int dp[5001][5001];
int main()
{
    ll N, M, sum = 0;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> bulls[i];
    }
    for(int i = 1; i <= M; i++)
    {
        cin >> cow[i];
    }
    sort(bulls, bulls + N + 1);
    sort(cow, cow + M + 1);
    for(int i = 0; i <= N; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= M; i++)
    {
        dp[i][0] = 9999999999999;
    }
    for(int i = 1; i <= N; i++)
    {
        printf("%d     ", i);
        for(int j = 1; j <= M; j++)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(bulls[i] - cow[j]));
            cout << dp[i][j] << " ";
        }
        printf("\n");
    }
    cout << dp[N][M] << "\n";
    return 0;
}