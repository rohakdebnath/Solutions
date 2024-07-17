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
    vector<i64> lucnums (87);
    lucnums[0] = 2;
    lucnums[1] = 1;
    for (int i = 2; i < N + 1; ++i)
    {
        lucnums[i] = lucnums[i - 1] + lucnums[i - 2];
    }
    cout << lucnums[N] << '\n';
    return 0;
}
