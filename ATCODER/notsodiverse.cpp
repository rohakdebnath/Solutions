#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N, K; cin >> N >> K;
    unordered_map <int, int> freq;
    rep(0, N)
    {
        int A; cin >> A;
        ++freq[A];
    }
    int cuts = max(0, sci(freq.size() - K));
    VI frevec;
    for (auto [u, v]: freq) frevec.emplace_back(v);
    sort(all(frevec));
    int totalcut = 0;
    rep(0, cuts) totalcut += frevec[i];
    cout << totalcut << '\n';
    return 0;
}
