#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

pair<int, int> reduce (const pair<int, int>& p){
    int g = gcd(p.first, p.second);
    return {p.first/g, p.second/g};
}

void solve()
{
    int N; cin >> N;
    string s; cin >> s;
    map<pair<int, int>, int> ratio;
    vector<int> ans (N);
    int D = 0, K = 0;
    rep(i, 0, N){
        D += s[i] == 'D';
        K += s[i] == 'K';
        ans[i] = 1 + ratio[reduce({D, K})];
        ++ratio[reduce({D, K})];
    }
    rep(i, 0, N) cout << ans[i] << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
