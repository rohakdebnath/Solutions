#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 19;
int delivery(int lvl, char curr, int conte){
    if (lvl == N){
        return 1;
    }
    int ans = 0;
    if (conte < 2){
        if (curr == 'E') {
            ans += delivery(lvl + 1, 'E', conte + 1);
            ans += delivery(lvl + 1, 'M', 0);
        } else {
            ans += delivery(lvl + 1, 'E', conte + 1);
        }
    } else {
        ans += delivery(lvl + 1, 'M', 0);
    }
    return ans;
}

int main()
{
    UNSYNC
    cout << delivery(0, 'E', 0) << '\n';
    return 0;
}
