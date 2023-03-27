

/*Given a pointer to the head of a linked list and a specific position, determine the data value at that position. Count backwards from the tail node. The tail is at postion 0, its parent is at 1 and so on.

Example
head refers to 3->2->1->0->NULL
positonFromTail 2 

will return the value 2.

Each of the data values matches its distance from the tail. The value 2 is at the desired position.

Function Description

Complete the getNode function in the editor below.

getNode has the following parameters:

SinglyLinkedListNode pointer head: refers to the head of the list
int positionFromTail: the item to retrieve
Returns

int: the value at the desired position*/




int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int length = 0;
    SinglyLinkedListNode*curr = llist;
    while(curr != NULL){
        length ++;
        curr = curr->next;
    }
    positionFromTail = length - positionFromTail;   //position from head(starts at 1) = length - position from tail(starts count from 0)
    curr = llist;
    length = 0;
    while(curr != NULL){
        length++;
        if(length == positionFromTail)
            return curr->data;
        curr = curr->next;
    }
    return 0;
}