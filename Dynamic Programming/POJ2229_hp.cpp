#include <iostream>
#include <cmath>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ll long long

int n;
const int mod = 1000000000;
int arr[1000010][20];

int main() {
    cin >> n;
    int bound = log(n)/log(2);

    FOR( j, 0, bound )
        arr[0][j] = 1;

    rep1( i, n )
        FOR( j, 0, bound ) {
            arr[i][j] = (j > 0 ? arr[i][j-1] : 0);
            if ( (1 << j) <= i )
                arr[i][j] = (arr[i][j] + arr[i - (1 << j)][j]) % mod;
        }

    cout << arr[n][bound];
    return 0;
}
