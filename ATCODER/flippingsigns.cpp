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
    int N; cin >> N;
    i64 ans = 0;
    int countneg = 0;
    i64 mini = INT32_MAX;
    rep(i, 0, N){
        i64 num; cin >> num;
        if (num < 0) ++countneg;
        mini = min(mini, abs(num));
        ans += abs(num);
    }
    ans += countneg & 1 ? -2*mini : 0;
    cout << ans << '\n';
    return 0;
}
