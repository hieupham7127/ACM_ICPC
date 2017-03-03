#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)

int W,H;
string field[25];
bool vis[25][25];

int dx[4]= {1, -1, 0, 0};
int dy[4]= {0, 0, -1, 1};

int dfs(int x, int y){
    if(vis[x][y]) return 0;
    vis[x][y] = true;
    int ans = 1;
    rep(dir,4){
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if(xx >= 0 && xx < H && yy >= 0 && yy < W && field[xx][yy] == '.'){
            ans += dfs(xx,yy);
        }
    }
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    while(1){
        cin >> W >> H;
        if( W == 0 && H == 0) break;
        rep(i,25) field[i] = "";
        rep(i,25) rep(j,25) vis[i][j] = false;

        rep(i,H){
            cin >> field[i];
        }
        rep(i,H){
            rep(j,W){
                if(field[i][j] == '@'){
                    cout << dfs(i,j) << endl;
                }
            }
        }
    }
}
