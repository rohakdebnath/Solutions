#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI s (N); rep(0, N) cin >> s[i];
    sort(all(s));
    int sum = accumulate(all(s), 0);
    if (sum % 10 == 0)
    {
        rep(0, N)
        {
            if (s[i] % 10 != 0)
            {
                sum -= s[i];
                break;
            }
        }
    }
    cout << (sum % 10 == 0? 0 : sum) << '\n';

    return 0;
}
