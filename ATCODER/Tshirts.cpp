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
    int N, M; cin >> N >> M;
    string S; cin >> S;
    int wP = M, wL = 0, L = 0, P = M;
    for (char c: S)
    {
        if (c == '1')
        {
            if (wP) --wP;
            else if (wL) --wL;
            else ++L;
        }
        else if (c == '2')
        {
            if (wL) --wL;
            else ++L;
        }
        else
        {
            wL = L;
            wP = P;
        }
    }
    cout << L << '\n';

    return 0;
}
