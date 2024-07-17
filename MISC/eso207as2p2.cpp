//Josephus using normal recursion works in O(n) but since here n <= 1e12, a slightly different version in O(klogn) is used
#include <iostream> 

using namespace std;
using i64 = long long;

int josrec(int N, int K){
    if (K == 1) return N - 1;
    if (N == 1) return 0;
    if (N < K){
        return (josrec(N - 1, K) + K) % N;
    } 
    int test = josrec(N - N/K, K) - N % K;
    if (test < 0) test += N;
    else test += test/(K - 1);
    return test;
}
int main()
{
    int N, K; cin >> N >> K;
    cout << josrec(N, K) + 1 << '\n';
    return 0;
}
