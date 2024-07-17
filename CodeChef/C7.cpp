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
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

void solve()
{
    int N, K; cin >> N >> K;
    VI pre (K);
    int c = 1;
    per(i, K - 1, 0){
        pre[i] = c;
        c = c ^ 1;
    }
    VI suf (N - K);
    rep(i, 0, (N - K)/2 + ((N - K) & 1 and N & 1)) suf[i] = 1;

    if (N & 1 and K == N - 1){
        rep (i, 0, N) cout << i + 1 << ' ';
        cout << '\n';
        return;
    }
    int lastodd = 1;
    int lasteven = 2;
    for (int i : pre){
        if (i == 1){
            cout << lastodd << ' ';
            lastodd += 2;
        } else {
            cout << lasteven << ' ';
            lasteven += 2;
        }
    }
    for (int i : suf){
        if (i == 1){
            cout << lastodd << ' ';
            lastodd += 2;
        } else {
            cout << lasteven << ' ';
            lasteven += 2;
        }
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
