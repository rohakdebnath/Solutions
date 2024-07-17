#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    int ans = 0;
    unordered_map<int, int> freq;
    rep(0, N)
    {
        int A; cin >> A;
        ++freq[A];
    }
    for (auto [u, v]: freq) ans += v % 2;
    cout << ans << '\n';
    return 0;
}
