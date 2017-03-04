#include <iostream>
#include <set>
int m[5][5];

std::set<int> s;


int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void dfs( int y, int x, int cnt, int init )
{
    if ( cnt == 5 )
        init = m[y][x];
    else if ( cnt == 0 )
    {
        s.insert( init );
        return;
    }
    for ( int i = 0; i < 4; ++i )
    {
        int ny = y + dy[i], nx = x + dx[i];
        if ( ny >= 0 && nx >= 0 && ny < 5 && nx < 5 )
        {
            dfs( ny, nx, cnt - 1, init * 10 + m[ny][nx] );
        }
    }
}

int main()
{
    for ( int i = 0; i < 5; ++i )
        for ( int j = 0; j < 5; ++j )
            std::cin >> m[i][j];
    for ( int i = 0; i < 5; ++i )
        for ( int j = 0; j < 5; ++j )
            dfs( i, j, 5, 0 );
    std::cout << s.size() << std::endl;
    return 0;
}

