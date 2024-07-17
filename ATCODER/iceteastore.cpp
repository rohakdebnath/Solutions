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
    i64 Q, H, S, D, N; cin >> Q >> H >> S >> D >> N;
    Q *= 4; H *= 2;
    i64 cost = (N/2)*min({2*Q, 2*H, 2*S, D}) + (N%2)*min({Q, H, S});
    cout << cost << '\n';
    return 0;
}
