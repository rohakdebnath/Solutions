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
    VI A (N); rep(i, 0, N) cin >> A[i];
    VI nx (N); nx[N - 1] = N;
    per(i, N - 2, 0){
        nx[i] = A[i] == A[i + 1] ? nx[i + 1] : i + 1;
    }
    int Q; cin >> Q;
    while (Q--){
        int l, r; cin >> l >> r; --l;
        if (nx[l] < r){
            cout << l + 1 << ' ' << nx[l] + 1 << '\n';
        } else {
            cout << "-1 -1\n";
        }
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
