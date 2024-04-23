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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // res is the ListNode that is going to be continued , its empty in the beginning
        ListNode* res = new ListNode() ;
        // list will point to the head of the res listNode
        ListNode* list = res;
        int carry = 0;
        int total = 0;
        while(l1 || l2 || carry){
            total = carry;
            if(l1){
                total+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                total+=l2->val;
                l2 = l2->next;
            }
            int least = total%10;
            carry = total/10;
            res->next = new ListNode(least);
            res = res->next;
        }
        return list->next;

    }
};