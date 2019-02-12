//
//  main.cpp
//  ShoppingCart
//
//  Created by Caroline Telma on 2/10/19.
//  Copyright © 2019 Caroline Telma. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class ShoppingCart {
    
public:
    int items;
    map<string, double> MyMap; //Construct new, empty map.
    map<string, double>::iterator it;
    double sales_tax = 0.085; //NYC sales tax amount taken from: https://www.usatoday.com/story/money/taxes/2018/03/27/states-highest-and-lowest-sales-taxes/452512002/
    
    ShoppingCart()
    {
        items = 0; //initilize cart to 0 items to mirror an empty shopping cart"
    }
    
    //Method for number of items in the cart
    void GetItems()
    {
        cout << "Number of items in cart: " << items << endl;
        cout << endl << endl; //create blank lines at the end of the method
    }
    
    //Method to add items to shopping cart
    void AddItems (string name_of_item, int number_of_items, double price)
    {
  
        cout << "What would you like to add to your shopping cart? " << endl;
        cin >> name_of_item;
        
        cout << "What is the price of " << name_of_item << "?" << endl;
        cin >> price;
        
        MyMap.insert(pair<string, double> (name_of_item, price));
        
        cout << "How many " << name_of_item << " are you adding to your cart? " << endl;
        cin >> number_of_items;
        
        items += number_of_items;
        
        cout << "You have added " << number_of_items << " " << name_of_item << " to your shopping cart!" << endl;
        cout << endl << endl; //create blank lines at the end of the method
    }
    
    //Method to remove items from cart
    void RemoveItems(string name_of_item, int number_of_items)
    {
        cout << "What would you like to remove from your shopping cart? " << endl;
        cin >> name_of_item;

        it = MyMap.find(name_of_item);
        if( it != MyMap.end())
        {
            MyMap.erase(it); //remove particular item from list
        }
        else if (it == MyMap.end())
        {
            cout << "You do not have " << name_of_item << " in your cart. Unable to remove!" << endl;
            cout << endl << endl; //create blank lines at the end of the method
        }
        else if (number_of_items > 0)
        {
            cout << "How many " << name_of_item << " are you removing from your cart? " << endl;
            cin >> number_of_items;
            cout << endl << endl; //create blank lines at the end of the method
        }
        else {
        items -= number_of_items;
        
        cout << "You have removed " << number_of_items << " " << name_of_item << " from your shopping cart " << endl;
        cout << endl << endl; //create blank lines at the end of the method
        }
        
    }
    
    //Method to clear the cart
    void ClearCart()
    {
        items = 0; //set number of items to 0
        MyMap.clear(); //clear map
        cout << "Your cart is now empty!" << endl;
        cout << endl << endl; //create blank lines at the end of the method
    }
    
    //Method to list items in the cart
    void ListItems()
    {
        if (items == 0)
        {
            cout << "There are no items to list... cart is empty!" << endl; //print out message when the cart is empty
            cout << endl; //create blank at the end of the method
        }
        else {
           
            for (const auto &p : MyMap) {
                cout << "Name of item: " << p.first << "\n" << "Price per item: $" << p.second << '\n';
            }
        }
        cout << endl << endl; //create blank lines at the end of the method
        
        
    }
    
    //Method to calculate total cost
   void CalculateTotalCost()
    {
        if (items == 0)
        {
            cout << "Cart is empty!" << endl; //print out message when the cart is empty
            cout << endl; //create blank at the end of the method
        }
        else
        {
            
            for (const auto &p : MyMap)
            {
                cout << "Total cost (including sales tax): $" << (p.second * items) + ((p.second * items) * sales_tax) << endl;
                break;
            }
            cout << endl << endl; //create blank lines at the end of the method
            
            
        }
        
    }
    
    //Method to calculate total cost with sales tax
    void CalculateSalesTax()
    {
        
        if (items == 0)
        {
            cout << "Cart is empty!" << endl; //print out message when the cart is empty
            cout << endl; //create blank at the end of the method
        }
        else
        {
            
            for (const auto &p : MyMap)
            {
                
                cout << "Total sales tax on items in the cart: $" << (p.second * items) * sales_tax << endl;
                break;
            }
            cout << endl << endl; //create blank lines at the end of the method
        }
        
    }
    
    //Method to apply discount
    void ApplyDiscount(string name_of_item, double discount)
    {
        cout << "What would you like to apply a discount to?" << endl;
        cin >> name_of_item;
        
        it = MyMap.find(name_of_item);
        if( it != MyMap.end())
        {
            cout << "What is the amount of the discount you'd like to apply (enter in dollars and cents)?" << endl;
            cin >> discount;
            
            for (const auto &p : MyMap)
            {
                cout << "Your new total (including sales tax) after all discounts are applied is: " << ((p.second * items) + ((p.second * items) * sales_tax)) - discount << endl;
                break;
            }
            cout << endl << endl; //create blank lines at the end of the method
            
        }
        
        else if (it == MyMap.end())
        {
            cout << "You do not have " << name_of_item << " in your cart. Unable to apply a discount!" << endl;
            cout << endl << endl; //create blank lines at the end of the method
        }
    }
    
    //Method to apply buy-one-get-one free discount
    void BuyOneGetOne(string name_of_item)
    {
        cout << "What item would you like to buy and get one free?" << endl;
        cin >> name_of_item;
        
        it = MyMap.find(name_of_item);
        if( it != MyMap.end())
        {
            
            for (const auto &p : MyMap)
            {
                cout << "Your new total (including sales tax) after buy-one-get-obne free is applied is: " << ((p.second * items) + ((p.second * items) * sales_tax)) - p.second << endl;
                break;
            }
            cout << endl << endl; //create blank lines at the end of the method
            
        }
        
        else if (it == MyMap.end())
        {
            cout << "You do not have " << name_of_item << " in your cart. Unable to apply buy-one-get-one free!" << endl;
            cout << endl << endl; //create blank lines at the end of the method
        }
    }
    
    //Method to set custom state tax
    void SetStateTax(string state_name)
    {
        cout << "What state do you live in?" << endl;
        cin >> state_name;
        
        cout << "What is your states sales tax (please enter tax amount as a decimal)? " << endl;
        cin >> sales_tax;
    }
    
};

