#include "List.h"
#include <iostream>

List::List() : count(0), head(nullptr) {}

List::~List()
{
    ListNode* current = head;
    while (current != nullptr)
    {
        ListNode* next = current->getNext();
        delete current;
        current = next;
    }
}
ListNode* List::getHead(){
    return head;
}

void List::insert(string name, int price)
{
    ListNode* newNode = new ListNode(name, price);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->setNext(head);
        head = newNode;
    }

    count++;
}

void List::update(string name, int price)
{
    ListNode* current = head;

    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            // Perform update operation as needed
            current->setPrice(price);
            return;
        }

        current = current->getNext();
    }

    std::cout << "Product not found in the list.\n";
}

void List::remove(string name)
{
    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            if (prev == nullptr)
            {
                // If the node to be deleted is the head
                head = current->getNext();
            }
            else
            {
                prev->setNext(current->getNext());
            }

            delete current;
            count--;
            return;
        }

        prev = current;
        current = current->getNext();
    }

    std::cout << "Product not found in the list.\n";
}

ListNode* List::search(string name)
{
    ListNode* current = head;

    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            // Return the matching ListNode
            return current;
        }

        current = current->getNext();
    }

    // If the product is not found in the list, return nullptr or handle it accordingly
    return nullptr;
}
void List::printList(ListNode *n){
    if(!n){
        return;
    }
    cout<<"\nName:"<<n->getName()<<"\n";
    cout<<"\nPrice:"<<n->getPrice()<<"\n";
    printList(n->getNext());

}
void List::recommendProducts(List* a, List* b) {
    // Finding the total length of both lists
    int totalCount = a->count + b->count;
    int browsedProductShare = static_cast<int>(0.7 * totalCount);
    int purchasedProductShare = totalCount - browsedProductShare;

    // Creating the recommended list
    ListNode *tempA = a->getHead();
    ListNode *tempB = b->getHead();
    List *newList = new List;

    for (int i = 0; i < browsedProductShare && tempA != nullptr; ++i) {
        newList->insert(tempA->getName(), tempA->getPrice());
        tempA = tempA->getNext();
    }

    for (int i = 0; i < purchasedProductShare && tempB != nullptr; ++i) {
        newList->insert(tempB->getName(), tempB->getPrice());
        tempB = tempB->getNext();
    }
    newList->printList(newList->getHead());
}

