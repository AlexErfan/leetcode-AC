/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (55.48%)
 * Total Accepted:    692.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You
 * must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case
        if (head == NULL)
            return nullptr; 
        if (head->next == NULL) 
            return head;

        // record current next and current temp; 
        ListNode* next = head->next; // original next.
        ListNode* temp = head->next->next; // original third.

        // swap *next pointer.
        next->next = head; // original next->next to head.
        //head->next = temp; // original head->next to third.
        
        // swap head pointer.
        head = next;       // original next to head.
        next = head->next; // original head to next.
        
        // connect to next sawp pairs
        next->next = swapPairs(temp);
        return head;
    }
};





