
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define mp make_pair
#define sz(x) int((x).size())
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
// const int MOD = ;

int N;
ll S;
ll C[10010];
ll Y[10010];
int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    cin >> N >> S;
    rep(i,N){
        cin >> C[i] >> Y[i];
    }
    ll cost = C[0] * Y[0];
    for(int i = 1; i < N; i++){
        ll mincost = C[i];
        rep(j,i){
            mincost = min(mincost, C[j] + (i-j)*S);
        }
        cost += mincost * Y[i];
    }
    cout << cost << endl;
}
