//input: 1->2->2->3->3->3->3->NULL
//output: 1->2->3->NULL




SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) { //llist contains address of head node
    SinglyLinkedListNode *curr = llist, *temp;
    while(curr!= NULL){
        if(curr->next != NULL){
        while(curr->data == curr->next->data){    //Think step by step and draw diagram of each step
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
            if(curr->next == NULL)
                break;
        }
        }
        curr = curr->next;
    }
    return llist;
}