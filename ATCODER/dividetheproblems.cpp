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
    VI d (N); rep(0, N) cin >> d[i];

    if (N % 2)
    {
        cout << 0 << '\n';
        return 0;
    }
    sort(all(d));
    cout << d[N/2] - d[N/2 - 1] << '\n';
    return 0;
}
