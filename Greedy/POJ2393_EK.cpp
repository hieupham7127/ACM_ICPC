#include <iostream>
#include <algorithm>
int N, S;

int main()
{
    std::cin >> N >> S;
    long long n, y;
    std::cin >> n >> y;
    long long last = n;
    long long ans = n * y;
    for ( int i = 1; i < N; ++i )
    {
        std::cin >> n >> y;
        last = std::min( last + S, n );
        ans += last * y;
    }
    std::cout << ans << std::endl;
    return 0;
}

