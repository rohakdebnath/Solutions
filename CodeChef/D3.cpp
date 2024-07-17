#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int N; cin >> N;
    if (N == 2){
        cout << "-1\n";
        return;
    }
    VVI mat (N, VI (N));

    if (N % 2){
        int curr = 3;
        rep(i, 0, N){
            rep(j, 0, N){
                if (i % 2 == 0){
                    if (j % 2){
                        mat[i][j] = curr;
                        curr += 2;
                    }
                    else{
                        mat[i][j] = curr - 1;
                    }
                }
                else{
                    if (j % 2 == 0){
                        mat[i][j] = curr;
                        curr += 2;
                    }
                    else{
                        mat[i][j] = curr - 1;
                    }
                }
            }
        }
        mat[0][0] = 1;
        if (N > 1) mat[N - 1][N - 1] = 2;
    }
    else{
        int curr = 1;
        rep(i, 0, N){
            rep(j, 0, N){
                mat[i][j] = curr;
                ++curr;
            }
        }
        for(int i = 1; i < N; i += 2) reverse(all(mat[i]));
        rep(i, 1, N){
            swap(mat[i][i], mat[i - 1][i]);
        }
    }
    rep(i, 0, N){
        rep(j, 0, N){
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
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
