#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
    i64 ans = 0;
    auto check = [&] (i64 d){
        if (d < N / d - 1) ans += N / d - 1;
    };

    for (i64 i = 1; i * i < N; ++i){
        if (N % i == 0){
            check(i);
        }
    }
    cout << ans << '\n';
    return 0;
}
