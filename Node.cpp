#include "Node.h"
Node::Node()
{
    left = NULL;
    right = NULL;
    product = new Product;
}

Node::Node(string name,string category,int price, string colour)
{
    left = NULL;
    right = NULL;
    product = new Product(name,category,price,colour);
}

Node::~Node()
{
}

Node*Node:: getLeft()
{
    return left;
}

Node* Node::getRight()
{
    return right;
}

void Node::setLeft(Node *n)
{
    left = n;
}

void Node::setRight(Node* n)
{
    right = n;
}

Product* Node::getProduct()
{
    return product;
}

void Node::printInfo()
{
    cout << "Product Name : " << product->getName() << endl;
    cout << "Product Category : " << product->getCategory() << endl;
    cout << "Product Price : " << product->getPrice() << endl;
    cout << "Product Colour : " << product->getColour() << endl << endl;
}
void Node::showProduct() {
    cout << "\nName :" << product->getName() << "\n";
    cout << "\nPrice :" << product->getPrice() << "\n";

}
