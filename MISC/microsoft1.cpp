#include <bits/stdc++.h>
using namespace std;

struct Results {
    string set_name;
    vector<string> selected_cards;
};

#include <bits/stdc++.h>

int getRankValues(char rank) {
    if (rank == 'A') return 14;
    if (rank == 'K') return 13;
    if (rank == 'Q') return 12;
    if (rank == 'J') return 11;
    if (rank == '1') return 10;
    return rank - '0';
}

bool compareCards(const string& a, const string& b) {
    return getRankValues(a[0]) > getRankValues(b[0]);
}

bool findFiveInARow(vector<string>& cards, Results& result) {
    map<int, vector<string>> mpp;
    for (string& card : cards) {
        mpp[getRankValues(card[0])].push_back(card);
    }

    vector<int> ranks;
    for (auto& pair : mpp) ranks.push_back(pair.first);
    sort(ranks.begin(), ranks.end(), greater<int>());

    for (size_t i = 0; i + 4 < ranks.size(); ++i) {
        if (ranks[i] - ranks[i + 4] == 4) {
            result.set_name = "five in a row";
            for (int j = 0; j < 5; ++j) result.selected_cards.push_back(mpp[ranks[i + j]][0]);
            reverse(result.selected_cards.begin(), result.selected_cards.end());
            return true;
        }
    }
    return false;
}

bool findSuit(vector<string>& cards, Results& result) {
    unordered_map<char, vector<string>> suitMap;
    for (string& card : cards) suitMap[card[card.size() - 1]].push_back(card);

    char suits[] = {'S', 'H', 'D', 'C'};
    for (char suit : suits) {
        if (suitMap[suit].size() >= 5) {
            sort(suitMap[suit].begin(), suitMap[suit].end(), compareCards);
            result.set_name = "suit";
            result.selected_cards.assign(suitMap[suit].begin(), suitMap[suit].begin() + 5);
            reverse(result.selected_cards.begin(), result.selected_cards.end());
            return true;
        }
    }
    return false;
}

bool findTripleAndPair(vector<string>& cards, Results& result) {
    map<char, vector<string>> rankMap;
    for (string& card : cards) rankMap[getRankValues(card[0])].push_back(card);

    vector<string> triple, pair;
    for (auto it = rankMap.rbegin(); it != rankMap.rend(); ++it) {
        if (it->second.size() >= 3 and triple.empty()) triple = { it->second[0], it->second[1], it->second[2] };
        else if (it->second.size() >= 2 and pair.empty()) pair = { it->second[0], it->second[1] };

        if (!triple.empty() and !pair.empty()) {
            result.set_name = "a triple and a pair";
            result.selected_cards = triple;
            result.selected_cards.insert(result.selected_cards.end(), pair.begin(), pair.end());
            return true;
        }
    }
    return false;
}

bool findPair(vector<string>& cards, Results& result) {
    map<int, vector<string>> rankMap;
    for (string& card : cards) {
        if (card[0] == '1' and card[1] == '0') rankMap[10].push_back(card);
        else rankMap[getRankValues(card[0])].push_back(card);
    }

    for (auto it = rankMap.rbegin(); it != rankMap.rend(); ++it) {
        if (it->second.size() >= 2) {
            result.set_name = "pair";
            result.selected_cards = { it->second[0], it->second[1] };
            return true;
        }
    }
    return false;
}

bool findTriple(vector<string>& cards, Results& result) {
    map<int, vector<string>> rankMap;
    for (string& card : cards) {
        rankMap[getRankValues(card[0])].push_back(card);
    }

    for (auto it = rankMap.rbegin(); it != rankMap.rend(); ++it) {
        if (it->second.size() >= 3) {
            result.set_name = "triple";
            result.selected_cards = {it->second[0], it->second[1], it->second[2] };
            return true;
        }
    }
    return false;
}

bool findSingleCard(vector<string>& cards, Results& result) {
    result.set_name = "single card";
    sort(cards.begin(), cards.end(), compareCards);
    result.selected_cards.push_back(cards[0]);
    return true;
}

Results solution(vector<string>& cards) {
    Results result;
    if (findTripleAndPair(cards, result)) return result;
    if (findSuit(cards, result)) return result;
    if (findFiveInARow(cards, result)) return result;
    if (findTriple(cards, result)) return result;
    if (findPair(cards, result)) return result;
    if (findSingleCard(cards, result)) return result;
    assert(result.selected_cards.size() > 0);
    return result;
}


int main() {
    vector<string> cards = {"JS", "QD"};
    Results ans = solution(cards);
    vector<string> a = ans.selected_cards;
    for (auto s: a) cout << s << '\n';
    cout << '\n';

};
