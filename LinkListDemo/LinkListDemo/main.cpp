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

/// 创建链表
/// @param array 数据来源数组
/// @param arrCnt 数组元素个数
node *createLinkList(int array[], int arrCnt) {
    node *head, *pre, *current;
    
    // 先创建头结点，并让头结点指向NULL
    head = new node;
    head->next = NULL;
    
    // 把头结点赋值给前驱节点
    pre = head;
    
    for (int i = 0; i < arrCnt; i++) {
        // 循环创建节点
        current = new node;
        // 把数组元素array[i]依次赋值给新创建的节点，并把新节点的next置位NULL
        current->data = array[i];
        current->next = NULL;
        
        // 前驱节点的next指向新创建的节点，对i=0，相当于把头结点的next也指向了新创建的第一个节点
        pre->next = current;
        
        // 把新创建的节点赋值给前驱节点，为下一次节点创建做准备
        pre = current;
        
        // 思考一个问题：
        // 对于i=0，执行pre->next = current；之后的结果，就是，头结点的next也指向了current
        // 那对于i=n-1呢？最后一个节点创建成功之后，pre节点就等于当前节点，这算不算一个副作用呢？
        // 问题2：
        // 如果同时有两个指针p1,p2指向同一个节点，对其中一个节点调用free(p1)，会有什么结果呢？会不会导致这个节点的内存区域被释放掉，p2所指向的内存区域是不是就没有数据了？
    }
    
    return head;
}

/// 查找链表中元素x的个数
/// @param linkList 链表
/// @param x 值x
int searchLinkList(node *linkList, int x) {
    int cnt = 0;
    
    linkList = linkList->next;
    
    while (linkList != NULL) {
        if (linkList->data == x) {
            cnt++;
        }
        linkList = linkList->next;
    }
    
    return cnt;
}

/// 测试链表创建
void testCreate() {
    const int arrCnt = 5;
    int array[arrCnt] = {5, 3, 4, 1, 2};
    
    // 此时linkList指向的是链表的头结点
    node *linkList = createLinkList(array, arrCnt);
    
    // 让linkList指针指向第一个包含有效数据的节点
    linkList = linkList->next;
    
    // 从第一个包含有效数据的节点开始，依次遍历链表中的节点，知道linkList指向NULL为止
    while (linkList != NULL) {
        cout << linkList->data << " ";
        linkList = linkList->next;
    }
    
    cout << endl;
}

/// 测试链表的查找
void testSearch() {
    const int arrCnt = 6;
    int array[arrCnt] = {5, 3, 4, 1, 3, 2};
    
    // 此时linkList指向的是链表的头结点
    node *linkList = createLinkList(array, arrCnt);
    
    int elementToSearch = 3;
    
    int cnt = searchLinkList(linkList, elementToSearch);
    
    printf("count of element %d is %d", elementToSearch, cnt);
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    testSearch();
    
    return 0;
}
