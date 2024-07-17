#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    map<int, int> freq;
    int countof1or2 = 0;
    i64 ans = 0;
    rep(i, 0, N){
        if (A[i] == 1 or A[i] == 2){
            ++countof1or2;
            continue;
        }
        ans += freq[A[i]];
        ++freq[A[i]];
    }
    ans += ((countof1or2*1LL)*(countof1or2 - 1))/2;
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
