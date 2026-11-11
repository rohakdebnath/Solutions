#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

bool ask(string&& s) {
    cout << "? " << s << endl;
    bool b; cin >> b;
    return b;
}

void solve() {
    int n; cin >> n;
    string ans = "";
    //pref
    while (ans.size() < n){
        if(ask("0" + ans)){
            ans = "0" + ans;
            continue;
        }
        if(ask("1" + ans)){
            ans = "1" + ans;
            continue;
        }
        break;
    }
    //suff
    while(ans.size() < n){
        if(ask(ans + "0")){
            ans = ans + "0";
        } else {
            ans = ans + "1";
        }
    }
    cout << "! " << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
