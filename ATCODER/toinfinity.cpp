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
    i64 K; cin >> K;
    int endof1 = 0;
    int i;
    for (i = 0; i < S.size(); ++i)
    {
        if (S[i] == '1') ++endof1;
        else break;
    }
    if (K <= endof1 or i == S.size()) cout << 1;
    else cout << S[i];
    cout << '\n';

    return 0;
}
