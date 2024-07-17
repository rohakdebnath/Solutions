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
//     i64 N, K; cin >> N >> K;
//     VI A (N); 
//     i64 odds = 0;
//     rep(i, 0, N)
//     {
//         i64 a; cin >> a;
//         if (a % 2) ++odds;
//         A[i] = a;
//     }
//     sort(all(A));
//     i64 oddops = min(K, odds);
//     K -= oddops;
//     rep(i, N - 1, 0)
//     {
//         if (A[i] % 2 and oddops > 0)
//         {
//             ++A[i];
//             --oddops;
//         }
//     }
//     sort(all(A));
//     i64 minel = INT32_MAX;
//     rep(i, 0, N)
//     {
//         if (A[i] % 2 == 0) minel = min(minel, A[i]);
//     }
//     bool doit = true;
//     while(K--)
//     {
//         if (doit)
//         {
//             while (minel % 2 == 0 and K > 0) minel /= 2, --K;
//             doit = false;
//         }
//         else if (!doit and K > 0)
//         {
//             ++minel;
//             --K;
//             doit = true;
//         }
//     }
//     cout << accumulate(1 + all(A), 0LL) + minel << '\n';
// }

// int main()
// {
//     UNSYNC
//     i64 T;
//     cin >> T;
//     while(T--) solve();
//     return 0;
// }
