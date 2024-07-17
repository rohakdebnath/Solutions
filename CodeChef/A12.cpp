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
    string S; cin >> S;
    int cnt = 0;
    int maxcount = 0;
    rep(i, 0, N){
        if (i > 0 and S[i - 1] == '1') cnt = 0;
        if (S[i] == '0') ++cnt, maxcount = max(maxcount, cnt);
    }
    cout << count(all(S), '1') + maxcount << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
