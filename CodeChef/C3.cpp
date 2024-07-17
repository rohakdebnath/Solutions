// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// #define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
// #define sci(x) static_cast<i64>(x)
// #define all(x) x.begin(), x.end()
// #define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
// #define per(i, fin, x) for (i64 i = fin; i >= x; --i)
// #define VI vector<i64>
// #define VVI vector<vector<i64>>

// void solve()
// {
//     i64 N; cin >> N;
//     VI A(N); rep(i, 0, N) cin >> A[i];
//     i64 E = 0, O = 0;
//     rep(i, 0, N){
//         if (i % 2) O += A[i];
//         else E += A[i];
//     }

//     i64 S = E + O;
//     if (N == 1){
//         if (S == 1) cout << "Bob\n";
//         else cout << "Alice\n";
//     }
//     else if (S & 1LL){
//         cout << "Bob\n";
//     }
//     else{
//         if ((S/2^E) & 1) {
//             cout << "Alice\n";
//         }
//         else cout << "Bob\n";
//     }
// }

// int main()
// {
//     UNSYNC
//     i64 T;
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
#define VI vector<int>
#define VVI vector<vector<int>>

double square_root(double x) {
    double left = 0, right = x;
    double epsilon = 1e-10;  // Desired precision

    while (right - left > epsilon) {
        double middle = (left + right) / 2;
        if (middle * middle <= x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return left;
}
int main()
{
    UNSYNC
    double num; cin >> num;
    cout << setprecision(10) << square_root(num) << '\n';
    return 0;
}
