#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int N; cin >> N;
    vector<string> S[6];
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        S[s.size()].push_back(s);
    }
    i64 ans = 0;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            if ((i + j) % 2) continue;
            vector<i64> p (91); //p[i] number of strings with sum of prefix of l / 2 = i;
            int l = (i + j) / 2;
            for (string s: S[i]){
                int t = 45;
                for (int n = 0; n < s.size(); ++n) {
                    if (n < l) t += s[n] - '0';
                    else t -= s[n] - '0';
                }
                ++p[t];
            }
            for (string s: S[j]){
                int t = 45;
                for (int n = 0; n < s.size(); ++n) {
                    if (n + i >= l) t += s[n] - '0';
                    else t -= s[n] - '0';
                }
                ans += p[t];
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
