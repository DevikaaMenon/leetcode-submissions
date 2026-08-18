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
    void reorderList(ListNode* head) {
        if(!head) return;

        vector<ListNode*> vt;
        for(ListNode* temp=head;temp;temp=temp->next){
            vt.push_back(temp);
        }
        int i=0,j=vt.size()-1;
        while(i<j){
            vt[i]->next=vt[j];
            i++;
            if(i==j) break;
            vt[j]->next=vt[i];
            j--;
        }
        vt[i]->next=nullptr;
    }
};