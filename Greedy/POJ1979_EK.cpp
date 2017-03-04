#include <vector>
#include <iostream>
using namespace std;

int W,H;
char m[22][22];

int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};

int dfs( int y, int x )
{
    if ( y < 0 || x < 0 || y >= H || x >= W )
    {
        return 0;
    }
    int total = 0;
    if ( m[y][x] == '#' )
        return 0;
    else if ( m[y][x] == '.' || m[y][x] == '@' )
    {
        m[y][x] = '#';
        total = 1;
        for ( int i = 0; i < 5; ++i )
        {
            total += dfs( y+dy[i], x+dx[i] );
        }
    }
    return total;
}

int main(int argc, char *argv[])
{
    while( cin >> W >> H, W && H )
    {
        int sy, sx;
        for ( int i = 0; i < H; ++i )
        {
            for ( int j = 0; j < W; ++j )
            {
                cin >> m[i][j];
                if ( m[i][j] == '@' )
                {
                    sy = i;
                    sx = j;
                }
            }
        }
        cout << dfs( sy, sx ) << endl;
    }
}
