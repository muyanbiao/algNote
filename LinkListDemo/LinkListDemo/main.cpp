//
//  main.cpp
//  LinkListDemo
//
//  Created by yanbiaomu on 2020/10/27.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node { // 链表节点
    int data;
    node* next;
};

node *createLinkList(int array[], int arrCnt) {
    node *head;
    head = new node;
    head->next = NULL;
    
    node *pre;
    pre = head;
    
    node *newP;
    
    for (int i = 0; i < arrCnt; ++i) {
        newP = new node;
        newP->data = array[i];
        newP->next = NULL;
        pre->next = newP;
        pre = newP;
    }
    
    return head;
}

int main(int argc, const char * argv[]) {
    
    int array[6] = {6, 5, 4, 3, 2, 1};
    node *linkList = createLinkList(array, 6);
    linkList = linkList->next;
    while (linkList != NULL) {
        cout << linkList->data << " ";
        linkList = linkList->next;
    }
    
    cout << endl;
    return 0;
}
