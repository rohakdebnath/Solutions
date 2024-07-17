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
    string s; cin >> s;
    i64 N = s.size() - 1;
    i64 ptr = N;
    i64 moves = 0;
    for (i64 i = N; i >= 0; --i)
    {
        if (s[i] == 'B')
        {
            moves += ptr - i;
            --ptr;
        }
    }
    cout << moves << '\n';
    return 0;
}
