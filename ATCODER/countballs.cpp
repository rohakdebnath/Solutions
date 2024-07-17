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
    i64 N, A, B; cin >> N >> A >> B;
    i64 reps = N/(A + B);
    i64 rem = N - reps*(A + B);

    cout << reps*A + min(rem, A) << '\n';
    return 0;
}
