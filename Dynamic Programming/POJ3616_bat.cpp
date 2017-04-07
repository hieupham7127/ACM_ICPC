
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

struct Interval{
    int s,e,c;
    Interval() {};
    Interval(int ss, int ee, int cc): s(ss), e(ee), c(cc){};

    bool operator < (const Interval& i2) const
    {
        return e < i2.e;
    }
};

int N, M, R;
Interval I[1010];
int dp[1010]; // dp[i] = Max C to get at the end of i-th interval
int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    cin >> N >> M >> R;
    rep1(i,M){
        cin >> I[i].s >> I[i].e >> I[i].c;
        I[i].e = min(N, I[i].e + R);
    }
    sort(I+1, I+M + 1);
    dp[1] = I[1].c;
    int ans = 0;
    for(int i = 2; i <= M; i++){
        dp[i] = I[i].c;
        for(int j = 1; j < i; j++){
            if(I[j].e <= I[i].s){
                dp[i] = max(dp[i], dp[j] + I[i].c);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

}
