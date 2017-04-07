
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define db(x) {cout << #x << " = " << (x) << endl;}
#define dba(a, x, y) {cout<<#a<<" :";FOR(i123,x,y)cout<<setw(4)<<(a)[i123];cout<<endl;}
#define clr(x) memset(x,0,sizeof(x));
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())

int N;
int A[400][400];
int dp[400][400];
int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    cin >> N;
    rep1(i,N){
        rep1(j,i){
            cin >> A[i][j];
        }
    }
    for(int row = N + 1; row >= 2; row--){
        for(int col = 1; col <= row; col++){
            dp[row-1][col] = max(dp[row-1][col], dp[row][col] + A[row-1][col]);
            dp[row-1][col-1] = max(dp[row-1][col-1], dp[row][col] + A[row-1][col-1]);
        }
    }
    cout << dp[1][1] << endl;

}
