#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 summ(i64 i, i64 x){
    return 1LL* (2*i - x + 1) * x / 2;
}

void solve()
{
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<i64> pfA (N + 1); partial_sum(all(A), pfA.begin() + 1);
    i64 Q; cin >> Q;
    while(Q--){
        i64 l, u; cin >> l >> u; --l;
        i64 j = lower_bound(l + 1 + all(pfA), pfA[l] + u) - pfA.begin();
        i64 r = -1;
        i64 ans = -INT32_MAX;
        if (j <= N){
            if (summ(u, pfA[j] - pfA[l]) > ans){
                ans = summ(u, pfA[j] - pfA[l]);
                r = j;
            }
        }
        if (j > l + 1){
            if (summ(u, pfA[j - 1] - pfA[l]) >= ans){
                ans = summ(u, pfA[j - 1] - pfA[l]);
                r = j - 1; 
            }
        }
        cout << r << " \n"[Q == 0];
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
