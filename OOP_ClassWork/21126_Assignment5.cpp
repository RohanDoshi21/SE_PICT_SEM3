#include <iostream>
using namespace std;
class Inventory1
{
private:
    int code;
    int items;
    double price;

public:
    Inventory1(int code, int items, double price);
    void show()
    {
        cout << "Code: " << code << endl;
        cout << "Items: " << items << endl;
        cout << "Price: " << price << endl;
    }
    int getCode()
    {
        return code;
    }
    int getItems()
    {
        return items;
    }
    double getPrice()
    {
        return price;
    }
    operator double(){ // this is a type conversion
        return items*price;
    }
};

Inventory1::Inventory1(int code, int items, double price)
{
    this->code = code;
    this->items = items;
    this->price = price;
}

class Inventory2
{
private:
    int code;
    float value;
public:
    Inventory2(int code, float value);
    void show(){
        cout << "Code: " << code << endl;
        cout << "value: " << value << endl;
    }
    Inventory2(Inventory1 obj){
        this->code = obj.getCode();
        double price = obj.getPrice();
        int items = obj.getItems();
        this->value = price*items;
    }
};

Inventory2::Inventory2(int code = 0, float value = 0)
{
    this->code = code;
    this->value = value;
}


int main()
{
    Inventory1 obj(100, 5, 140.8);
    double totalValue;
    totalValue = obj;
    cout << totalValue << endl;
    Inventory2 obj2;
    obj2 = obj;
    obj2.show();
    return 0;
}