void linkedList::reverse(){
    node *prev = NULL, *curr, *next;
    curr = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}