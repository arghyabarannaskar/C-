/*You are given a linked list that contains N integers. You have performed the following reverse operation on the list:

Select all the subparts of the list that contain only even integers. For example, if the list is {1,2,8,9,12,16}, then the selected subparts will be {2,8}, {12,16}.
Reverse the selected subpart such as {8,2} and {16, 12}.
Now, you are required to retrieve the original list.*/


#include<iostream>
using namespace std;

class Node{
public:
    Node *pre;
    int data;
    Node *next;
};

class l_s{
private:
    Node *first,*last;
public :
    l_s(){
        first=NULL;
    }

    void ins(int k);
    void r_display();
    void del(){
        Node *p=first;
        while(first){
            first=first->next;
            p->next=NULL;
            delete p;
            p=first;
        }
        last=first=NULL;
    }
};

void l_s :: r_display(){
    Node *p=last;
    while(p){
        cout<<p->data<<" ";
        p=p->pre;
    }
}

void l_s :: ins(int k){
    Node *p=NULL,*q=NULL;
    if(first==NULL){
        first=new Node;
        first->data=k;
        first->next=NULL;
        first->pre=NULL;
        last=first;
    }else{
        p=new Node;
        p->data=k;
        p->pre=last;
        last->next=p;
        p->next=NULL;
        last=p;
    }
}


 
int main(){
    int n,k;
    cin>>n;
    l_s p;
    for(int i=0;i<n;i++){
    cin>>k;
    if(k%2==0){
        while(k%2==0&&i<n){
            p.ins(k);
            i++; 
            if(i<n)
            cin>>k;
        }
        p.r_display();
        p.del();
    }

    if(i<n)
        cout<<k<<" ";
    }
    return 0;
}