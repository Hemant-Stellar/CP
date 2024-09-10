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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head->next;
        ListNode* previous = head;
        while(current){
            ListNode* node = new ListNode(gcd(previous->val,current->val),nullptr);
            previous->next = node;
            node->next = current;
            previous = current;
            current = current->next;
        }
        return head;
    }
};