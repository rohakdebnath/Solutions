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
    int N; cin >> N;
    VI A (N); cin >> A;
    auto dist = [&] (int x, int y) {return abs(A[x] - A[y]);};
    VI right (N), left (N);
    right.front() = left.back() = 0;
    rep(i, 0, N - 1){
        right[i + 1] = right[i] + (i == 0 or dist(i, i + 1) < dist(i, i - 1) ? 1 : dist(i, i + 1)); 
    }
    per(i, N - 1, 1){
        left[i - 1] = left[i] + (i == N - 1 or dist(i, i + 1) > dist(i, i - 1) ? 1 : dist(i, i - 1));
    }

    auto query = [&] (int x, int y){
        if (x > y){
            return left[y] - left[x];
        } else {
            return right[y] - right[x];
        }
    };

    int M; cin >> M;
    while (M--){
        int s, e; cin >> s >> e; --s, --e;
        cout << query(s, e) << '\n';
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
