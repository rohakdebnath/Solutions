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

    bool ninodd = true;
    for (int i = 1; i < N; i += 2){
        if (A[i] == N){
            ninodd = false;
            break;
        }
    }
    if (!ninodd) reverse(all(A));
    vector<int> odd, even;
    rep(i, 0, N){
        if (i % 2){
            even.push_back(A[i]);
        } else {
            odd.push_back(A[i]);
        }
    }
    vector<int> id (N/2); iota(all(id), 0);
    sort(all(id), [&] (int i, int j) {return odd[i] < odd[j];});

    vector<int> oddans (N/2), evenans (N/2);
    rep(i, 0, N/2){
        oddans[id[i]] = N - i;
    }
    iota(all(id), 0);
    sort(all(id), [&] (int i, int j) {return even[i] < even[j];});
    rep(i, 0, N/2){
        evenans[id[i]] = N / 2 - i;
    }

    vector<int> fin;
    rep(i, 0, N/2){
        fin.push_back(oddans[i]);
        fin.push_back(evenans[i]);
    }
    if (!ninodd){
        reverse(all(fin));
    }

    rep(i, 0, N){
        cout << fin[i] << " \n"[i == N - 1];
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
