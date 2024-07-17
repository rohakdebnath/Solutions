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
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> ans (N); ans[N - 1] = A[N - 1];
    per(i, N - 2, 0){
        int sum = 0;
        for (int j = i; j < N; j += i + 1) sum += ans[j];
        ans[i] = (A[i] != sum % 2);
    }
    int M = accumulate(all(ans), 0);
    cout << M << '\n';
    rep(i, 0, N) if (ans[i]) cout << i + 1 << ' ';
    cout << '\n';
    return 0;

}
