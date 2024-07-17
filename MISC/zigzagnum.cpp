#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int N, K; 

void zigzag(int lvl = 0, string S = "", int low = 1, int last = K + 1){
    if (lvl == N){
        cout << S << '\n';
        return;
    }
    if (low){
        rep(i, 1, last){
            zigzag(lvl + 1, S + char(i + '0'), !low, i);
        }
    } else {
        rep(i, last + 1, K + 1){
            zigzag(lvl + 1, S + char(i + '0'), !low, i);
        }
    }
}

int main()
{
    UNSYNC
    cin >> N >> K;
    zigzag(0, "", 1, K + 1);
    return 0;
}
