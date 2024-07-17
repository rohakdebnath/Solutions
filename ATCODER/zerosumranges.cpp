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
    map<i64, i64> sum; sum[0] = 1;
    i64 ans = 0;
    i64 s = 0;
    rep(i, 0, N){
        s += A[i];
        ans += sum[s];
        ++sum[s];
    }
    cout << ans << '\n';
    return 0;
}
