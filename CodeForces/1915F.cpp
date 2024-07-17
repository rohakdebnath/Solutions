#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

void solve()
{
    i64 N; cin >> N;
    vector<pair<i64, i64>> seg (N);
    rep(i, 0, N){
        cin >> seg[i].second >> seg[i].first;
    }
    sort(all(seg));
    ordered_set<i64> starts;
    i64 ans = 0; //have to count the number of pairs such that one is contained inside the other
    for (auto p: seg){
        ans +=  starts.size() - starts.order_of_key(p.second);
        starts.insert(p.second);
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
