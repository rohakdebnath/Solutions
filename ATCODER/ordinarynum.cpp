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
    VI p (n); rep(0, n) cin >> p[i];
    int count = 0;

    for (int i = 1; i < n - 1; ++i)
    {
        if ((p[i] > p[i - 1] and p[i] < p[i + 1]) or (p[i] < p[i - 1] and p[i] > p[i + 1])) ++count;
    }
    cout << count << '\n';
    return 0;
}
