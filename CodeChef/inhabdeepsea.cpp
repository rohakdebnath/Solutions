#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N, K; cin >> N >> K;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    i64 l = (K + 1) / 2, r = K - l;
    if (accumulate(all(A), 0LL) <= K){
        cout << N << '\n';
        return;
    }
    i64 sunk = 0;
    i64 j = 0;
    while(l){
        if (A[j] <= l){
            l -= A[j];
            ++j;
        } else {
            A[j] -= l;
            break;
        }
    }
    sunk += j;
    j = N - 1;
    while(r){
        if (A[j] <= r){
            r -= A[j];
            --j;
        } else {
            A[j] -= r;
            break;
        }
    }
    sunk += N - 1 - j;
    cout << sunk << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
