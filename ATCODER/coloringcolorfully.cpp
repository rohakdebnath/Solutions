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
    int ooob = 0, ooow = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        if ((S[i] == '1' and (i % 2 == 0)) or (S[i] == '0' and (i % 2))) ++ooob;
        if ((S[i] == '0' and (i % 2 == 0)) or (S[i] == '1' and (i % 2))) ++ooow;
    }

    cout << min(ooob, ooow) << '\n';
    return 0;
}
