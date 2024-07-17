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
    double N, T, A; cin >> N >> T >> A;
    double mindiff = INT32_MAX;
    double pos = -1;

    rep(0, N)
    {
        double H; cin >> H;
        if (mindiff > abs(A - (T - H*0.006)))
        {
            mindiff = abs(A - (T - H*0.006));
            pos = i + 1; 
        }
    }
    cout << pos << '\n';
    return 0;
}