int main(int argc, const char * argv[]) {
    
    ShoppingCart myCart; //create instance of class
   
    //initialize all variables here
    int choice = 0;
    string name = " ";
    int number = 0;
    double price = 0.0;
    
    while(choice != 10) //program runs until user enters '10' to quit
    {
        //Welcome user and output a menu of options
        cout << "Welcome to your shopping cart. Here is a menu of optioms: " << endl;
        cout << "Press '0' to view number of items in your cart: " << endl;
        cout << "Press '1' to add items to your cart: " << endl;
        cout << "Press '2' remove items from your cart: " << endl;
        cout << "Press '3' to list items in your cart: " << endl;
        cout << "Press '4' to clear the cart: " << endl;
        cout << "Press '5' to calculate total cost of items in the cart: " << endl;
        cout << "Press '6' to calculate sales tax on items in the cart: " << endl;
        cout << "Press '7' to apply a discount to an item in the cart: " << endl;
        cout << "Press '8' to apply a 'buy one get one free' discount: " << endl;
        cout << "Press '9' to apply sales tax based on buyer's geographicl state: " << endl;
        cout << "Press '10' to quit: " << endl;
        cin >> choice;
        
        //Call different methods based on user's selection
        switch (choice)
        {
            case 0:
                myCart.GetItems();
                break;
            case 1:
                myCart.AddItems(name, number, price);
                break;
            case 2:
                myCart.RemoveItems(name, number);
                break;
            case 3:
                myCart.ListItems();
                break;
           case 4:
                myCart.ClearCart();
                break;
            case 5:
                myCart.CalculateTotalCost();
                break;
            case 6:
                myCart.CalculateSalesTax();
                break;
            case 7:
                myCart.ApplyDiscount(name, price);
                break;
            case 8:
                myCart.BuyOneGetOne(name);
                break;
            case 9:
                myCart.SetStateTax(name);
                break;
        }
    }
    return 0;
}
