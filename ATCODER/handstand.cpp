#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N, K; cin >> N >> K;
    string s; cin >> s;
    vector<int> p, n;
    if (s[0] == '0') p.push_back(0);
    int j = 0;
    while(j < N){
        int a = 0, b = 0;
        while (s[j] != '0' and j < N) ++a, ++j;
        while (s[j] == '0' and j < N) ++b, ++j;
        if (a) p.push_back(a);
        if (b) n.push_back(b);
    }
    if (s[N - 1] == '0') p.push_back(0);
    int t = p.size();
    vector<int> pfp (t + 1); partial_sum(all(p), pfp.begin() + 1);
    vector<int> pfn (t); partial_sum(all(n), pfn.begin() + 1);
    int ans = 0;
    int z = min(K, t - 1);
    rep(i, z, t){
        ans = max(ans, pfn[i] - pfn[i - z] + pfp[i + 1] - pfp[i - z]);
    }
    cout << ans << '\n';
    return 0;
}
