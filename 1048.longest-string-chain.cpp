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
public:
    int longestStrChain(vector<string>& words) {
//                unordered_map<string, int> dp;
//
//        // Sorting the list in terms of the word length.
//        std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
//            return word1.size() < word2.size();
//        });
//
//        int longestWordSequenceLength = 1;
//
//        for (const string &word : words) {
//            int presentLength = 1;
//            // Find all possible predecessors for the current word by removing one letter at a time.
//            for (int i = 0; i < word.length(); i++) {
//                string predecessor = word.substr(0, i) + word.substr(i + 1, word.length() + 1);
//                if (dp.find(predecessor) != dp.end()) {
//                    int previousLength = dp[predecessor];
//                    presentLength = max(presentLength, previousLength + 1);
//                }
//            }
//            dp[word] = presentLength;
//            longestWordSequenceLength = max(longestWordSequenceLength, presentLength);
//        }
//        return longestWordSequenceLength;

        unordered_map<string, int> dp;

        // Sorting the list in terms of the word length.
        std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
            return word1.size() < word2.size();
        });

        int maxLength = 1;
        for (const string& word: words) {
            int curMaxLen = 1;

            // find max length for current word.
            for (int i = 0; i < word.length(); i++) {
                string newWord = word.substr(0,i) + word.substr(i+1);
                if (dp.find(newWord) != dp.end()) {
                    int prevLen = dp[newWord];
                    curMaxLen = max(prevLen + 1, curMaxLen);
                }
            }
            dp[word] = curMaxLen;
            maxLength = max(curMaxLen, maxLength);
        }

        return maxLength;
    }
};

