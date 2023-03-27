Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.



//MYCODE:

ListNode* rotateRight(ListNode* head, int k){
    if(!head)
        return head;
    ListNode *curr = head;
    int len = 0;
    while(curr){
        len++;
        curr = curr->next;
    }
    k = k % len;   //in case the value of k is larger than the lenghth of the linked list 
    int pos = len - k;
    for (int i = 1; i < pos;i++){
        curr = curr->next;
    }

    ListNode *newhead = curr->next;
    curr->next = NULL;
    curr = newhead;
    while(curr->next != NULL){   //reaching the last node
        curr = curr->next;  
    }
    curr->next = head;
    reuturn newhead;
}









Solution
ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    int len = 1;
    ListNode *p = head;
    while(p->next) { len++; p = p->next; }
    p->next = head;
    if(k %= len)
        for(int i = 0; i < len-k; ++i, p=p->next) ; 
    ListNode* newHead = p->next;
    p->next = NULL;
    return newHead;
}