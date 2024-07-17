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
    VI l (N), r (N), c (N);
    rep(i, 0, N) cin >> l[i]; sort(all(l));
    rep(i, 0, N) cin >> r[i]; sort(all(r));
    rep(i, 0, N) cin >> c[i]; sort(all(c));

    int j = 0;
    VI diffs;
    priority_queue<int> validleft;
    rep(i, 0, N){
        while (l[j] < r[i] and j < N){
            validleft.push(l[j]);
            ++j;
        }
        diffs.push_back(r[i] - validleft.top());
        validleft.pop();
    }
    sort(all(diffs), greater<int> ());
    i64 ans = 0;
    rep(i, 0, N){
        ans += diffs[i]*c[i];
    }
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
