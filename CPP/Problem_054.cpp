#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <iostream>

using namespace std;

static int rval(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return 14; // A
}

// Score is a vector<int> where lexicographic compare works.
static vector<int> score(const vector<string>& hand) {
    vector<int> ranks(5);
    vector<char> suits(5);
    for (int i = 0; i < 5; i++) {
        ranks[i] = rval(hand[i][0]);
        suits[i] = hand[i][1];
    }
    sort(ranks.begin(), ranks.end());

    bool isFlush = all_of(suits.begin(), suits.end(), [&](char s){ return s == suits[0]; });

    bool isStraight = false;
    int straightHigh = ranks[4];
    bool consecutive = true;
    for (int i = 1; i < 5; i++) {
        if (ranks[i] != ranks[i-1] + 1) { consecutive = false; break; }
    }
    if (consecutive) {
        isStraight = true;
    } else if (ranks == vector<int>({2,3,4,5,14})) {
        isStraight = true;
        straightHigh = 5;
    }

    unordered_map<int,int> freq;
    for (int r : ranks) freq[r]++;

    vector<pair<int,int>> groups; // (count, rank)
    groups.reserve(freq.size());
    for (auto &kv : freq) groups.push_back({kv.second, kv.first});
    sort(groups.begin(), groups.end(), [](auto &a, auto &b){
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });

    vector<int> ranksDesc = ranks;
    reverse(ranksDesc.begin(), ranksDesc.end());

    if (isFlush && isStraight) {
        if (straightHigh == 14) return {9};            // royal flush
        return {8, straightHigh};                      // straight flush
    }

    if (groups[0].first == 4) {
        int quad = groups[0].second;
        int kicker = 0;
        for (int r : ranks) if (r != quad) kicker = max(kicker, r);
        return {7, quad, kicker};
    }

    if (groups[0].first == 3 && groups.size() > 1 && groups[1].first == 2) {
        return {6, groups[0].second, groups[1].second}; // full house
    }

    if (isFlush) {
        vector<int> v = {5};
        v.insert(v.end(), ranksDesc.begin(), ranksDesc.end());
        return v;
    }

    if (isStraight) return {4, straightHigh};

    if (groups[0].first == 3) {
        int trip = groups[0].second;
        vector<int> kickers;
        for (int r : ranks) if (r != trip) kickers.push_back(r);
        sort(kickers.rbegin(), kickers.rend());
        return {3, trip, kickers[0], kickers[1]};
    }

    if (groups[0].first == 2 && groups.size() > 1 && groups[1].first == 2) {
        int p1 = groups[0].second, p2 = groups[1].second;
        int highPair = max(p1, p2), lowPair = min(p1, p2);
        int kicker = 0;
        for (int r : ranks) if (r != p1 && r != p2) kicker = r;
        return {2, highPair, lowPair, kicker};
    }

    if (groups[0].first == 2) {
        int pair = groups[0].second;
        vector<int> kickers;
        for (int r : ranks) if (r != pair) kickers.push_back(r);
        sort(kickers.rbegin(), kickers.rend());
        return {1, pair, kickers[0], kickers[1], kickers[2]};
    }

    vector<int> v = {0};
    v.insert(v.end(), ranksDesc.begin(), ranksDesc.end());
    return v;
}

int main() {
    ifstream in("poker.txt");
    string c;
    int wins = 0;

    while (true) {
        vector<string> cards(10);
        for (int i = 0; i < 10; i++) {
            if (!(in >> cards[i])) {
                cout << wins << "\n"; // should be 376 on official file
                return 0;
            }
        }
        vector<string> h1(cards.begin(), cards.begin() + 5);
        vector<string> h2(cards.begin() + 5, cards.end());

        if (score(h1) > score(h2)) wins++;
    }
}
