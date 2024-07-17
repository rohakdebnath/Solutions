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
    i64 N, A, B; cin >> N >> A >> B;
    if (A > B)
    {
        cout << "0\n";
        return 0;
    }
    else cout << max(0LL, (B - A)*(N - 2) + 1) << '\n';
    return 0;
}
