#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, Q; cin >> N >> Q;
    vector<int> A (N + 1); rep(i, 1, N + 1) cin >> A[i];
    map<int, vector<int>> M; M[0].push_back(0);
    rep(i, 1, N + 1){
        A[i] ^= A[i - 1];
        M[A[i]].push_back(i);
    }
    while (Q--){
        int l, r; cin >> l >> r;
        if (A[l - 1] == A[r]){
            cout << "YES\n";
            continue;
        }
        int s = *lower_bound(all(M[A[r]]), l);
        int t = *--lower_bound(all(M[A[l - 1]]), r);
        cout << (t > s ? "YES\n": "NO\n");
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
