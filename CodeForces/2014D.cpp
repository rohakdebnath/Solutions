#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, d, k; cin >> n >> d >> k;
    vector<pair<int, int>> jobs(k);
    vector<int> l(k), r(k);
    for (auto &p: jobs){
        cin >> p.first >> p.second;
    }
    for (int i = 0; i < k; i++){
        l[i] = jobs[i].first;
        r[i] = jobs[i].second;
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int maxlap = -1, minlap = inf;
    int bro = 1, mom = 1;
    for(int s = 1; s <= n - d + 1; s++){
        int x = upper_bound(l.begin(), l.end(), s + d - 1) - l.begin();
        int y = lower_bound(r.begin(), r.end(), s) - r.begin();
        int overlap = x - y;
        if(overlap > maxlap){
            maxlap = overlap;
            bro = s;
        }
        if(overlap < minlap){
            minlap = overlap;
            mom = s;
        }
    }
    cout << bro << " " << mom << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
