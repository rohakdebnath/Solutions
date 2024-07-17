#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    string s; cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(2, 2));

    bool A = a <= 12 and a >= 1;
    bool B = b <= 12 and b >= 1;
    
    if (A and B) cout << "AMBIGUOUS\n";
    else if (A) cout << "MMYY\n";
    else if (B) cout << "YYMM\n";
    else cout << "NA\n";
    return 0;
}
