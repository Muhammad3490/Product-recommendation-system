#include "Product.h"

Product::Product()
{
    name = "";
    category = "";
    price = 0;
    colour = "";
}

Product::Product(string name, string category, int price,string colour)
{
    this->name = name;
    this->category = category;
    this->price = price;
    this->colour = colour;
}

string Product::getName()
{
    return name;
}

string Product::getCategory()
{
    return category;
}

int Product::getPrice()
{
    return price;
}

string Product::getColour()
{
    return colour;
}

void Product::setName(string name)
{
    this->name = name;
}

void Product::setCategory(string category)
{
    this->category = category;
}

void Product::setPrice(int price)
{
    this->price = price;
}

void Product::setColour(string colour)
{
    this->colour = colour;
}

