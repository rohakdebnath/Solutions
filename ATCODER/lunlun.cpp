#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int SZ = 1e5;
int main()
{
    UNSYNC
    int K; cin >> K;
    vector<i64> lunlun (9); iota(all(lunlun), 1);
    rep(i, 0, SZ){
        if (lunlun.size() > SZ) break;
        int x = lunlun[i];
        if (x % 10 != 0) lunlun.push_back(10LL*x + x % 10 - 1);
        lunlun.push_back(10LL*x + x % 10);
        if (x % 10 != 9) lunlun.push_back(10LL*x + x % 10 + 1);
    }
    cout << lunlun[K - 1] << '\n';
    return 0;
}
