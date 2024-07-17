#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()

void solve() {
    int N; cin >> N;
    vector<int> A (N); for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> nd (N, N);
    for (int i = N - 2; i >= 0; --i) {
        if (A[i] != A[i + 1]) nd[i] = i + 1;
        else nd[i] = nd[i + 1];
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r;
        --l, --r;
        int j = nd[l];
        if (j > r){
            cout << "-1 -1\n";
        } else {
            cout << l + 1 << ' ' << j + 1 << '\n';
        }
    }
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
