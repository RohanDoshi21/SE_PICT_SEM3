// !Author: Rohan Doshi
// ? Problem statement

/*
Design a structure BIGBAZAR to store order information. Each 
order information has an 11-character item code, 20- character 
item name, price and an integer quantity. Provide the following 
member functions in a class:- 
• 1. functions to read these records from standard input 
getdata(), 
• 2. to calculate the total price calculate() 
• 3. sort functions to arrange data by ItemCode sort(), 
• 4. to display the same and display the totalprice display(). 
• Also use function displaycount() to display the number of 
records. 
*/

#include <iostream>
using namespace std;

class BIGBAZAR
{
    string itemCode, itemName;
    float price;
    int quantity;

public:
    void getdata(string itemCodeParameter, string itemNameParameter, float priceParameter, int quantityParameter){
        itemCode = itemCodeParameter;
        itemName = itemNameParameter;
        price = priceParameter;
        quantity = quantityParameter;
    }
    float calculate(){
        return price*quantity;
    }
    int displaycount(){
        return quantity;
    }

};
int main()
{

    return 0;
}