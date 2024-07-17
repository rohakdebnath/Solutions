#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);

i64 pow3(i64 i){
    return i*i*i;
}

int main()
{
    UNSYNC
    int N, K; cin >> N >> K;
    cout << (K & 1 ? pow3(N/K) : pow3(N/K) + pow3((N + K/2)/K)) << '\n';
    return 0;
}
