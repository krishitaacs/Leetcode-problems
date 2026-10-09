/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *temp = head;

    // Check if there are at least k nodes
    for(int i = 0; i < k; i++)
    {
        if(temp == NULL)
            return head;

        temp = temp->next;
    }

    // Reverse k nodes
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    for(int i = 0; i < k; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // head is now the last node of reversed group
    head->next = reverseKGroup(curr, k);

    // prev is the new head of this group
    return prev;
}