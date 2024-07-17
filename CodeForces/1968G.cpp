#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<int> zfunc(string& s){
    int N = s.size();
    vector<int> z (N);
    z[0] = N;
    int l = 0, r = 0;
    rep(i, 1, N){
        if (i < r){
            z[i] = min<int>(r - i, z[i - l]);
        }
        while(z[i] + i < N and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve()
{
    int N, L, R; cin >> N >> L >> R;
    string s; cin >> s;
    vector<int> z = zfunc(s);
    vector<vector<int>> v (N + 1);
    set<int> ind;
    rep(i, 0, N) v[z[i]].push_back(i), ind.insert(i);

    vector<int> md (N + 1); //max divisions for i length common prefix
    rep(l, 1, N + 1){
        for (int i: v[l - 1]) ind.erase(i);
        int ans = 1, x = 0;
        while (true){
            auto it = ind.lower_bound(x + l);
            if (it == ind.end()) break;
            x = *it;
            ++ans;
        }
        md[l] = ans;
    }
    int len = N;
    rep(d, L, R + 1){
        while (len > 0 and md[len] < d) --len;
        cout << len << " \n"[d == R];
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
