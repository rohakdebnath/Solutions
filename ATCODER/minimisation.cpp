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
    int n,k;
    cin >> n >> k;
    VI a (n); rep(0, n) cin >> a[i];

    int ans=(n-2)/(k-1)+ 1;
    cout <<ans<<'\n';
    return 0;
}
