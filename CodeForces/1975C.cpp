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
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    if (N == 2){
        cout << min(A[0], A[1]) << '\n';
        return;
    }
    vector<int> meds;
    rep(i, 1, N - 1){
        vector<int> t = {A[i - 1], A[i], A[i + 1]}; sort(all(t));
        meds.push_back(t[1]);
    }
    cout << accumulate(all(meds), 0, [&] (int i, int r) {return max(r, i);}) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
