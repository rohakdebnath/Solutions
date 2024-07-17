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
    VI h (N); rep(0, N) cin >> h[i];
    int prev = 0;
    int sum = accumulate(all(h), 0, [&prev] (int currsum, int a) 
    {
        int diff = max(a - prev, 0);
        prev = a;
        return currsum + diff;
    });
    std::cout << sum << '\n';

    return 0;
}
