#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 s = 2147483647;
void solve()
{
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));

    int groups = 0;
    int j = N - 1;
    for (int i = 0; i < N and i < j; ++i){
        while (A[i] + A[j] > s) --j;
        if (i < j and A[i] + A[j] == s) ++groups , --j;
    }
    cout << N - groups << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
