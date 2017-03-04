#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int d[401][401];
int m[401][401];

int dy[] = {1, -1, 0 ,0};
int dx[] = {0, 0, 1, -1};

int main(int argc, char *argv[])
{
    int M;
    cin >> M;
    memset( m, 0, sizeof(m) );
    for ( int i = 0; i < 401; ++i )
    {
        for ( int j = 0; j < 401; ++j )
        {
            d[i][j] = 1001;
        }
    }
    for ( int i = 0; i < M; ++i )
    {
        int x, y, t;
        cin >> x >> y >> t;
        d[y][x] = min( t, d[y][x] );
        for ( int i = 0; i < 4; ++i )
        {
            int ny = y + dy[i], nx = x + dx[i];
            if ( ny >= 0 && nx >= 0 )
            {
                d[ny][nx] = min( t, d[ny][nx] );
            }
        }
    }
    queue<pair<int, int> >Q;
    Q.push( make_pair( 0, 0 ) );
    while ( !Q.empty() )
    {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();
        if ( d[y][x] == 1001 )
        {
            cout << m[y][x] << endl;
            return 0;
        }
        else if ( d[y][x] <= m[y][x] )
        {
            continue;
        }
        for ( int i = 0; i < 4; ++i )
        {
            int ny = y + dy[i], nx = x + dx[i];
            if ( ny >= 0 && nx >= 0 &&
                 m[ny][nx] == 0 )
            {
                m[ny][nx] = m[y][x] + 1;
                Q.push( make_pair( ny, nx ) );
            }
        }
    }
    cout << -1 << endl;
}
