#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define mp make_pair
#define sz(x) int((x).size())
const int INF = 2e9;
// const int MOD = ;

int M;
int timeDestroyed[330][330];
int T[330][330];

int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, 1, -1, 0};

int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    cin >> M;
    rep(i,330) rep(j,330) timeDestroyed[i][j] = INF;
    rep(hello,M){
        int x,y,t;
        cin >> x;
	cin >> y;
	cin >> t;
        rep(dir,5){
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if(xx >= 0 && yy >= 0){
                timeDestroyed[xx][yy] = min(timeDestroyed[xx][yy], t);
            }
        }
    }
    queue< pair<int,int> > Q;
    Q.push(mp(0,0));
    while(sz(Q)>0){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if(timeDestroyed[x][y] >= INF){
            cout << T[x][y] << endl;
            return 0;
        }
        rep(dir,4){
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if(xx >= 0 && yy >= 0 && (T[xx][yy] == 0) && (T[x][y] + 1 < timeDestroyed[xx][yy])){
                T[xx][yy] = T[x][y] + 1;
                Q.push(mp(xx,yy));
            }
        }
    }
    cout << -1 << endl;
}
