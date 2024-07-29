class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    multimap<string, string> map;
    vector<vector<string>> myAnagrams;
    vector<string> anagram;
    vector<string> unsorted_strs = strs;
    for (auto& word : strs) {
        string unsorted = word;
        sort(word.begin(), word.end());
        map.insert({ word,unsorted });
    }
    sort(strs.begin(), strs.end());
    auto it = map.begin();
    auto last = unique(strs.begin(), strs.end());
    strs.erase(last, strs.end());
    for (auto word : strs) {
        sort(word.begin(), word.end());
        for (int i = 0; i < map.count(word); i++) {
            anagram.push_back(it->second);
            if (it != map.end()) it++;
        }
        myAnagrams.push_back(anagram);
        anagram.clear();
    }

    return myAnagrams;
}
};