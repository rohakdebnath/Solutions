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
    string t = "";
    int zeros = 0;
    int ones = 0;
    rep(i, 0, s.size())
    {
        if (s[i] == '0'){
            ++zeros;
            t += '1';
        }
        else{
            ++ones;
            t += '0';
        }
    } 
    int c = 0;
    rep(i, 0, t.size())
    {
        if (t[i] == '0' and zeros){
            ++c;
            --zeros;
        }
        else if (t[i] == '1' and ones){
            ++c;
            --ones;
        }
        else break;
    }
    cout << s.size() - c << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
