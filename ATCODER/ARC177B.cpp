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
    string B; cin >> B;
    string S = "";
    per(i, N - 1, 0){
        if (B[i] - '0'){
            S += string (i + 1, 'A');
            S += string (i, 'B');
        }
    }
    cout << S.size() << '\n' << S << '\n';
    return 0;
}
