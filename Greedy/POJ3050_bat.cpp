
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

vector<int> field[6];
set<string> S;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int depth, string chars){
    if(x < 0 || y < 0 || x >= 5 || y >= 5) return;
    depth++;
    chars += (char) field[x][y];
    if(depth == 6){
        S.insert(chars);
        return;
    }
    rep(dir,4){
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        dfs(xx, yy, depth, chars);
    }

}

int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    rep(i,5){
        rep(j,5){
            int k; cin >> k;
            field[i].pb(k);
        }
    }
    rep(i,5){
        rep(j,5){
            string s = "";
            dfs(i,j,0,s);
        }
    }
    cout << sz(S) << endl;
}
