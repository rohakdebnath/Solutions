#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s[0] = '(';
    int o = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') ++o;
        else if (s[i] == ')') ++c;
        else {
            if (o > c) {
                --o;
                s[i] = ')';
            } else {
                --c;
                s[i] = '(';
            }
        }
    }
    int cost = 0;
    vector<pair<char, int>> brak;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') brak.push_back({'(', i});
        else {
            cost += (i - brak.back().second);
            brak.pop_back();
        }
    }
    cout << cost << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
