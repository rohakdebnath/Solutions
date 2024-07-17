// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// #define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
// #define sci(x) static_cast<int>(x)
// #define all(x) x.begin(), x.end()
// #define rep(i, ini, x) for (int i = ini; i < x; ++i)
// #define per(i, fin, x) for (int i = fin; i >= x; --i)
// #define VI vector<i64>
// #define VVI vector<vector<i64>>
// template <class T> istream& operator>>(istream& is, vector<T>& v) {
//     for (auto& x : v) is >> x;
//     return is;
// }
// void solve()
// {
//     int X, Q; cin >> X >> Q;
//     map<int, int> pfacts;
//     for (int i = 2; i * i <= X; ++i){
//         while (X % i == 0){
//             ++pfacts[i];
//             X /= i;
//         }
//     }
//     if (X > 2) ++pfacts[X];
//     while (Q--){
//         int p; cin >> p;
//         if (p == 1){
//             cout << "1\n";
//             continue;
//         }
//         int m = 0;
//         for (auto [u, v]: pfacts){
//             if (v % p == 0) ++m;
//         }
//         cout << (1 << m) << '\n';
//     }
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
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

void solve()
{
    
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
