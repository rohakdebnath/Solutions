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
    string S; cin >> S;
    VI dp (N + 1);
    rep(0, N)
    {
        dp[i + 1] = dp[i] + (S[i] == 'I' ? 1 : -1);
    }
    cout << *max_element(all(dp)) << '\n';
    return 0;
}
