#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;

int A[100+10];
int C[100+10];

int dp[100000+10];

int main(int argc, char *argv[])
{
    while ( cin >> n >> m, n && m )
    {

        for ( int i = 0; i < n; ++i )
        {
            cin >> A[i];
        }
        for ( int i = 0; i < n; ++i )
        {
            cin >> C[i];
        }

        memset(dp, -1, sizeof(dp));
        dp[0] = 0;

        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j <= m; ++j )
            {
                if ( dp[j] >= 0 )
                    dp[j] = C[i];
                if ( j - A[i] >= 0)
                {
                    if ( dp[j - A[i]] > 0 )
                    {
                        dp[j] = max(dp[j], dp[j - A[i]] - 1);
                    }
                }
            }
        }

        int ans = 0;
        for ( int j = 1; j <= m; ++j )
        {
            if ( dp[j] > -1 )
                ans++;
        }
        cout << ans << endl;
    }
}
