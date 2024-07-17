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
    int D, N; cin >> D >> N;
    cout << (N == 100 ? 101 : N);
    if (D != 0) cout << (D == 1 ? "00" : "0000");
    cout << '\n';
    return 0;
}
