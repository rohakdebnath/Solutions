#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int n, k, x; cin >> n >> k >> x;
    VI A(n); rep(i, 0, n) cin >> A[i];
    sort(all(A));
    VI pfA (n + 1); partial_sum(all(A), pfA.begin() + 1);
    int maxdiff = -INT32_MAX;
    per(i, n, n - k){
        maxdiff = max(maxdiff, 2*pfA[max(0, i - x)] - pfA[i]);
    }
    cout << maxdiff << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
