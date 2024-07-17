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
    int N; cin >> N;
    VI button (N + 1);
    vector<bool> lightened (N + 1);
    lightened[1] = true;
    rep(1, N + 1) cin >> button[i];
    int lin = 1;
    int moves = 0;
    while(true)
    {
        ++moves;
        if (button[lin] == 2) break;
        lin = button[lin];
        if (!lightened[lin]) lightened[lin] = true;
        else
        {
            cout << "-1\n";
            return 0;
        }
    }

    cout << moves << '\n';
    return 0;
}
