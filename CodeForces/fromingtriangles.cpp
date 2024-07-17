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

void solve()
{
    i64 N; cin >> N;
    map<i64, i64> freq;
    rep(i, 0, N){
        i64 x; cin >> x;
        ++freq[x];
    }
    VI sfq;
    for(auto [u, v]: freq){
        sfq.push_back(v);
    }
    i64 ans = 0;
    VI pfS (sfq.size() + 1); partial_sum(all(sfq), pfS.begin() + 1);
    per(i, sfq.size() - 1, 0){
        if (sfq[i] >= 3){
            ans += (sfq[i]*(sfq[i] - 1)*(sfq[i] - 2))/6;
        }
        if (sfq[i] >= 2){
            ans += (sfq[i]*(sfq[i] - 1))/2*pfS[i];
        }
    }
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
