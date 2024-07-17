#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>
const int MOD = 1e9 + 7;

int main()
{
    UNSYNC
    int N; cin >> N;
    i64 power = 1;
    for (int i = 1; i <= N; ++i)
    {
        power = (power * i) % MOD;
    }
    cout << power << '\n';
    return 0;
}
