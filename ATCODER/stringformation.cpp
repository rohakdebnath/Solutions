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
    string S; cin >> S;
    deque<char> ss (all(S));
    int Q; cin >> Q;
    int flips = 0;
    rep(0, Q)
    {
        int T; cin >> T;
        if (T == 1) ++flips;
        else
        {
            int F; cin >> F;
            char C; cin >> C;
            if ((flips + F) % 2 == 1) ss.push_front(C);
            else ss.push_back(C);
        }
    }
    if (flips % 2) reverse(all(ss));
    string sf (all(ss));
    cout << sf << '\n';
    return 0;
}
