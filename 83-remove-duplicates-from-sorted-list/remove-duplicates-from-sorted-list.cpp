class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Linked List → Array
        vector<int> arr;

        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Remove duplicates from sorted array
        vector<int> unique;

        for (int i = 0; i < arr.size(); i++) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                unique.push_back(arr[i]);
            }
        }

        // Array → Linked List
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        for (int x : unique) {

            ListNode* node = new ListNode(x);

            if (newHead == nullptr) {
                newHead = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }

        return newHead;
    }
};