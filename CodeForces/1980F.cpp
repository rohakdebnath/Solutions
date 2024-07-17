#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N, M, K; cin >> N >> M >> K;
    map<i64, priority_queue<i64>> MP;
    vector<pair<i64, i64>> V (K);
    rep(i, 0, K){
        i64 y, x; cin >> y >> x;
        MP[x].push(y);
        V[i] = {x, y};
    }
    i64 ans = N * M;
    map<pair<i64, i64>, bool> C;
    vector<int> fin;
    i64 x = 0, y = 0;
    for (auto [u, v]: MP){
        if (!x) x = u - 1;
        ans -= (u - x - 1) * y;
        if (v.top() > y){
            y = v.top();
            C[{u, y}] = 1;
        }
        x = u;
        ans -= y;
    }
    ans -= (M - x) * y;
    cout << ans << '\n';
    rep(i, 0, K){
        if (!C[V[i]]) cout << "1 ";

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
