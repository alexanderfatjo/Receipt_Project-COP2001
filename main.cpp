#include <iostream>
#include "header.h"
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    do{
        //prints menu
        print_menu();
        cin >> user_choice;
        switch (user_choice)
        {
        case 1:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.cheeseburgers;
            customer.total = (item_prices.cheeseburgers * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 2:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.hamburgers;
            customer.total = (item_prices.hamburgers * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 3:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.chicken_tenders;
            customer.total = (item_prices.chicken_tenders * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 4:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.boneless_wings;
            customer.total = (item_prices.boneless_wings * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 5:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.wings;
            customer.total = (item_prices.wings * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 6:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.grilled_cheese;
            customer.total = (item_prices.grilled_cheese * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 7:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.regular_fries;
            customer.total = (item_prices.regular_fries * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 8:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.cajun_fries;
            customer.total = (item_prices.cajun_fries * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 9:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.medium_drink;
            customer.total = (item_prices.medium_drink * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        case 10:
            cout << "Order Quantity: " <<endl;
            cin >> customer.item_quantity;
            customer.menu_item = item_name.large_drink;
            customer.total = (item_prices.large_drink * customer.item_quantity);
            total_order_prices.push_back(customer);
            break;
        default:
            cout << "Sorry that is not a menu choice" << endl;
            break;
        }
    }while (!check_for_exit());
    for (const auto &f : total_order_prices){
        cout << f.item_quantity << " X " << f.menu_item << " = $" << f.total << endl;
        sub_total +=f.total; //Adds the total price for each item including its quantity to a subtotal
    }
    //after order is complete, moves onto the receipt
    print_discounts();//prints discount options
    cin >> eligible_discount;
    //each case is set to a specific discount type
    switch(eligible_discount){
    case 1:
        active_discount = 0.050;
        receipt_calculations();
        print_receipt();
        break;
    case 2:
        active_discount = 0.080;
        receipt_calculations();
        print_receipt();
        break;
    case 3:
        active_discount = 0.025;
        receipt_calculations();
        print_receipt();
        break;
    case 4:
        active_discount = 0.040;
        receipt_calculations();
        print_receipt();
        break;
    case 5:
        active_discount = 0.000;
        receipt_calculations();
        print_receipt();
        break;
    default:
        //if user inputs an invalid response, no discount is assumed
        active_discount = 0.000;
        receipt_calculations();
        print_receipt();
        break;
    }
    customer_payment();
    exit(1);
}
