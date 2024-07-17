#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 n, m; cin >> n >> m;
    i64 N = n + m + 1;
    vector<i64> a (N), b (N), ans (N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];

    i64 x = 0, y = 0, s = 0, t = 0;
    while (x < n and y < m){ //it is worth noticing that removing any one canditate essentially fixes the hirings. Also worth noticing that one of the group always has to fill first. 
    // We can proceed by removing any other canditate than the members of the first group, in which case if we simply assume that all of the other members belong to the other group then removing any one of them doesnt change the hiring order,but merely the total strength, which we can find by doing net strength - removed guy's strength
    // Removing any of the member of the first group creates a slightly different order of selection, but it is the same for all the removals of members of the first group. So we can try to find this order and then iterate over the first group members and remove their strngths at each iteration.
        if (a[t] > b[t]){
            s += a[t];
            ++x;
        } else {
            s += b[t];
            ++y;
        }
        ++t;
    }
    i64 r = s;
    rep(i, t, N){
        s += (x == n ? b[i] : a[i]);
    }
    rep(i, t, N){
        ans[i] = s - (x == n ? b[i] : a[i]);
    }
    rep(i, 0, t){
        if ((x == n) == (b[i] > a[i])) ans[i] = s - max(a[i], b[i]); //lets say we fully hired the programmers, then while filling the programmers, the testers we picked, if removed will have been selected later because we are conditioned to pick an extra of whatever is not filled first
    }

    i64 oldx = x, oldt = t;
    x == n ? --x : --y; // we want to see what will happen if we removed each of the members of the group which is completed first, there is only one other valid configuration after each of the first recruited group's member is removed, and it same for all such removals, so --x and fix the configurations

    while (x < n and y < m){
        if (a[t] > b[t]){
            r += a[t];
            ++x;
        } else {
            r += b[t];
            ++y;
        }
        ++t;
    }
    rep(i, t, N){
        r += (x == n ? b[i] : a[i]);
    }
    rep(i, 0, oldt){
        if ((oldx == n) == (b[i] < a[i])) ans[i] = r - max(a[i], b[i]); // remove the members of the firstly completed group at each iteration
    }
    rep(i, 0, N) cout << ans[i] << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
