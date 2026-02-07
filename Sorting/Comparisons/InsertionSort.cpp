struct ListNode {       // Definition for singly-linked list.
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (!head) return nullptr;

    ListNode* sorted = nullptr;          // new sorted list

    while (head) {
        ListNode* cur = head;            // node to insert
        head = head->next;               // advance original list

        // Insert `cur` into the sorted list at the right spot
        if (!sorted || cur->val < sorted->val) {
            cur->next = sorted;
            sorted = cur;
        } else {
            ListNode* p = sorted;
            while (p->next && p->next->val < cur->val)
                p = p->next;
            cur->next = p->next;
            p->next = cur;
        }
    }
    return sorted;
};