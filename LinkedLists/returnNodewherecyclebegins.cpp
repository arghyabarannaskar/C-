Given a linked list, return the node where the cycle begins. If there is no cycle, return null. Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

Solution
Actually we can just use set.insert(key).second to check but it will take up O(n) space which is quite an awful waste, so here we just going to check the circle and then locate it.

If there is a circle then once the slow meets the fast the first time, there will be a formula as follows: a+b+kl = 2(a+b) -> kl-b = a (a is the length between the head and the start of the circle, b is the steps the slow pointer moves in the circle while l is the length of the circle).
After that we can reset the fast and slow down the fast (same speed as the slow using kl-b = a) then once they meet again, the location will be the start of the circle.
At last we take up constant space to solve this and traverse the linked list twice at most (as for the slow pointer).

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;   
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow != fast) return NULL;
    fast = head;
    while(fast && fast->next) {
        if(slow == fast) return slow;
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
}