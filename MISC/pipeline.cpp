#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

i64 N, K; 
i64 sumoflast(i64 m){
    return (K - 1)*(K)/2 - (K - 1 - m)*(K - m)/2;
}

int main()
{
    UNSYNC
    cin >> N >> K;
    --N;
    i64 l = -1, r = K;
    while (r - l > 1){
        i64 m = l + (r - l)/2;
        if (N <= sumoflast(m)){
            r = m;
        } else {
            l = m;
        }
    }
    cout << (r == K? -1 : r) << '\n';
    return 0;
}
