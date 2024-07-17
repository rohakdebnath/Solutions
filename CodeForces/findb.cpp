#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N, Q; cin >> N >> Q;
    vector<i64> A (N);
    vector<i64> mina (N);
    rep(i, 0, N){
        cin >> A[i];
        if (A[i] == 1) mina[i] = 2;
        else mina[i] = 1;
    }

    vector<i64> psA (N + 1), psmina (N + 1);
    partial_sum(all(A), psA.begin() + 1);
    partial_sum(all(mina), psmina.begin() + 1);

    rep(i, 0, Q){
        i64 l, r; cin >> l >> r;
        if (psA[r] - psA[l - 1] < psmina[r] - psmina[l - 1] or r == l) cout << "No\n";
        else cout << "Yes\n";
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
