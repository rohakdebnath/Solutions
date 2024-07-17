#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> sums (100001);
    sums[0] = 1;
    rep(i, 0, N){
        per(j, 100000 - A[i], 0){
            if (sums[j]) sums[j + A[i]] += sums[j];
        }
    }

    int ans = accumulate(all(sums), 0, [] (int S, int i) {return S + (i != 0);}) - 1;
    cout << ans << '\n';
    rep(i, 1, 100001){
        if (sums[i]) cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
