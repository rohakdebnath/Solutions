#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    bitset<100001> bit;
    vector<int> A (N); 
    rep(i, 0, N){
        int x; cin >> x;
        bit[x] = 1;
    }
    int c = bit.count();
    cout << c - !(c & 1) << '\n';
    return 0;
}
