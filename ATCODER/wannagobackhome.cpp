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
    int N = 0, E = 0, S = 0, W = 0;
    for (char c: s)
    {
        if (c == 'N') ++N;
        else if (c == 'E') ++E;
        else if (c == 'W') ++W;
        else if (c == 'S') ++S;
    }
    if ((E and !W) or (!E and W) or (!N and S) or (N and !S)) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
