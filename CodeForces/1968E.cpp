#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    vector<pair<int, int>> ans;
    ans.push_back({1, 1});
    ans.push_back({1, 2});
    rep(i, 3, N + 1){
        ans.push_back({i, i});
    }
    for (auto[u, v] : ans){
        cout << u << ' ' << v << '\n';
    }
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
