#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<i64> A (N); 
    unordered_map<i64, i64> freq;
    rep(0, N)
    {
        i64 a; cin >> a;
        A[i] = a;
        ++freq[a];
    } 
    unordered_map<i64, i64> pick2same;
    for(auto [u, v] : freq) pick2same[u] = v*(v - 1)/2;
    i64 ans = 0LL;
    for(auto [u, v] : pick2same) ans += v;
    rep(0, N)
    {
        i64 ptclr = (freq[A[i]] - 1)*(freq[A[i]] - 2)/2 - freq[A[i]]*(freq[A[i]] - 1)/2;
        cout << ans + ptclr << '\n';
    }
    return 0;
}
