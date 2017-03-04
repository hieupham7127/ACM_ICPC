#include <iostream>
#include <algorithm>
#include <math.h>

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
typedef long long ll;
typedef long double ld;
const int INF = 2e9;
const ld pi = acos(-1);
// const int MOD = ;

int N, T;
pair<ll,ll> shift[25050];
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    cin >> N >> T;
	// Sort by increasing l, increasing r
    rep(i,N){
        cin >> shift[i].first;
        cin >> shift[i].second;
    }
    sort(shift,shift+N);
	// keep track of curend = last day of the last cow, curmax = how far current cows can reach. Choose max.
    ll curend = 0, curmax = -INF, cnt = 0;
    rep(i,N){
        ll l = shift[i].first;
        ll r = shift[i].second;
        if (l <= curend + 1) {
            curmax = max(curmax, r);
        }else{
            if(curmax == -INF){
                cout << -1 << endl;
                return 0;
            }else{
                curend = curmax;
                curmax = -INF;
                cnt++;
                if(curend >= T){
                    break;
                }
                i--;
            }
        }
        if(curmax >= T){
            cout << cnt + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
