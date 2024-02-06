#include "BST.h"
#include "List.h"
int main(){
    BST shop;
    shop.insert("Shirt1","T Shirt",1000,"Black");
    shop.insert("Shirt2","T Shirt",1100,"Black");
    shop.insert("Shirt3","T Shirt",1200,"Black");
    shop.insert("Shirt4","T Shirt",1300,"Black");
    shop.insert("Shirt5","T Shirt",1000,"Black");
    shop.insert("Shirt6","T Shirt",1000,"Black");
    shop.insert("Shirt7","T Shirt",1600,"Black");

    shop.insert("Pants1","Pants",2000,"Black");
    shop.insert("Pants2","Pants",2200,"Black");
    shop.insert("Pants3","Pants",2300,"Black");
    shop.insert("Pants4","Pants",2400,"Black");

    string cat;
    cout<<"Enter the category to browse product";
    cin>>cat;
    shop.inOrderCategory(shop.getRoot(),cat);
    List *browseList = new List;
    int price = 1;
    string name;
    do {
        cout << "\nEnter the price & name of the product to see details \n";
        cout << "\nOr enter 0 to exit\n";
        cin >> price;
        cin>>name;

        if (price != 0 && name!="") {
            Node *address = shop.searchPrice(price,name);
            if (address != NULL) {
                browseList->insert(address->getProduct()->getName(), address->getProduct()->getPrice());
                address = NULL;
            } else {
                cout << "Product not found.\n";
            }
        }
    } while (price != 0);
    cout<<"\nEnter 1 to see browse history or 0 to continue :"<<"\n";
    cin>>price;
    if(price==1){
        browseList->printList(browseList->getHead());
    }

    int c = 1; // Initialize c to a non-zero value to enter the loop
    List* purchaseList = new List;

    cout << "Purchase products**********************\n";
    while (c != 0) {
        cout << "Press 1 to purchase products or press 0 to exit\n";
        cin >> c;

        if (c == 0) {
            cout << "Exiting the purchase process.\n";
            break;
        } else if (c != 1) {
            cout << "Invalid input. Please enter 1 to purchase or 0 to exit.\n";
            continue;
        }

        cout << "Enter the price && name of the product to purchase (separated by space)\n";
        cin >> price >> name;

        cout << "Purchase details:\n";
        Node* address = shop.searchPrice(price, name);

        if (address != NULL) {
            int input;
            cout << "Enter the cash to purchase\n";
            cin >> input;

            if (input == price) {
                purchaseList->insert(address->getProduct()->getName(), address->getProduct()->getPrice());
                cout << "Purchase successful!\n";
            } else {
                cout << "Incorrect cash amount. Purchase failed.\n";
            }
        } else {
            cout << "Product not found. Purchase failed.\n";
        }
    }
    int a;
    cout<<"Enter 1 to view recommended products or press 0 to exit\n";
    cin>>a;
    if(a==1){
        cout<<"Printing the recommended list\n";
        browseList->recommendProducts(browseList,purchaseList);


    }
    // Add any necessary cleanup code

    return 0;

}