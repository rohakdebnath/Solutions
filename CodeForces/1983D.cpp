// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// void solve() {
//     int n; cin >> n; 
//     vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
//     vector<int> b(n); for (int i = 0; i < n; ++i) cin >> b[i];
    
//     auto merge = [&](auto& self, vector<int>& arr, vector<int>& temp, int left, int mid, int right) -> i64 {
//         i64 inv = 0;
//         int i = left, j = mid, k = left;
//         while (i <= mid - 1 && j <= right) {
//             if (arr[i] <= arr[j]) {
//                 temp[k++] = arr[i++];
//             } else {
//                 temp[k++] = arr[j++];
//                 inv += (mid - i);
//             }
//         }
//         while (i <= mid - 1) temp[k++] = arr[i++];
//         while (j <= right) temp[k++] = arr[j++];

//         for (i = left; i <= right; i++) {
//             arr[i] = temp[i];
//         }
//         return inv;
//     };

//     auto mergeSort = [&](auto& self, vector<int>& arr, vector<int>& temp, int left, int right) -> i64 {
//         i64 inv = 0;
//         if (right > left) {
//             int mid = (left + right) / 2;
//             inv += self(self, arr, temp, left, mid);
//             inv += self(self, arr, temp, mid + 1, right);
//             inv += merge(self, arr, temp, left, mid + 1, right);
//         }
//         return inv;
//     };

//     auto countSwaps = [&](vector<int>& arr) -> i64 {
//         vector<int> temp (n);
//         return mergeSort(mergeSort, arr, temp, 0, n - 1);
//     };
//     int x = countSwaps(a) % 2 == countSwaps(b) % 2;
//     sort(a.begin(), a.end()), sort(b.begin(), b.end());

//     cout << ((a != b) or !x ? "NO\n" : "YES\n");
// }

// signed main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int T; cin >> T;
//     while (T--) solve();
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n; 
    vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n); for (int i = 0; i < n; ++i) cin >> b[i];
    auto va = a, vb = b;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    if (va != vb) {
        cout << "NO\n";
        return;
    }
    //coordinate compression
    vector<int> ida (n); iota(ida.begin(), ida.end(), 0); 
    sort(ida.begin(), ida.end(), [&] (int i, int j) {return a[i] < a[j];});
    vector<int> pid (n);
    for (int i = 0; i < n; ++i) pid[ida[i]] = i;

    vector<int> idb (n); iota(idb.begin(), idb.end(), 0);
    sort(idb.begin(), idb.end(), [&] (int i, int j) {return b[i] < b[j];});

    int parity = 1;
    for (int i = 0; i < n; ++i) {
        if (ida[i] == idb[i]) continue;
        parity ^= 1;
        int j = pid[idb[i]];
        swap(ida[i], ida[j]);
        swap(pid[ida[i]], pid[ida[j]]);
    }
    cout << (parity ? "YES\n" : "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
int parity(const vector<int> &a) {
    const int n = a.size();
    vector<bool> vis(n);
    int p = n % 2;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        for (int j = i; !vis[j]; j = a[j]) {
            vis[j] = true;
        }
        p ^= 1;
    }
    return p;
}
