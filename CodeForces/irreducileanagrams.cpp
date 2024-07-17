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

int main()
{
    UNSYNC
    string S; cin >> S;
    int Q; cin >> Q;
    int N = S.size();
    VVI alpha (N + 1, VI (26));
    rep(i, 1, N + 1)
    {
        alpha[i] = alpha[i - 1];
        ++alpha[i][S[i - 1] - 'a'];
    }
    while(Q--)
    {
        int l, r; cin >> l >> r;
        int count = 0;
        rep(i, 0, 26) count += (alpha[r][i] - alpha[l - 1][i] > 0);
        if (l == r or count >= 3 or S[l - 1] != S[r - 1]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
