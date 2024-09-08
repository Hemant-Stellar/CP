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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr= head;
        int l = 0; vector<ListNode*> ans(k,nullptr);
        while(curr) {
            l++;
            curr=curr->next;
        }
        curr = head;
        int rem = l%k , size = l/k;
        for(int i = 0; i<k  && curr; i++){
            int z = size + (i<rem?1:0);
            ListNode* prev = nullptr;
            ans[i]= curr;
            while(z-- && curr){
                prev = curr;
                curr = curr->next;
            }
            if(prev) prev->next = nullptr;

        }
    return ans;

    }
};