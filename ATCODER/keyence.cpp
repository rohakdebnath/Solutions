#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    string S; cin >> S;
    for(int i = 0; i < S.size(); ++i)
    {
        for (int j = i; j < S.size(); ++j)
        {
            if (S.substr(0, i) + S.substr(j, S.size() - j) == "keyence")
            {
                cout << "YES\n";
                return 0;
            }
        }
    } 
    cout << "NO\n";
    return 0;
}
