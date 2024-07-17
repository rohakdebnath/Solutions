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
    int A, B, D; cin >> A >> B >> D;
    int cur = A;
    while (cur <= B){
        cout << cur << ' ';
        cur += D;
    }
    cout << '\n';
    return 0;
}
