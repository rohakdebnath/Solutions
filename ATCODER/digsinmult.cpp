#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 F(i64 a, i64 b){
    string A = to_string(a);
    string B = to_string(b);
    return max(A.size(), B.size());
}
int main()
{
    UNSYNC
    i64 N; cin >> N;
    i64 ans = INT32_MAX;
    for (i64 i = 1; i * i <= N; ++i){
        if (N % i == 0){
            ans = min(ans, F(i, N/i));
        }
    }
    cout << ans << '\n';
    return 0;
}
