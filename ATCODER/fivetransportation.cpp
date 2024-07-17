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
    i64 N, A, B, C, D, E; cin >> N >> A >> B >> C >> D >> E;
    cout << 4 + (N - 1)/(min({A, B, C, D, E})) + 1;
    return 0;
}
