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
    int tottim = 0;
    int maxdist = 0;
    rep(0, 5)
    {
        int A; cin >> A;
        tottim += (A % 10 ? (A/10 + 1)*10 : A);
        if (A % 10) maxdist = max(maxdist, 10 - A % 10);
    }

    cout << tottim - maxdist << '\n';
    return 0;
}
