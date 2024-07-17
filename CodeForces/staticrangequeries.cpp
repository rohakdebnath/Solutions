#include <bits/stdc++.h> //simple to understand relatively and harder to implement because of the indexing error

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

VI specialidx;
i64 diffarray[400002]; //diffarray[i] represents the difference in "interval value" i and i - 1
i64 width[400002]; // length of ith interval
i64 value[400002]; //value of ith interval, can be calculated using pfx of diffarray
i64 pfsSpinterval[400002]; //pfx of special intervals 
pair<i64, i64> queries[100002]; 
pair<pair<i64, i64>, i64> updates[100002];
// O((N + Q)log(N + Q))
i64 compressedidx(i64 a){
    return lower_bound(all(specialidx), a) - specialidx.begin(); //crucial part which makes life easier
}
int main()
{
    UNSYNC
    i64 N, Q; cin >> N >> Q;
    for (i64 i = 0; i < N; i++) 
    {
		i64 l, r, v; cin >> l >> r >> v;
		specialidx.push_back(l);
		specialidx.push_back(r);
		updates[i] = {{l, r}, v};
	}
	for (i64 i = 0; i < Q; i++) 
    {
		i64 l, r; cin >> l >> r;
		specialidx.push_back(l);
		specialidx.push_back(r);
		queries[i] = {l, r};
	}
    sort(all(specialidx)); specialidx.erase(unique(all(specialidx)), specialidx.end()); //removes extra elements from a sorted list, remember this
    rep(i, 0, N)
    {
        auto x = updates[i];
        diffarray[compressedidx(x.first.first) + 1] += x.second; //one based indexing
        diffarray[compressedidx(x.first.second) + 1] -= x.second;
    }
    rep(i, 1, specialidx.size()) value[i] = value[i - 1] + diffarray[i];
    rep(i, 1, specialidx.size()) width[i] = specialidx[i] - specialidx[i - 1];
    rep(i, 1, specialidx.size()) pfsSpinterval[i] = pfsSpinterval[i - 1] + value[i]*width[i];

    rep(i, 0, Q) cout << pfsSpinterval[compressedidx(queries[i].second)] - pfsSpinterval[compressedidx(queries[i].first)] << '\n';
    return 0;
}
