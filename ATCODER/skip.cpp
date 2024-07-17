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
    int N, X; cin >> N >> X;
    VI diffs (N);
    rep(0, N)
    {
        int x; cin >> x;
        diffs[i] = abs(X - x);
    }
    int g = accumulate(all(diffs), diffs[0], [&] (int a, int b) {return gcd(a, b);});
    cout << g << '\n';
    return 0;
}
