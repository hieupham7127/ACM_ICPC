#include <iostream>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define ll long long

int main()
{
    int n;
    ll s, c, y;
    cin >> n >> s;
    
    ll res = 0;
    // maxC = 5000, this guarantees the first c is always chosen
    ll minC = 5001, pos = 1;
    rep(i, n) {
        cin >> c >> y;
        /* 
         * variables: 
         *  minC = ci
         *  c = cj
         *  pos = (j - i)
         * 
         * PSEU-DO CODE:
         *  if cj is chosen
         *      cost = cj * y
         *  else 
         *      cost = ci * y + s * (j - i) * y
         */
        if (minC + s * pos >= c) {
            minC = c;             
            pos = 0;
        }
        
        res += minC * y + s * pos * y;
        pos++;
    }
	
    cout << res << endl;
    return 0;
}	
