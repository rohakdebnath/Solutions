#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int count = 0;
    auto is1100 = [&](int j) -> bool {
        return s[j] == '1' and s[j + 1] == '1' and s[j + 2] == '0' and s[j + 3] == '0';
    };
    for(int j = 0; j <= n - 4; ++j){
        if(is1100(j)) count++;
    }
    int q; cin >> q;
    while(q--){
        int i; char v; cin >> i >> v;
        int pos = i - 1; 
        if(s[pos] != v){
            for(int j = pos - 3; j <= pos; ++j){
                if(j >= 0 and j + 3 < n){
                    if(is1100(j)) count--;
                }
            }
            s[pos] = v;
            for (int j = pos - 3; j <= pos; ++j){
                if(j >= 0 and j + 3 < n){
                    if(is1100(j)) count++;
                }
            }
        }
        if (count > 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
