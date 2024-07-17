#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    unordered_map<string, pair<int, int>> data;
    int N; cin >> N;
    rep(0, N)
    {
        string s; cin >> s;
        ++data[s].first;
    }
    int M; cin >> M;
    rep(0, M)
    {
        string s; cin >> s;
        --data[s].first;
    }
    int maxval = -INT32_MAX;
    for (auto [u, v]: data)
    {
        maxval = max(maxval, v.first - v.second);
    }
    cout << max(0, maxval) << '\n';
    return 0;
}
