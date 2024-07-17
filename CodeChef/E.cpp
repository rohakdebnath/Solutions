#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int N; cin >> N;
    VI A (N); rep(0, N) cin >> A[i];
    VI firstappear (100001);
    rep(0, N)
    {
        if (!firstappear[A[i]]) firstappear[A[i]] = i + 1;
    }
    int maxel = *max_element(all(A));
    rep(0, N)
    {
        if (firstappear[A[i]] == i + 1) cout << A[i] << ' ';
        else cout << maxel << ' ';
    }
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
