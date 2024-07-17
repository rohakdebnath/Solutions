#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<int> A; 
int N, K; 
int ans = INT32_MAX;

void dfs(string s = "0"){
    if (s.size() > to_string(N).size() + 2) return;
    int i = stoi(s);
    if (i >= N) ans = min(ans, i);
    rep(t, 0, 10 - K){
        dfs(s + char(A[t] + '0'));
    }
}
int main()
{
    UNSYNC
    cin >> N >> K;
    A.resize(10); iota(all(A), 0);
    rep(i, 0, K) {
        int x; cin >> x;
        A.erase(find(all(A), x));
    }
    dfs();
    cout << ans << '\n';
    return 0;
}
