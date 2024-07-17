#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    if (is_sorted(all(A)) or A.size() <= 2){
        cout << "YES\n";
        return;
    } else {
        if (A[0] < A[N - 1]){
            cout << "NO\n";
            return;
        }
        rep(i, 1, N - 1){
            if ((A[i - 1] <= A[i] and A[i] >= A[i + 1])){
                vector<int> s = vector<int> (A.begin() + i + 1, A.end());
                s.insert(s.end(), A.begin(), A.begin() + i + 1);
                if (is_sorted(all(s))) cout << "YES\n";
                else cout << "NO\n";
                break;
            }
        }
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
