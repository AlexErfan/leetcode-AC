/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 *
 * https://leetcode.com/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (56.71%)
 * Total Accepted:    148.8K
 * Total Submissions: 262.4K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * You are given an array of words where each word consists of lowercase
 * English letters.
 * 
 * wordA is a predecessor of wordB if and only if we can insert exactly one
 * letter anywhere in wordA without changing the order of the other characters
 * to make it equal to wordB.
 * 
 * 
 * For example, "abc" is a predecessor of "abac", while "cba" is not a
 * predecessor of "bcad".
 * 
 * 
 * A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1,
 * where word1 is a predecessor of word2, word2 is a predecessor of word3, and
 * so on. A single word is trivially a word chain with k == 1.
 * 
 * Return the length of the longest possible word chain with words chosen from
 * the given list of words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output: 5
 * Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc",
 * "pcxbc", "pcxbcf"].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["abcd","dbqca"]
 * Output: 1
 * Explanation: The trivial word chain ["abcd"] is one of the longest word
 * chains.
 * ["abcd","dbqca"] is not a valid word chain because the ordering of the
 * letters is changed.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of lowercase English letters.
 * 
 * 
 */
class Solution {
private:
    int dfs(unordered_set<string>& presentWords, unordered_map<string, int>& memo, string word) {
        if (memo.find(word) != memo.end())
            return memo[word];

        int maxDepth = 1;

        // find maxDepth for current word.
        for (int i = 0; i < word.length(); i++) {
            // find depth for each newWord, update the maxDepth.
            string newWord = word.substr(0, i) + word.substr(i+1);
            int curDepth;
            if (presentWords.find(newWord) != presentWords.end()) {
                curDepth = 1 + dfs(presentWords, memo, newWord);
                maxDepth = max(maxDepth, curDepth);
            }
        }


        // store maxDepth for current word.
        memo[word] = maxDepth;

        return maxDepth;
    }


public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        unordered_set<string> presentWords;

        for (const string &word: words)
            presentWords.insert(word);

        int result = 0;
        for (const string &word: words) {
            result = max(result, dfs(presentWords, memo, word));
        }

        return result;
    }

};

