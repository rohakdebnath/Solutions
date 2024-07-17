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
    int n; cin >> n;
    VI a (n); rep(0, n) cin >> a[i];
    deque<int> b;
    rep(0, n)
    {
        if (i % 2) b.push_back(a[i]);
        else b.push_front(a[i]);
    }
    if (n % 2 == 0) reverse(all(b));
    for(int i: b) cout << i << ' ';
    cout << '\n';
    return 0;
}
