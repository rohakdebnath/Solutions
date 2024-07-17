#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int N; cin >> N;
    vector<pair<int, int>> A (N); 
    rep(i, 0, N){
        int x; cin >> x;
        A[i] = {x, i};
    } 
    VI ans (N);
    stack<pair<int, int>> prevgind; prevgind.push({INT32_MAX, -1});
    rep(i, 0, N){
        while (prevgind.top().first <= A[i].first){
            prevgind.pop();
        }
        ans[i] = i - prevgind.top().second;
        prevgind.push(A[i]);
    }
    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
