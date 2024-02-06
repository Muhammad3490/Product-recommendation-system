#include "BST.h"

BST::BST()
{
    root = NULL;
    count = 0;
}

BST::~BST()
{
}

Node* BST::getRoot()
{
    return root;
}
void  BST::setRoot(Node* n) {
    root = n;
}


void BST::insert(string name, string category, int price, string colour)
{
    //first create a node with the given parameters
    Node* newNode = new Node(name, category, price, colour);

    //if their is no node and root is empty
    if (root == NULL)
    {
        root = newNode;
        count++;
        return;
    }

    //if root is not null then

    Node* temp = root;
    while (temp != NULL)
    {
        if (newNode->getProduct()->getPrice() > temp->getProduct()->getPrice())
        {
            if (temp->getRight() == NULL)
            {
                temp->setRight(newNode);
                count++;
                return;
            }
            else
            {
                temp = temp->getRight();
            }
        }
            // If price is less or equal in both cases we set it on left side
            // So we don't need to write any condition for this
        else
        {
            if (temp->getLeft() == NULL)
            {
                temp->setLeft(newNode);
                count++;
                return;
            }
            else
            {
                temp = temp->getLeft();
            }
        }
    }
}

// Search Function from price
Node* BST::search(string name, string category, string colour, int price)
{
    if(root==NULL)
    {
        cout<<"Store is Empty"<<endl;
        return NULL;
    }
    else
    {
        Node*temp=root;
        while(temp!=NULL)
        {
            if(temp->getProduct()->getPrice()>price)
            {
                temp=temp->getLeft();
            }
            else if(temp->getProduct()->getPrice()<price)
            {
                temp=temp->getRight();
            }
            else
            {
                do
                {
                    if (temp->getProduct()->getCategory() == category && temp->getProduct()->getColour() == colour)
                    {
                        return temp;
                    }
                    else
                    {
                        temp = temp->getLeft();
                    }
                } while (temp->getProduct()->getCategory() != category && temp->getProduct()->getColour() != colour);
            }
        }
        cout << "Nothing Found\n";
        return NULL;
    }
}
//searching the product by price
Node* BST::searchPrice(int price, string name) {
    if (root == NULL) {
        cout << "\nShop is empty \n";
        return NULL;
    }

    Node* temp = root;
    while (temp != NULL) {
        if (price == temp->getProduct()->getPrice() && name == temp->getProduct()->getName()) {
            cout << "\n\nProduct details\n";
            cout << "**********************************\n";
            temp->printInfo();
            return temp;
        } else if (price == temp->getProduct()->getPrice()) {
            // If prices are the same but names are different, check the left subtree
            temp = temp->getLeft();
        } else if (price < temp->getProduct()->getPrice()) {
            temp = temp->getLeft();
        } else {
            temp = temp->getRight();
        }
    }

    cout << "\nNo product found\n";
    return NULL;
}




void BST::update(string name, string category, string colour, int price)
{
    if (root == NULL)
    {
        cout << "Store is Empty\n";
    }
    else
    {
        Node* temp = root;
        bool found = false;

        while (temp != NULL)
        {
            if (price > temp->getProduct()->getPrice())
            {
                temp = temp->getRight();
            }
            else if (price < temp->getProduct()->getPrice())
            {
                temp = temp->getLeft();
            }
            if (temp->getProduct()->getCategory() == category && temp->getProduct()->getColour() == colour)
            {
                found = true;
                break;
            }
            else
            {
                temp = temp->getLeft();
            }
        }

        if (found == true)
        {
            int answer;
            do
            {
                cout << "Press 1 to update Product's Name\n";
                cout << "Press 2 to update Product's Category\n";
                cout << "Press 3 to update Product's Colour\n";
                cin >> answer;
                if (answer != 1 && answer != 2 && answer != 3)
                {
                    cout << "You enter wrong key\n";
                    cout << "Enter the correct key\n";
                }
            } while (answer != 1 && answer != 2 && answer != 3);

            switch (answer)
            {
                case 1 :
                {
                    string newName;
                    cout << "Enter New Name\n";
                    cin >> newName;

                    cout << "Name updated from " << temp->getProduct()->getName() << " to " << newName << endl;
                    temp->getProduct()->setName(newName);
                    return;
                }
                case 2 :
                {
                    string newCategory;
                    cout << "Enter New Category\n";
                    cin >> newCategory;

                    cout << "Category updated from " << temp->getProduct()->getCategory() << " to " << newCategory << endl;
                    temp->getProduct()->setCategory(newCategory);
                    return;
                }
                case 3 :
                {
                    string newColour;
                    cout << "Enter New Colour\n";
                    cin >> newColour;

                    cout << "Colour updated from " << temp->getProduct()->getColour() << " to " << newColour << endl;
                    temp->getProduct()->setCategory(newColour);
                    return;
                }
                default:
                    return;
            }
        }
        if (!found)
        {
            cout << "Nothing Found\n";
        }
    }
}

