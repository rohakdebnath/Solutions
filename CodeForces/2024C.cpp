#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// Comparator based on inversion counts
struct CompareInversion {
    // Function to count inversions in a vector
    int count(const vector<int>& a) const {
        int inv = 0;
        for(int i = 0; i < a.size(); ++i){
            for(int j = i + 1; j < a.size(); ++j){
                if(a[i] > a[j]){
                    ++inv;
                }
            }
        }
        return inv;
    }

    // Comparator operator
    bool operator()(const array<int, 2>& a, const array<int, 2>& b) const {
        // Create two combined vectors for comparison
        vector<int> x = {a[0], a[1], b[0], b[1]};
        vector<int> y = {b[0], b[1], a[0], a[1]};

        // Count inversions for both orderings
        int ab = count(x);
        int ba = count(y);
        return ab <= ba;
    };
};

// Function to count inversions in the flattened array
int countInversions(const vector<array<int, 2>>& a) {
    vector<int> flattened;
    for (const auto& arr : a) {
        flattened.push_back(arr[0]);
        flattened.push_back(arr[1]);
    }
    int inv = 0;
    for (int i = 0; i < flattened.size(); ++i) {
        for (int j = i + 1; j < flattened.size(); ++j) {
            if (flattened[i] > flattened[j]) {
                ++inv;
            }
        }
    }
    return inv;
}

// Function to compute the brute force best order
void bruteForce(const vector<array<int, 2>>& a, vector<array<int, 2>>& best_order, int& min_inversions) {
    best_order = a;
    min_inversions = countInversions(a);

    // Generate all permutations
    vector<array<int, 2>> perm = a;
    sort(perm.begin(), perm.end()); // Ensure starting from the first permutation

    do {
        int inv = countInversions(perm);
        if(inv < min_inversions){
            min_inversions = inv;
            best_order = perm;
        }
    } while(next_permutation(perm.begin(), perm.end()));
}

// Function to generate a single test case
vector<array<int, 2>> generateTestCase(int n, mt19937 &rng, uniform_int_distribution<int> &dist){
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; ++i){
        a[i][0] = dist(rng);
        a[i][1] = dist(rng);
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize random number generator
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, 9);

    const int n = 3; // Fixed number of pairs
    const int total_tests = 1000; // Number of test cases
    int mismatch_count = 0;

    for(int test = 1; test <= total_tests; ++test){
        // Generate a random test case
        vector<array<int, 2>> a = generateTestCase(n, rng, dist);

        // Make a copy for brute force
        vector<array<int, 2>> a_brute = a;
        vector<array<int, 2>> best_order;
        int min_inversions;
        bruteForce(a_brute, best_order, min_inversions);

        // Sort using CompareInversion
        vector<array<int, 2>> a_sorted = a;
        sort(a_sorted.begin(), a_sorted.end(), CompareInversion());

        // Compare the two sorted orders

        if(min_inversions != countInversions(a_sorted)){
            // Increment mismatch count
            mismatch_count++;

            // Print the discrepancy details
            cout << "Mismatch #" << mismatch_count << ":\n";
            cout << "Generated Input:\n";
            for(const auto& arr : a){
                cout << arr[0] << ' ' << arr[1] << "\n";
            }

            cout << "Your Order:\n";
            for(const auto& arr : a_sorted){
                cout << arr[0] << ' ' << arr[1] << "\n";
            }

            cout << "Brute Force Order:\n";
            for(const auto& arr : best_order){
                cout << arr[0] << ' ' << arr[1] << "\n";
            }
            cout << "--------------------------\n";

            // Optional: Stop after finding a certain number of mismatches
            // Uncomment the following lines if you want to stop after first mismatch
            // break;
        }
    }

    // Summary of the stress test
    cout << "Stress Test Completed.\n";
    cout << "Total Test Cases: " << total_tests << "\n";
    cout << "Total Mismatches Found: " << mismatch_count << "\n";

    return 0;
}
