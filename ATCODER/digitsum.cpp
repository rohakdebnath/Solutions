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
    int sum = 0;
    rep(0, S.size())
    {
        sum += S[i] - '0';
    }
    cout << max(sum, sci(S[0] - '0' - 1 + 9*(S.size() - 1))) << '\n';
    return 0;
}
