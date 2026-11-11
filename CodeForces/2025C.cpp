#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<pair<int, int>> uniq;
    uniq.emplace_back(a[0], 1);
    for(int i = 1; i < n; i++) {
        if(a[i] == uniq.back().first) {
            uniq.back().second++;
        } else {
            uniq.emplace_back(a[i], 1);
        }
    }

    int m = uniq.size();
    int i = 0;
    i64 curr = uniq[0].second;
    i64 ans = curr;
    for(int j = 1; j < m; j++) {
        if (uniq[j].first - uniq[j - 1].first <= 1){
            curr += uniq[j].second;
        } else{
            i = j;
            curr = uniq[j].second;
        }
        while(uniq[j].first - uniq[i].first > (k - 1)){
            curr -= uniq[i].second;
            i++;
        }
        ans = max(ans, curr);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
