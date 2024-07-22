#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& fenwick, int index, int value, int n) {
    while (index <= n) {
        fenwick[index] += value;
        index += index & (-index);
    }
}

int query(const vector<int>& fenwick, int index) {
    int sum = 0;
    while (index > 0) {
        sum += fenwick[index];
        index -= index & (-index);
    }
    return sum;
}

int calculateSumOfSi(const vector<int>& arr, int min_val) {
    int n = arr.size();
    int max_elem = *max_element(arr.begin(), arr.end()) - min_val;
    vector<int> fenwick(max_elem + 2, 0);
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        int shifted_index = arr[i] - min_val;
        int count = query(fenwick, shifted_index);
        total_sum += count;
        update(fenwick, shifted_index + 1, 1, max_elem + 1); // +1 for 1-based index
    }
    return total_sum;
}

class Solution {
  public:
    long long greatCount(int N, string S) {
        S = '0' + S; // Prepending '0' to manage indices correctly
        vector<int> a(N + 1);
        int s = 0;
        int min_val = INT_MAX;
        for (int i = 0; i <= N; ++i) {
            s += S[i] - '0';
            a[i] = 2 * s - i;
            min_val = min(min_val, a[i]);
        }
        
        return calculateSumOfSi(a, min_val);
    }
};

int main(){
    int t;
    scanf("%d ", &t);
    while(t--){
        int N;
        cin >> N;
        
        string S;
        cin >> S;

        Solution obj;
        long long res = obj.greatCount(N, S);
        
        cout << res << endl;
    }
}
