#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    deque<int> pref (N); pref[0] = 0;
    rep(i, 1, N)
    {
        pref[i] = pref[i - 1] + (S[i] == 'C' and S[i - 1] == 'A');
    }
    pref.push_front(0);
    rep(i, 0, Q)
    {
        int l, r; cin >> l >> r;
        int ans = pref[r] - pref[l - 1];
        if (l > 1 and S[l - 2] == 'A' and S[l - 1] == 'C') --ans;
        cout << ans << '\n';
    }
    return 0;
}
