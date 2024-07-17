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
    VI X (N); rep(0, N) cin >> X[i];
    VI t = X; sort(all(t));
    int m1 = t[N/2 - 1];
    int m2 = t[N/2];
    for(int i: X)
    {
        if (i <= m1) cout << m2 << '\n';
        else cout << m1 << '\n';
    }
    return 0;
}
