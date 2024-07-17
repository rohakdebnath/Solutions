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
    rep(i, 0, N - 4){
        string t = S.substr(i, 5);
        if (t == "mapie") S[i + 2] = 'x', ++cnt;
    }
    rep(i, 0, N - 2){
        string t = S.substr(i, 3);
        if (t == "map" or t == "pie") ++cnt;
    }
    cout << cnt << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
