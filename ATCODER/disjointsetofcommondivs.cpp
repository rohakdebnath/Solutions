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
    i64 A, B; cin >> A >> B;
    i64 g = gcd(A, B);
    int ans = 1;
    for (i64 i = 2; i * i <= g; ++i){
        if (g % i == 0) ++ans;
        while (g % i == 0) g /= i;
    }
    if (g > 1) ans += 1;
    cout << ans << '\n';

    return 0;
}
