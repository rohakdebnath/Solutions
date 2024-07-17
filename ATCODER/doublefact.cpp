#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

i64 pow(i64 N, i64 P){
    i64 ans = 0;
    while (N/P){
        ans += N/P;
        N /= P;
    }
    return ans;
}
int main()
{
    UNSYNC
    i64 N; cin >> N;
    if (N & 1){
        cout << 0 << '\n';
    } else {
        cout << pow(N/2, 5LL) << '\n';
    }
    return 0;
}
