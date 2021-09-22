/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (69.81%)
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return its maximum depth.
 * 
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [0]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 104].
 * -100 <= Node.val <= 100
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    queue<pair<TreeNode*, int>> nextItems;
    int curretMax = 0;

    int nextDepth () {
        if (nextItems.size() == 0)
            return curretMax;

        auto nextItem = nextItems.front();
        nextItems.pop();

        auto nextNode = nextItem.first;
        if (not nextNode)
            return curretMax;
        auto nextLevel = nextItem.second + 1;

        curretMax = max(curretMax, nextLevel); // update the depth.

        if (nextNode->left)
            nextItems.push(make_pair(nextNode->left, nextLevel));
        if (nextNode->right)
            nextItems.push(make_pair(nextNode->right, nextLevel));

        return nextDepth();
    }
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> empty;
        swap(nextItems, empty);

        nextItems.push(make_pair(root, 0));

        return nextDepth();
    }
};












