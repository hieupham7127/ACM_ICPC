#include <iostream>
#include <algorithm>
#include <utility>

int W, H;
int m[22][22];

int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};

int ans = 20;

void dfs( int y, int x, int cnt )
{
    if ( cnt == 11 )
        return;
    for ( int i = 0; i < 4; ++i )
    {
        int ny = y, nx = x;
        while ( true )
        {
            if ( !( ny + dy[i] >= 0 && ny + dy[i] < H &&
                 nx + dx[i] >= 0 && nx + dx[i] < W ) )
                goto skip;
            if ( m[ny + dy[i]][nx + dx[i]] == 1 )
            {
                if ( ny == y && nx == x )
                    break;
                m[ny + dy[i]][nx + dx[i]] = 0;
                dfs( ny, nx, cnt + 1 );
                m[ny + dy[i]][nx + dx[i]] = 1;
                break;
            }
            ny += dy[i];
            nx += dx[i];
            // std::cout << ny << " " << nx << std::endl;
            if ( m[ny][nx] == 3 ) {
                ans = std::min( ans, cnt );
                return;
            }
        }
skip:;
    }
}

int main()
{
    while ( std::cin >> W >> H, W && H )
    {
        ans = 20;
        int sy, sx;
        for ( int i = 0; i < H; ++i )
        {
            for ( int j = 0; j < W; ++j )
            {
                std::cin >> m[i][j];
                if ( m[i][j] == 2 )
                {
                    sy = i;
                    sx = j;
                }
            }
        }
        dfs( sy, sx, 1 );
        std::cout << ( ( ans == 20 ) ? -1 : ans ) << std::endl;
    }
    return 0;
}

