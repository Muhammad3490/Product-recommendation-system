#include "Product.h"
class Node
{
public:
    Node();
    Node(string name, string category, int price, string colour);
    ~Node();
    Node* getLeft();
    Node* getRight();
    void setLeft(Node *n);
    void setRight(Node *n);
    Product* getProduct();
    void printInfo();
    void showProduct();



private:
    Node* right;
    Node* left;
    Product *product;
};

