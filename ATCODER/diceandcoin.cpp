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
    int N, K; cin >> N >> K;
    double tot = 0;
    for (int i = 1; i <= N; ++i)
    {
        int n = 0;
        while ((1 << n)* i < K) ++n;
        tot += 1.0/N / pow(2, n);
    }

    cout << setprecision (10) << tot << '\n';
    return 0;
}
