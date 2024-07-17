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
    int N; cin >> N;
    VI X(N), Y(N);
    rep(0, N) cin >> X[i];
    rep(0, N) cin >> Y[i];

    int profit = 0;
    rep(0, N) profit += max(0, X[i] - Y[i]);

    cout << profit << '\n';
    return 0;
}
