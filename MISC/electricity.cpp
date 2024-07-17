#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

struct elec
{
    unsigned int D;
    unsigned int M;
    int Y;
    unsigned int C;

    elec(int a = 0, int b = 0, int c = 0, int d = 0): D (a), M (b), Y (c), C(d) {}
};

int nextdateandbill(const elec& e1, const elec& e2)
{
    chrono::sys_days date1 {chrono::year {e1.Y}/ chrono::month {e1.M}/ chrono::day {e1.D}};
    chrono::sys_days date2 {chrono::year {e2.Y}/ chrono::month {e2.M}/ chrono::day {e2.D}};

    if (date2 - date1 == std::chrono::days{1}) return e2.C - e1.C;
    else return 0;
}   

int main()
{
    UNSYNC
    int n; cin >> n;
    vector<elec> data (n);
    rep(i, 0, n) cin >> data[i].D >> data[i].M >> data[i].Y >> data[i].C;
    int fosho = 0;
    int totalbill = 0;
    rep(i, 1, n)
    {
        int t = nextdateandbill(data[i - 1], data[i]);
        if (t)
        {
            ++fosho;
            totalbill += t;
        }
    }
    cout << fosho << ' ' << totalbill << '\n';
    return 0;
}
