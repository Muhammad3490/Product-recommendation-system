#include "ListNode.h"
ListNode::ListNode(string name, int price) : next(nullptr), name(name), price(price) {}

ListNode::~ListNode()
{
    // Implement destructor if needed
}

ListNode* ListNode::getNext()
{
    return next;
}

void ListNode::setNext(ListNode* nextNode)
{
    next = nextNode;
}

std::string ListNode::getName()
{
    return name;
}

int ListNode::getPrice()
{
    return price;
}

void ListNode::setName(string newName)
{
    name = newName;
}

void ListNode::setPrice(int newPrice)
{
    price = newPrice;
}