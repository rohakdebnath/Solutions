#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int M;
void catalan(int N, string s = "", int o = 0, int c = 0){
    if (N == 0){
        cout << s << '\n';
        return;
    }
    if (o < M) catalan(N - 1, s + '(', o + 1, c);
    if (o > c) catalan(N - 1, s + ')', o, c + 1);
}
int main()
{
    UNSYNC
    cin >> M;
    catalan(2*M, "", 0, 0);
    
    return 0;
}
