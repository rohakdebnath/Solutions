#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    string s; cin >> s;
    vector<char> final;
    int killb = 0, killB = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        bool normal = true;
        if (s[i] == 'b')
        {
            ++killb;
            normal = false;
        }
        else if (s[i] == 'B') 
        {
            ++killB;
            normal = false;
        }
        if (killb and s[i] - 'a' >= 0 and s[i] - 'a' < 26 and s[i] != 'b') --killb;
        else if (killB and s[i] - 'A' >= 0 and s[i] - 'A' < 26 and s[i] != 'B') --killB;
        else if (normal) final.push_back(s[i]);
    }
    reverse(all(final));
    for(char c: final) cout << c;
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
