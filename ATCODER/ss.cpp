#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    string S; cin >> S;
    int maxlen = 0;
    for(int i = 0; i < S.size(); ++i)
    {
        for(int j = i + 1; j < S.size(); j += 2)
        {
            if (i == 0 and j == S.size() - 1) continue;
            int hl = (j - i + 1)/2;
            if (S.substr(i, hl) == S.substr(i + hl, hl)) maxlen = max(maxlen, 2*hl);
        }
    }
    cout << maxlen << '\n';
    return 0;
}
