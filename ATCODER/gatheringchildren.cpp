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

int main()
{
    UNSYNC
    string s; cin >> s;
    int N = s.size();

    int pos = N - 1;
    VI nearestL (N);
    per(i, N - 2, 0){
        if (s[i] == 'L'){
            pos = i;
        } else {
            nearestL[i] = pos;
        }
    }
    pos = 0;
    VI nearestR (N);
    rep(i, 1, N){
        if (s[i] == 'R'){
            pos = i;
        } else {
            nearestR[i] = pos;
        }
    }

    VI final (N);
    rep(i, 0, N){
        int ans;
        if (s[i] == 'R'){
            ans = nearestL[i] - i;
            if (ans & 1){
                ++final[nearestL[i] - 1];
            } else {
                ++final[nearestL[i]];
            }
        } else {
            ans = i - nearestR[i];
            if (ans & 1){
                ++final[nearestR[i] + 1];
            } else {
                ++final[nearestR[i]];
            }
        }
    }
    for (int i : final) cout << i << ' ';
    cout << '\n';
    return 0;
}
