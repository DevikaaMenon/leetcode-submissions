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
    ListNode* reverseList(ListNode* head) {
        ListNode *current=head, *prev=nullptr,*nexx=nullptr;

        while(current!=nullptr){
            nexx=current->next;
            current->next=prev;

            prev=current;
            current=nexx;
        }
        return prev;
    }
};