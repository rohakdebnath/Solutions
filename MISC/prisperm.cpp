#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int P, C;

void prisRec(int lvl = 0, string S = "", char last = 'c', int chairs = 0, int pris = 0){
    // if (chairs > C - P or pris > P) return; 
    if (lvl == C){
        cout << S << '\n';
        return;
    }
    if (last == 'c'){
        if (chairs < C - P and pris <= P) prisRec(lvl + 1, S + 'c', 'c', chairs + 1, pris);
        if (chairs <= C - P and pris < P) prisRec(lvl + 1, S + 'p', 'p', chairs, pris + 1);
    } else {
        if (chairs < C - P and pris <= P) prisRec(lvl + 1, S + 'c', 'c', chairs + 1, pris);
    }
}
int main()
{
    UNSYNC
    cin >> P >> C;
    prisRec(0, "", 'c', 0, 0);
    return 0;
}
