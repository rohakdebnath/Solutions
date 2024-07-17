#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

vector<pair<int, int>> A;
VI lesserleft;
void merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<pair<int, int>> h1 (n1); rep(i, 0, n1) h1[i] = A[i + l];
    vector<pair<int, int>> h2 (n2); rep(i, 0, n2) h2[i] = A[i + m + 1];

    int i = 0;  //suppose we have two sorted array, our task is the calculate for each element of the second array, the smaller elements in the first array, this works because the indices of the second array at each step of the merge iteration are all greater than those in the first array. Also note that once two arrays are merged, we will not be counting anything "within" this array in anny other iteration, hence there will be no overcounting
    rep(j, 0, n2){ 
        while(h1[i].first <= h2[j].first and i < n1){
            A[i + j + l] = h1[i];
            ++i;
        }
        A[i + j + l] = h2[j];
        lesserleft[h2[j].second] += i; //The number of elements in the first array which are smaller than h2[j].first is simply the elements of the first array which already placed in the "sorted result array", which is i.
    }
    while (i < n1){ //In cases where the h1 array still has elements left (due to them being larger the sort will not complete entirely (however the count for lesser elements in h1 for each element in h2 will be complete, but the sort needs to be completed for other iterations))
        A[i + n2 + l] = h1[i];
        ++i;
    }
}   

void mergeSort(int l, int r){
    if (l >= r) return; // dividing the array until there is only one element in each array, 
    int m = l + (r - l)/2; 
    mergeSort(l, m), mergeSort(m + 1, r); //using recursion to simulate the division process
    merge(l, m, r);  //then merging pairs. Since the height of the divisions is at most log2(N) and at each level we merge using 2P , each layer takes O(N) time to merge, overall becomes O(Nlog2(N))
}

void solve()
{
    int N; cin >> N;
    A = vector<pair<int, int>> (N);
    lesserleft = VI (N, 1);
    rep(i, 0, N){
        int x; cin >> x;
        A[i] = {x, i};
    }
    mergeSort(0, N - 1);
    for (int i: lesserleft) cout << i << ' ';
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
