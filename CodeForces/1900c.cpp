#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

const int MX = 3e5 + 1;
int L[MX], R[MX];
string S;

int dfs(int s){
    int ans = INT32_MAX;
    if (L[s] == -1 and R[s] == -1) return 0;

    if (L[s] != -1){
        ans = min(ans, dfs(L[s]) + (S[s] != 'L'));
    }
    if (R[s] != -1){
        ans = min(ans, dfs(R[s]) + (S[s] != 'R'));
    }
    return ans;
}

void solve()
{
    int N; cin >> N;
    cin >> S;
    rep(i, 0, N){
        cin >> L[i] >> R[i]; --L[i], --R[i];
    }
    cout << dfs(0) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
