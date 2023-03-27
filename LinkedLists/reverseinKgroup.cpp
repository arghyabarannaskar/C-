Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is. You may not alter the values in the nodes, only nodes itself may be changed. Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Solution
ListNode* reverseKGroup(ListNode* head, int k) {
	if(!head || !head->next) return head;
	ListNode newHead(0);
	ListNode *pre = &newHead, *cur = head, *next = NULL;
	newHead.next = head;
	int len = 0;
	for(ListNode *p = head; p; p = p->next) len++;
	int times = len/k;
	while(times) {
		for(int i = 1; i < k; ++i) {
			next = cur->next;
			cur->next = cur->next->next;
			next->next = pre->next;
			pre->next = next;
			if(i == k-1) {
				pre = cur;
				cur = cur->next;
			}
		}
		times--;
	}
	return newHead.next;
}