#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int N; cin >> N;
    string a, b, c; cin >> a >> b >> c;
    int sfai = 0;
    rep(i, 0, N){
        if (c[i] == a[i] or c[i] == b[i]) ++sfai;
    }
    cout << (sfai == N ? "NO\n": "YES\n");

}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
