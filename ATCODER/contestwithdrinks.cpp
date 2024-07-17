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
    int totsum = 0;
    VI time (N);
    rep(0, N)
    {
        int t; cin >> t;
        time[i] = t;
        totsum += t; 
    }
    int M; cin >> M;
    while(M--)
    {
        int P, X; cin >> P >> X;
        cout << totsum + X - time[P - 1] << '\n';
    }
    return 0;
}
