// Last updated: 7/6/2026, 12:10:27 PM
class Solution {
    unordered_map<string, int> mpp;      // stores minimum steps to reach a word
    vector<vector<string>> ans;           // final answer
    string b;                             // beginWord

private:
    // DFS to generate all shortest paths
    void dfs(string word, vector<string> &seq) {
        // If we reach beginWord, store the path
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        // Try all one-letter transformations
        for (int i = 0; i < sz; i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                // Move only to previous level word
                if (mpp.find(word) != mpp.end() &&
                    mpp[word] + 1 == steps) {

                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // backtrack
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string> &wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;

        b = beginWord;
        q.push(beginWord);
        mpp[beginWord] = 1;

        int sz = beginWord.size();
        st.erase(beginWord);

        // ---------- BFS PART ----------
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i < sz; i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // ---------- DFS PART ----------
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};
