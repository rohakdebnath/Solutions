#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI a (N); rep(0, N) cin >> a[i];
    VI start (N);
    VI end (N);

    start[0] = a[0];
    for(int i = 1; i < N; ++i) start[i] = max(start[i - 1], a[i]);

    end[N - 1] = a[N - 1];
    for(int i = N - 2; i >= 0; --i) end[i] = max(end[i + 1], a[i]);

    std::cout << end[1] << '\n';

    for (int i = 1; i < N - 1; ++i)
    {
        std::cout << max(start[i - 1], end[i + 1]) << '\n'; 
    }

    std::cout << start[N - 2] << '\n';
    return 0;
}
