#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

i64 rockmax(i64 n){
    return (n*(n + 1))/2;
}
i64 rockprodparity(i64 n){
    if (n == 0) return 0;
    return ((n - 1)/2 + 1) % 2;
}

void solve()
{
    i64 A, B; cin >> A >> B;
    i64 diff = abs(A - B);
    i64 rock = (sqrtl(1 + 8*diff) - 1.0)/2.0;
    i64 ans = rock;
    if (rockmax(ans) < diff) ++ans;
    while (rockprodparity(ans) != diff % 2) ++ans;
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
