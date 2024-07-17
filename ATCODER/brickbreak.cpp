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
    VI a (N); rep(0, N) cin >> a[i];
    int ptr = 1;
    for (int i = 1; i <= N; ++i) if (a[i - 1] == ptr) ++ptr;
    cout << (ptr == 1 ? -1 : (N - ptr + 1));
    cout << '\n';
    return 0;
}
