#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N, M; cin >> N >> M;
    VI X (M); rep(0, M) cin >> X[i];
    sort(all(X));
    int prev = X[0];
    VI diffs;
    transform(1 + all(X), back_inserter(diffs), [&prev] (int a) 
    {
        int diff = a - prev;
        prev = a;
        return diff;
    });
    sort(all(diffs));
    int moves = 0;
    rep(0, M - N) moves += diffs[i];
    cout << moves << '\n';
    return 0;
}
