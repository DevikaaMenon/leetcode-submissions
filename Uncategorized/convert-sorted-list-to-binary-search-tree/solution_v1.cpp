class Solution {
public:
    TreeNode* build(vector<int>& arr, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = build(arr, left, mid - 1);
        root->right = build(arr, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;

        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }

        return build(arr, 0, arr.size() - 1);
    }
};