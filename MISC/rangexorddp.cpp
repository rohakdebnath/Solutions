//Modification: In 2036F instead of 2^i we have any number x
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 a, b, g, k; cin >> a >> b >> g >> k; 
    bitset<64> x(a);
    string l = x.to_string();
    bitset<64> y(b);
    string r = y.to_string();

    i64 n = 64;

    vector ddp(n, vector(2, vector(2, vector<array<i64, 2>> (g, {-1, -1}))));

    auto dfs = [&](auto&& self, i64 i, i64 over, i64 under, i64 rem) -> array<i64, 2> {
        if (i == n) return {0, rem != k};
        
        auto& s = ddp[i][over][under][rem];
        if (s[1] != -1) return s;

        s = {0, 0};
        i64 o = over ? l[i] - '0' : 0;
        i64 u = under ? r[i] - '0' : 1;

        for (i64 d = o; d <= u; ++d) {
            int nrem = (rem + (d << (n - i - 1)) % g) % g;
            auto p = self(self, i + 1, over and (d == o), under and (d == u), nrem);
            
            if (d and p[1]) s[0] ^= (1LL << (n - 1 - i));
            s[0] ^= p[0];
            s[1] = (s[1] + p[1]) % 2;
        }

        return s;
    };

    cout << dfs(dfs, 0, 1, 1, 0)[0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
