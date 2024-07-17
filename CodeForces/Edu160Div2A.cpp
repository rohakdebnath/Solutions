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

void solve()
{
    string s; cin >> s;
    rep(i, 1, s.size())
    {
        int a = stoi(s.substr(0, i));
        int b = stoi(s.substr(i, s.size() - i));
        if (s[i] != '0' and a < b)
        {
            cout << a << ' ' << b << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
