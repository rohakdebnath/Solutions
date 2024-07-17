#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)

int compressedidx(vector<int>& C, int a){
    return lower_bound(all(C), a) - C.begin();
}

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<pair<int, int>> M;
    vector<int> cprs;
    rep(i, 0, N){
        int l, r; cin >> l >> r;
        M.push_back({l, r});
        cprs.push_back(l);
        cprs.push_back(r);
    }
    sort(all(cprs));
    cprs.erase(unique(all(cprs)), cprs.end());
    vector<int> diffa (2*N + 1);
    rep(i, 0, N){
        int l = compressedidx(cprs, M[i].first);
        int r = compressedidx(cprs, M[i].second);
        ++diffa[l];
        --diffa[r];
    }
    partial_sum(all(diffa), diffa.begin());
    cout << *max_element(all(diffa)) << '\n';
    return 0;
}
