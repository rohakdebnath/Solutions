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

VI poss (21);
int N;
VI A; 
void sumRec(int sum, int t){
    if (t == N){
        poss[sum] = 1;
        return;
    }
    sumRec(sum + A[t], t + 1);
    sumRec(sum, t + 1);

    return;
}

int main()
{
    UNSYNC
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];

    sumRec(0, 0);
    rep(i, 0, 21){
        if (poss[i] == 0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
