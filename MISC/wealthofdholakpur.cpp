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
    vector<int> freq;
    map<int, int> fq;
    rep(i, 0, N){
        ++fq[A[i]];
    }
    for(auto [u, v]: fq){
        freq.push_back(v);
    }
    sort(all(freq));
    int medfq = freq[(freq.size() - 1)/2];
    int medfreqele = INT32_MAX;

    for(auto [u, v]: fq){
        if (medfq == v){
            medfreqele = u;
            break;
        }
    }
    cout << medfreqele << '\n';
    return 0;
}
