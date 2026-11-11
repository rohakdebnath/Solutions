#include <bits/stdc++.h>
using namespace std;

const string p = "11111";
vector<string> pword;

string run(string guess) {
    cout << guess << endl;
    string a;
    for (int i = 0; i < 5; ++i) {
        char c; cin >> c;
        a += c;
    }
    return a;
}

bool matches(const string& word, const string& guess, const string& feedback) {
    for (int i = 0; i < 5; ++i) {
        if (feedback[i] == '1' and word[i] != guess[i]) return false;
    }
    vector<int> f (26);
    for (int i = 0; i < 5; ++i) {
        if (feedback[i] != '1') f[word[i] - 'a']++;
    }
    for (int i = 0; i < 5; ++i) {
        if (feedback[i] == '2') {
            if (word[i] == guess[i] or f[guess[i] - 'a'] == 0) return false;
            f[guess[i] - 'a']--;
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (feedback[i] == '0' and f[guess[i] - 'a'] > 0) return false;
    }
    return true;
}

int main() {
    ifstream infile("wordle.txt");
    string word;
    while (infile >> word) {
        pword.push_back(word);
    }
    infile.close();

    int x = 0;
    while (x < 6 and !pword.empty()) {
        string guess = (x == 0 ? "crane": pword[0]);
        auto r = run(guess);
        if (r == p) {
            cout << "Found the word: " << guess << endl;
            return 0;
        }
        vector<string> npword;
        for (const string& word : pword) {
            if (matches(word, guess, r)) {
                npword.push_back(word);
            }
        }
        pword = npword;
        ++x;
    }
    cout << "Sorry LoL\n";
    return 0;
}
