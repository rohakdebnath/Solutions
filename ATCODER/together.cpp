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
    int N; cin >> N;
    VI A (100000); 
    rep(0, N) 
    {
        int a; cin >> a;
        ++A[a];
    }
    int maxlen = 0;
    for (int i = 1; i < 99999; ++i)
    {
        maxlen = max(maxlen, A[i - 1] + A[i] + A[i + 1]);
    }
    cout << maxlen << '\n';   
    return 0;
}
