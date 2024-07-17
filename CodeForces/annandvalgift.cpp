#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int trzeros(int N){
    int res = 0;
    while (N % 10 == 0){
        ++res;
        N /= 10;
    }
    return res;
}

void solve()
{
    int N, M; cin >> N >> M;
    vector<int> zeros;
    int ans = 0;
    rep(i, 0, N){
        int X; cin >> X;
        ans += to_string(X).size();
        zeros.push_back(trzeros(X));
    }
    sort(all(zeros), greater<int> ());
    for (int i = 0; i < N; i += 2){
        ans -= zeros[i];
    }
    cout << (ans >= M + 1 ? "Sasha\n" : "Anna\n");
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
