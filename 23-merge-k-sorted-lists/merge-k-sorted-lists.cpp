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
    struct campare{
        bool operator()(const ListNode* l1,const ListNode* l2){
            return l1->val>l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,campare> minHeap;

        for(ListNode* list : lists){
            if(list != nullptr){
                minHeap.push(list);
            }
        }

        ListNode* dummy =new ListNode(0);
        ListNode* tail=dummy;

        while(!minHeap.empty()){
            ListNode* smaller=minHeap.top();
            minHeap.pop();

            tail->next=smaller;
            tail=tail->next;

            if(smaller->next!=nullptr){
                minHeap.push(smaller->next);
            }
        }
        ListNode* result=dummy->next;

        delete dummy;
        return result;
        
    }
};