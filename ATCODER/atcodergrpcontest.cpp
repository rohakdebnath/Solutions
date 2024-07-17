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
    vector<i64> a (3*N); rep(0, 3*N) cin >> a[i];
    sort(all(a), [&](const int& a, const int& b) {return a > b;});
    i64 sum = 0;
    for(int i = 1; i <= 2*N; i += 2) sum += a[i];
    cout << sum << '\n';
    return 0;
}
