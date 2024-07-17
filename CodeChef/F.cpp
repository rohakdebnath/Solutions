#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 N; cin >> N;
    bool hunted = false;
    i64 ini = 1LL;
    for (i64 i = 0; i < 32; ++i)
    {
        if (ini == N)
        {
            hunted = true;
            break;
        }
        ini *= 2LL;
    }
    if (hunted)
    {
        cout << "-1\n";
        return;
    }
    if (N % 2LL)
    {
        cout << 1 << ' ' << 1 << ' ' << (N - 1LL)/2 << '\n';
    }
    else 
    {
        i64 powsof2 = 0LL;
        while (N % 2 == 0LL)
        {
            N /= 2LL;
            ++powsof2;
        }
        i64 l = 1LL;
        rep(0, powsof2 - 1) l*= 2LL;
        cout << l*2LL << ' ' << l*2LL << ' ' << (N - 1LL)*l << '\n';
    }

}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
