Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.



ListNode* reverseBetween(ListNode* head, int m, int n){
    Node *newhead, *tail;
}












Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

Solution
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode newHead(0);
    newHead.next = head;
    ListNode *pre = &newHead, *cur = head, *next = NULL;
    int i = 1;
    while(i < n) {
        if(i++ < m) { pre = cur; cur = cur->next; }
        else { 
            next = cur->next; 
            cur->next = cur->next->next; 
            next->next = pre->next; 
            pre->next = next; 
        }
    }
    return newHead.next;
}