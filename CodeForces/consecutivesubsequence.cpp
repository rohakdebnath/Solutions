#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, int> dp; //dp[i] = length of maximum segment ending at value i
    map<int, int> id; //index of first occurance of an element a[i]
    int lisl = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (lisl < dp[a[i]]) {
            lisl = dp[a[i]];
            m = a[i];
        }
        if (id.find(a[i]) == id.end()) {
            id[a[i]] = i;
        }
    }   
    cout << lisl << '\n';
    deque<int> arr;
    for (int i = n - 1; i >= 0; --i) { 
        if (a[i] == m){
            arr.push_front(i + 1);
            --m;
        }
    }
    for (int i = 0; i < lisl; ++i) {
        cout << arr[i] << " \n"[i == lisl - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
