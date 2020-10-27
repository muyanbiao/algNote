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

/// 从数组中创建链表
/// @param Array 数据来源数组
node *createLinkList(int Array[], int arrCount) {
    node *head;
    node *pre;
    node *current;
    
    head = new node;
    head->next = NULL;
    
    pre = head;
    
    for (int i = 0; i < arrCount; i++) {
        current = new node;         // 新建节点
        current->data = Array[i];   // Array[i]赋值给新节点数据域
        current->next = NULL;       // 新节点的next指针域设置为NULL
        pre->next = current;        // pre-next设置为当前节点，当i=0的时候，这个赋值导致head->next也是current
        pre = current;              // 前驱节点pre设置为current，为下一次节点创建做准备，即：当前节点为下一个节点的前驱节点
    }
    
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arrCnt = 6;
    int Array[6] = {6, 5, 4, 3, 2, 1};
    
    node *linkList = createLinkList(Array, arrCnt);
    
    linkList = linkList -> next;
    
    while (linkList != NULL) {
        printf("%d ", linkList->data);
//        cout << linkList->data << " ";
        linkList = linkList->next;
    }
    
    return 0;
}
