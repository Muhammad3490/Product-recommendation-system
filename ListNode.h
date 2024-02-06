#include <iostream>
#include "string"

using namespace std;

class ListNode
{
public:
    ListNode(string name, int price);
    ListNode();
    ~ListNode();

    ListNode* getNext();
    void setNext(ListNode* nextNode);

    std::string getName();
    int getPrice();

    void setName(string name);
    void setPrice(int price);

private:
    ListNode* next;
    std::string name;
    int price;
};
