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

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A), [&] (int i, int j) {return i > j;});
    VI prefA (N);
    partial_sum(A.begin(), A.end(), prefA.begin());
    int ini = upper_bound(all(prefA), prefA[N - 1]/2) - prefA.begin();
    cout << ini + 1 << '\n'; 
    
    return 0;
}
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

// int main()
// {
//     UNSYNC
//     VI A = {1, 2, 3, 4, 4, 4, 4, 5, 6};
//     cout << lower_bound(all(A), 4) - A.begin() << '\n';
//     cout << upper_bound(A.rbegin(), A.rend(), 4, greater<int>()) - A.rbegin() << '\n';
//     return 0;
// }
