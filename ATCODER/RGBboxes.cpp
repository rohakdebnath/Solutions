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
    int R, G, B, N; cin >> R >> G >> B >> N;
    int cases = 0;
    for (int i = 0; i <= N/R; ++i)
    {
        for(int j = 0; j <= N/G; ++j)
        {
            if ((N - i*R - j*G) % B == 0 and N - i*R - j*G >= 0) ++cases;
        }
    }
    cout << cases << '\n';
    return 0;
}
