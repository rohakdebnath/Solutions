#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    priority_queue<i64> maxHeap;
    rep(i, 0, N){
        i64 A; cin >> A;
        maxHeap.push(A);
    }

    while (M){
        i64 t = maxHeap.top();
        maxHeap.pop();
        maxHeap.push(t/2);
        --M;
    }
    i64 ans = 0;
    while (!maxHeap.empty()){
        ans += maxHeap.top();
        maxHeap.pop();
    }
    cout << ans << '\n';
    return 0;
}
