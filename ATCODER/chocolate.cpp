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
    int N, D, X; cin >> N >> D >> X;
    int pieces = X;
    while(N--)
    {
        int c; cin >> c;
        int i = 0;
        while (1 + i*c <= D)
        {
            ++pieces;
            ++i;
        }
    }
    cout << pieces << '\n';
    return 0;
}