void BST::inOrder(Node* n)
{
    if (!n)
    {
        return;
    }
    else
        inOrder(n->getLeft());
    n->printInfo();
    inOrder(n->getRight());
}
void BST::inOrderCategory(Node* n, string category)
{
    if (!n)
    {
        return;
    }

    inOrderCategory(n->getLeft(), category);

    // Check if the current product's category matches the specified category
    if (n->getProduct()->getCategory() == category)
    {
        cout << "\nAvailable product in " << category << " categroy \n";
        n->showProduct();
    }

    inOrderCategory(n->getRight(), category);
}


//code for swap two pointers.
void swapPointers(Node*& curr, Node*& temp)
{
    Node* tempPtr = curr;
    curr = temp;
    temp = tempPtr;
}

void BST::del(string name, string category, string colour, int price)
{
    if (root == NULL)
    {
        cout << "Tree is Empty\n";
    }
    else
    {
        Node* current = root;
        Node* parent = NULL;

        while (current != NULL)
        {
            if (current->getProduct()->getCategory() == category && current->getProduct()->getColour() == colour)
            {
                break;
            }
            else if (price > current->getProduct()->getPrice())
            {
                parent = current;
                current = current->getRight();
            }
            else
            {
                parent = current;
                current = current->getLeft();
            }
        }

        // Case 1 : Node with 0 Child
        if (current->getLeft() == NULL && current->getRight() == NULL)
        {
            if (parent->getRight() == current)
            {
                parent->setRight(NULL);
                delete current;
                cout << "Node Deleted\n";
                return;
            }
            else if (parent->getLeft() == current)
            {
                parent->setLeft(NULL);
                delete current;
                cout << "Node Deleted\n";
                return;
            }
            else
            {
                cout << "Not Found\n";
                return;
            }
        }

        // Case 2 : Node with single Child
        if (current->getLeft() != NULL && current->getRight() == NULL)
        {
            if (parent->getLeft() == current)
            {
                parent->setLeft(current->getLeft());
                delete current;
                cout << "Node Deleted\n";
                return;
            }
            else if (parent->getRight() == current)
            {
                parent->setRight(current->getLeft());
                delete current;
                cout << "Node Deleted\n";
                return;
            }
            else
            {
                cout << "Not Found\n";
            }
        }
        else if (current->getLeft() == NULL && current->getRight() != NULL)
        {
            if (parent->getLeft() == current)
            {
                parent->setLeft(current->getRight());
                delete current;
                cout << "Node Deleted\n";
                return;
            }
            else if (parent->getRight() == current)
            {
                parent->setRight(current->getRight());
                delete current;
                cout << "Node Deleted\n";
                return;
            }
            else
            {
                cout << "Not Found\n";
            }
        }

        // Case 3 : Node with both childs
        Node* temp = current->getLeft();
        Node* checker = temp;

        while (checker->getRight() != NULL)
        {
            temp = checker;
            checker = checker->getRight();
        }

        swapPointers(current, checker);

        temp->setRight(NULL);
        delete checker;
        cout << "Node Deleted\n";
        return;
    }
}

void BST::findMaximum()
{
    if (root == NULL)
    {
        cout << "\n Store is empty \n";
        return;
    }
    else
    {
        Node* temp = root;
        while (temp->getRight() != NULL)
        {
            temp = temp->getRight();
        }
        cout << "The product with the maximum price in the store is \n";
        cout << temp->getProduct()->getName() << endl;
        cout << temp->getProduct()->getCategory() << endl;
        cout << temp->getProduct()->getPrice() << endl << endl;
    }
}


void BST::findMinimum()
{
    if (root == NULL)
    {
        cout << "\n Store is empty \n";
        return;
    }
    else
    {
        Node* temp = root;
        while (temp->getLeft() != NULL)
        {
            temp = temp->getLeft();
        }
        cout << "The product with the minimum price in the store is \n";
        cout << temp->getProduct()->getName() << endl;
        cout << temp->getProduct()->getCategory() << endl;
        cout << temp->getProduct()->getPrice() << endl << endl;
    }
}
Node* BST::searchName(Node* n,string name) {
    if (!n) {
        return NULL;  // If the node is not found, return NULL
    }

    // Compare the target name with the current node's name
    int compareResult = name.compare(n->getProduct()->getName());

    // Check if the names are equal
    if (compareResult == 0) {
        cout << "\nFound\n";
        return n;
    }

    // If the target name is less than the current node's name, search in the left subtree
    if (compareResult < 0) {
        return searchName(n->getLeft(), name);
    } else {
        // If the target name is greater than the current node's name, search in the right subtree
        return searchName(n->getRight(), name);
    }
}




