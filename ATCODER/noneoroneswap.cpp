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
    VI a (N); rep(0, N) cin >> a[i];
    VI b (N);
    iota(all(b), 1);
    int count = 0;
    rep(0, N) if (a[i] != b[i]) ++count;

    cout << (count > 2 ? "NO\n" : "YES\n");
    return 0;
}
