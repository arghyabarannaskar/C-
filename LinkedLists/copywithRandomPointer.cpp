Copy List with Random Pointer
linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

test

Solution
Recursive
class Solution {
    unordered_map<RandomListNode*, RandomListNode*> cloneMap;
    RandomListNode *helper(RandomListNode* head){
        if(head == NULL) return NULL;
        if(cloneMap.count(head)) return cloneMap[head];
        RandomListNode *cloned = new RandomListNode(head->label);
        cloneMap[head] = cloned; //crucial;
        cloned->next = helper(head->next);
        cloned->random = helper(head->random);
        return cloned;
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return helper(head);
    } 
};
Iterative
RandomListNode *copyRandomList(RandomListNode *head) {
	RandomListNode newHead(0), *p = head, *t = NULL;
	while(p) {
		RandomListNode *cloned = new RandomListNode(p->label);
		cloned->next = p->next;
		p->next = cloned;
		p = cloned->next;
	}
	p = head;
	while(p && p->next) {
		if(p->random) p->next->random = p->random->next;
		p = p->next->next;
	}
	p = head;
	t = &newHead;
	while(p && p->next) {
		t->next = p->next;
		p->next = p->next->next;
		t = t->next;
		p = p->next;
	}
	t->next = NULL;
	return newHead.next;
}