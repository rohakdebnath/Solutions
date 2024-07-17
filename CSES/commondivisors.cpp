#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> nums (1000001);
    rep(i, 0, N){
        int x; cin >> x;
        ++nums[x];
    }

    per(g, 1e6, 1){
        int ans = 0;
        for (int i = g; i <= 1e6; i += g) ans += nums[i];
        if (ans >= 2){
            cout << g << '\n';
            break;
        }
    }

    return 0;
}
