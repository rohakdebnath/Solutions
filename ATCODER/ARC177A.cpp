#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)


int coin(int i){
    if (i == 0) return 500;
    else if (i == 1) return 100;
    else if (i == 2) return 50;
    else if (i == 3) return 10;
    else if (i == 4) return 5;
    else return 1;
}

int main()
{
    UNSYNC
    vector<int> A (6);
    rep(i, 0, 6) cin >> A[i];
    reverse(all(A));
    int N; cin >> N;
    vector<int> X (N); rep(i, 0, N) cin >> X[i];
    sort(all(X), greater<int> ());

    rep(i, 0, N){
        rep(j, 0, 6){
            while (A[j] and X[i] >= coin(j)){
                X[i] -= coin(j);
                --A[j];
            } 
        }
        if (X[i]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
