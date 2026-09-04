class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int mind = -1, maxd = -1;

        if(head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }

        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* nex = curr->next;

        int pos = 1;

        int firstCP = -1;
        int lastCP = -1;

        int minDist = INT_MAX;

        while(nex != nullptr) {

            int prevval = prev->val;
            int currval = curr->val;
            int nextval = nex->val;

            if((prevval < currval && nextval < currval) ||
               (prevval > currval && nextval > currval)) {

                // First critical point
                if(firstCP == -1) {
                    firstCP = pos;
                }
                else {
                    minDist = min(minDist, pos - lastCP);
                }

                // Current becomes the latest critical point
                lastCP = pos;
            }

            prev = curr;
            curr = nex;
            nex = nex->next;

            pos++;
        }

        // Less than 2 critical points
        if(firstCP == lastCP) {
            return {-1, -1};
        }

        maxd = lastCP - firstCP;

        return {minDist, maxd};
    }
};