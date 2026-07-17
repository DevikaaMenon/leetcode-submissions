class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode prehead(-1);
        ListNode* curr = &prehead;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            // Move the  pointer forward
            curr = curr->next;
        }

        // Attach the remaining part of the list that isn't empty
        curr->next = (list1 != nullptr) ? list1 : list2;

        // The actual head is the next node after our dummy
        return prehead.next;
    }
};