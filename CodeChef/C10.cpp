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
    bitset<32> bin (N);
    string s = bin.to_string();
    s = s.substr(s.find_first_of('1'));

    bool srv = true;
    rep(i, 0, s.find_last_of('1')){
        if (s[i] == '0'){
            srv = false;
            break;;
        }
    }
    if (srv){
        cout << "0\n";
        return;
    }
    bool fnd = false;
    string n = s;
    rep(i, 1, s.size()){
        if (s[i] == '0' and !fnd){
            n[i] = '1';
            fnd = true;
        } else if (fnd){
            n[i] = '0';
        }
    }

    bitset<64> bits (s);
    i64 A = bits.to_ulong();
    bitset<64> bits2 (n);
    i64 B = bits2.to_ulong();

    
    cout << B - A << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
