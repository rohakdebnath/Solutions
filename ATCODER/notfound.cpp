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
    VI lexi (26);
    for(char c: S)
    {
        ++lexi[c - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (lexi[i] == 0)
        {
            cout << static_cast<char>('a' + i) << '\n';
            return 0;
        }
    }
    cout << "None\n";
    return 0;
}
