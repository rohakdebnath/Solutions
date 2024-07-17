//Order of Replacements dont matter, try it for two (B, C) pairs and the same logic can be extended to show the order is irrelevant.
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

int main()
{
    UNSYNC
    int N, M; cin >> N >> M;
    VI A (N); rep(i, 0, N) cin >> A[i]; sort(all(A));
    vector<pair<int, int>> B (M);
    rep(i, 0, M){
        cin >> B[i].second >> B[i].first;
    }
    sort(all(B)); reverse(all(B));
    VI D (N); 
    int j = 0;
    rep(i, 0, M){ //Using 2P to build D, the replacement numbers laid out in decresing order
        while (B[i].second and j < N){
            D[j] = B[i].first;
            --B[i].second;
            ++j;
        }
    }
    i64 ans = 0;
    rep(i, 0, N){
        ans += max(A[i], D[i]);
    }
    cout << ans << '\n';
    return 0;
}
