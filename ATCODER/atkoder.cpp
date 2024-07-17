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
    int longestacgt = 0;
    int acgt = 0;
    for(char c: s)
    {
        if (c == 'A' or c == 'C' or c == 'G' or c == 'T')
        {
            ++acgt;
            longestacgt = max(longestacgt, acgt);
        } 
        else acgt = 0;
    }
    cout << longestacgt << '\n';
    return 0;
}
