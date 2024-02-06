#include "Node.h"
class BST
{
public:
    BST();
    ~BST();
    Node* getRoot();
    void  setRoot(Node* n);
    void insert(string name, string category, int price, string colour);
    Node* search(string name, string category, string colour, int price);
    void update(string name,string category, string colour, int price);
    void del(string name, string category, string colour, int price);
    void inOrder(Node* n);
    void findMaximum();
    void findMinimum();
    void inOrderCategory(Node* n, string category);
    Node* searchPrice(int price,string name);
    Node* searchName(Node *n,string name);


private:
    Node* root;
    int count;

};

