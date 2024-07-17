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
    string S; cin >> S;
    int count = 0;
    rep(i, 0, 10){
        rep(j, 0, 10){
            rep(k, 0, 10){
                int posi = find(all(S), i + '0') - S.begin();
                int posj = find(1 + posi + all(S), j + '0') - S.begin();
                int posk = find(1 + posj + all(S), k + '0') - S.begin();
                if (posi < N and posj < N and posk < N){
                    ++count;
                }
            }
        }
    }
    cout << count << '\n';
    return 0;
}
