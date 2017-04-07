#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[350+10][350+10];
int d[350+10][350+10];

int main(int argc, char *argv[])
{
    int N;
    cin >> N;

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 1; j <= i; ++j )
        {
            cin >> d[i][j];
        }
    }

    int ans = 0;
    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 1; j <= i; ++j )
        {
            if ( i == 0 )
            {
                dp[i][j] = d[i][j];
            }
            else
            {
                if ( j > 0 )
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + d[i][j];
                else
                    dp[i][j] = dp[i-1][j] + d[i][j];
            }
            if ( i == N )
                ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << endl;
}
