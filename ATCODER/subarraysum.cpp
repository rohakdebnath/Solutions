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
    int N, K, S; cin >> N >> K >> S;
    if (S < 1000000000)
    {   
        rep(0, K) cout << S << ' ';
        rep(0, N - K) cout << S + 1 << ' ';
    }
    else
    {
        rep(0, K) cout << S << ' ';
        rep(0, N - K) cout << S - 1 << ' ';
    }
    cout << '\n';
    return 0;
}
