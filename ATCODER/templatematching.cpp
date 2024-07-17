#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

struct Sq{
    int x1;
    int y1;
    int x2;
    int y2;
};

bool match(vector<string>& A, vector<string>& B, Sq m){
    bool srv = true;
    rep(i, m.x1, m.x2){
        rep(j, m.y1, m.y2){
            if (A[i][j] != B[i - m.x1][j - m.y1]){
                srv = false;
                break;
            }
        }
    }
    return srv;
}

int main()
{
    UNSYNC
    int N, M; cin >> N >> M;
    vector<string> A (N);
    rep(i, 0, N) cin >> A[i];
    vector<string> B (M);
    rep(i, 0, M) cin >> B[i];

    bool found = false;
    rep(i, 0, N - M + 1){
        rep(j, 0, N - M + 1){
            if (match(A, B, {i, j, i + M, j + M})){
                found = true;
                break;
            }
        }
    }
    cout << (found ? "Yes\n" : "No\n");
    return 0;
}
