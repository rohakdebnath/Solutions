#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<i64> pregcd (N); inclusive_scan(all(A), pregcd.begin(), gcd<i64, i64>, 0);
    vector<i64> postgcd (N); inclusive_scan(rall(A), postgcd.rbegin(), gcd<i64, i64>, 0);
    vector<i64> d (N); d[0] = postgcd[1]; d[N - 1] = pregcd[N - 2];
    rep(i, 1, N - 1){
        d[i] = gcd(pregcd[i - 1], postgcd[i + 1]);
    }
    i64 ans = accumulate(all(d), 1LL, lcm<i64, i64>);
    cout << ans << '\n';
    return 0;
}
