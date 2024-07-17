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
    VI lower (26);
    bool Cloc = false;
    bool totLower = false;
    bool iniA = (S[0] == 'A');

    for (int i = 0; i < S.size(); ++i)
    {
        if (i >= 2 and i <= S.size() - 2 and S[i] == 'C') Cloc = true;
        if (S[i] - 'a' >= 0 and S[i] - 'a' < 26) ++lower[S[i] - 'a'];
    }
    if (accumulate(all(lower), 0) == S.size() - 2) totLower = true;

    if (Cloc and iniA and totLower)
    {
        cout << "AC\n";
    }
    else cout << "WA\n";
    return 0;
}
