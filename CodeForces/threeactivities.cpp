// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// #define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
// #define sci(x) static_cast<int>(x)
// #define all(x) x.begin(), x.end()
// #define rep(i, ini, x) for (int i = ini; i < x; ++i)
// #define per(i, fin, x) for (int i = fin; i >= x; --i)
// #define VI vector<int>
// #define VVI vector<vector<int>>

// int n;
// int maxim(VI& x, VI& y, VI& z)
// {
//     int i = distance(x.begin(), max_element(all(x)));
//     int j = 0;
//     int maxy = 0;
//     rep(l, 0, n)
//     {
//         if (l == i) continue;
//         if (maxy < y[l])
//         {
//             maxy = y[l];
//             j = l;
//         }
//     }
//     int k = 0;
//     int maxz = 0;
//     rep(l, 0, n)
//     {
//         if (l == i or l == j) continue;
//         if (maxz < z[l])
//         {
//             maxz = z[l];
//             k = l;
//         }
//     }
//     return x[i] + y[j] + z[k];
// }

// void solve()
// {
//     cin >> n;
//     VI a (n), b (n), c(n);
//     rep(i, 0, n) cin >> a[i];
//     rep(i, 0, n) cin >> b[i];
//     rep(i, 0, n) cin >> c[i];
//     int ans = max({maxim(a, b, c), maxim(b, a, c), maxim(a, c, b), maxim(b, c, a), maxim(c, b, a), maxim(c, a, b)});
//     cout << ans << '\n';
// }

// int main()
// {
//     UNSYNC
//     int T;
//     cin >> T;
//     while(T--) solve();
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {2, 3, 1, 4, 5};

    // Create an index vector [0, 1, 2, ...]
    vector<size_t> index(vec2.size());
    iota(index.begin(), index.end(), 0);

    // Sort the index vector based on the values in vec2
    sort(index.begin(), index.end(), [&vec2](size_t i, size_t j) {
        return vec2[i] < vec2[j];
    });

    // Reorder vec1 based on the sorted index vector
    sort(vec1.begin(), vec1.end(), [&vec2](int i, int j) {
        return vec2[i - 1] < vec2[j - 1];
    });

    // Output the sorted vec1
    for (int num : vec1) {
        cout << num << " ";
    }

    return 0;
}
