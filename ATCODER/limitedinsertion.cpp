#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI b (N); rep(i, 0, N) cin >> b[i];
    VI ans;
    rep(i, 0, N)
    {
        if (b[i] > i + 1)
        {
            cout << "-1\n";
            return 0;
        }
        ans.insert(ans.begin() + b[i] - 1, b[i]);
    }
    for(int i : ans) cout << i << '\n';
    return 0;
}

/**
 *    author:  tourist
 *    created: 23.03.2019 14:11:40       
**/
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     vector<int> b;
//     while (!a.empty()) {
//         int found = 0;
//         for (int i = (int) a.size() - 1; i >= 0; i--) {
//         if (a[i] == i + 1) {
//             b.push_back(i + 1);
//             a.erase(a.begin() + i);
//             found = 1;
//             break;
//         }
//         }
//         if (!found) {
//         cout << -1 << '\n';
//         return 0;
//         }
//     }
//     reverse(b.begin(), b.end());
//     for (int i = 0; i < n; i++) {
//         cout << b[i] << '\n';
//     }
//     return 0;
// }
