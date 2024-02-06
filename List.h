#include "ListNode.h"

class List {
private:
    int count;
    ListNode* head;

public:
    List();
    ~List();
    ListNode* getHead();
    void insert(string name, int price);
    void update(string name, int price);
    void remove(string name);
    ListNode* search(string name);
    void printList(ListNode *n);
    void recommendProducts(List *a,List *b);

    // Additional methods as needed
};