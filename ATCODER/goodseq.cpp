#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int N; cin >> N;
    unordered_map<int, int> freq;
    
    for (int i = 0; i < N; ++i)
    {
        int a; cin >> a;
        ++freq[a];
    }
    int removal = 0;
    for (auto [u, v]: freq)
    {
        if (v < u) removal += v;
        else if (v > u) removal += v - u;
    }
    cout << removal << '\n';
}
