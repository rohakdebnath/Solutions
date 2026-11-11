#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<string> p {"Male", "Female"};

string ask (int x) {
    cout << x << endl;
    string r; cin >> r;
    return r;
}

void solve() {
    int n; cin >> n;
    string init = ask(0);
    if (init == "Vacant") return;
    else {
        if (init == "Female") reverse(p.begin(), p.end());
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        string s = ask(m);
        if (s == "Vacant") return;
        if (s == p[m % 2]) l = m;
        else r = m;
    }
    ask(l);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}


