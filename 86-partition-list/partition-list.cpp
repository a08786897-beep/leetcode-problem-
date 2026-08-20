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
    ListNode* partition(ListNode* head, int x) {

        ListNode* curr=head;
        ListNode small(0);
        ListNode high(0);


        ListNode* smallTail=&small;
        ListNode* largeTail=&high;

        while(curr !=nullptr){
            if(curr->val<x){
                smallTail->next=curr;
                smallTail=smallTail->next;
            }else {
                largeTail->next=curr;
                largeTail=largeTail->next;
            }
            curr=curr->next;
        }
        largeTail->next=nullptr;
        smallTail->next=high.next;
        return small.next;
    }
};