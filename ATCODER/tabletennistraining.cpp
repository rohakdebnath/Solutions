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
    i64 N, A ,B; cin >> N >> A >> B;
    if ((A - B) % 2 == 0)
    {
        cout << abs(A - B)/2 << '\n';
    }
    else
    {
        cout << min(min(A - 1, B - 1) + 1 + (max(A, B) - 2 - min(A - 1, B - 1))/2, min(N - B, N - A) + 1 + (N - min(A, B) - min(N - A, N - B) - 1)/2) << '\n';
    }
    return 0;
}
