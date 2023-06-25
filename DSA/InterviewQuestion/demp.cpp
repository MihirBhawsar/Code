#include<iostream>

bool hasLoop(Node* head){
    Node * slow=head;
    Node * fast=head;

    while(fast!=nullptr){

        if(slow==fast){
            return true;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;

}

int main(){
    return 0;
}