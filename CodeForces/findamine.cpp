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
    int n, m; cin >> n >> m;
    cout << "? " << 1e8 << " 2" << endl;
    int Mx; cin >> Mx;
    cout << "? 2 2" << endl;
    int mx; cin >> mx;
    
    int xval = abs(Mx - mx)/2;
    if (Mx > mx){
        xval *= -1;
    }
    cout << "? 2 " << 1e8 << endl;
    int My; cin >> My;
    cout << "? 2 2" << endl;
    int my; cin >> my;
    
    int yval = abs(My - my)/2;
    if (My > my){
        yval *= -1;
    }

    cout << "! " << xval << ' ' << yval << endl;
    return 0;
}
