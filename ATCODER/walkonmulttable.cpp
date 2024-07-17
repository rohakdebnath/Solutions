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
    i64 N; cin >> N;
    i64 midN = sqrt(N);
    i64 minSum = N + 1;
    for(int i = 1; i <= midN; ++i)
    {
        if (N % i == 0)
        {
            minSum = min(minSum, i + N/i);
        }
    }
    cout << minSum - 2 << '\n';
    return 0;
}
