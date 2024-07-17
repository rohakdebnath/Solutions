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
    int s; cin >> s;
    VI A (1e6); A[s] = 1;
    int re = 1;
    while(true)
    {
        if (s % 2) s = 3*s + 1;
        else s /= 2;
        if (!A[s])
        {
            ++A[s];
            ++re;
        }
        else break;
    }
    cout << re + 1 << '\n';
    return 0;
}
