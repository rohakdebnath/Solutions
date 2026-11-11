#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int maximizeTransactions(vector<int> transaction) {
    i64 sum = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int x: transaction) {
        sum += x;
        q.push(x);
        if (sum < 0) {
            sum -= q.top();
            q.pop();
        }
    }
    return q.size();
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << maximizeTransactions(a) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
