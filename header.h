#ifndef RECEIPT_PROJECT_H
#define RECEIPT_PROJECT_H
#include <iostream>
#include <string>
#include <array>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

//global variables:
int user_choice = 0;
//total before tax and discount(raw order total)
float sub_total = 0.00;
//for discount choices
int eligible_discount = 0;
//for the amount of money that is discounted from subtotal(before tax)
float price_discounted = 0.00;
//for declaring there will be a discount
float active_discount = 0.00;
float tax_rate = 0.089;
//for total amount needed for payment
float final_total = 0.00;
float tax = 0.00;

//for customer payment
double payment = 0.00;
double payment_amount = 0.00;
double amount_due = 0.00;
double customer_change = 0.00;

//recycled code from class
bool check_for_exit() {
    // Ask if they want to leave and leave on "n"
    // Returns true if they want to exit, false if still want to continue
    std::string leave = "n"; // Leave flag - checked at end, "n" leaves loop
    std::cout << "\nContinue?(y/n) ";
    std::cin >> leave;
    if (leave[0] == 'n' || leave[0] == 'N') {
        return true;
    }
    return false;
}

//structure holds the name of each item
struct menu_item_names
{
   string cheeseburgers = "Cheeseburger";
   string hamburgers = "Hamburger";
   string chicken_tenders = "Chicken Tenders";
   string boneless_wings = "Boneless Wings";
   string wings = "Wings";
   string grilled_cheese = "Grilled Cheese";
   string regular_fries = "Regular Fries";
   string cajun_fries = "Cajun Fries";
   string medium_drink = "Medium Drink";
   string large_drink = "Large Drink";
};

//structure holds the price of each item
struct menu_item_prices
{
   double cheeseburgers = 7.99;
   double hamburgers = 7.49;
   double chicken_tenders = 6.99;
   double boneless_wings = 8.99;
   double wings = 9.99;
   double grilled_cheese = 5.49;
   double regular_fries = 3.49;
   double cajun_fries = 4.49;
   double medium_drink = 2.99;
   double large_drink = 3.49;
};

//strcuture for holding live total and menu items
struct order{
    double total = 0.00;
    string menu_item = "";
    int item_quantity = 0;
};

//for customer order total
vector<order> total_order_prices{};
menu_item_prices item_prices{};

//for storing customers order items
vector<menu_item_names> total_item_name{};

//for getting item name
menu_item_names item_name{};

order customer{};

//array holds all menu items
const std::array<std::string, 10> choices = { "Cheeseburger", "Hamburger", "Chicken Tenders", "Boneless Wings", "Wings", "Grilled Cheese", "Regular Fries", "Cajun Fries", "Medium Drink", "Large Drink"
};

//recycled code from function assignment
void print_menu(){
// prints out our main menu and the availble choices=
for (unsigned long long i = 0; i <= choices.size() - 1; i++){
    cout << "\t[" << i+1 << "]  " << choices[i] << "\n";
}
cout << "Enter selection [ ]\b\b";
}
//for discounts
const std::array<std::string, 5> discounts = {"Senior Citizen", "Preffered Member", "Educator" ,"Veteran", "N/A"};

void print_discounts() //recycled code from function assignment
{
// prints out our main menu and the availble choices
cout << "\t\t\tPlease select an option from the following choices:\n\n";
for (unsigned long long j = 0; j <= discounts.size() - 1; j++)
{
    cout << "\t[" << j+1 << "]  " << discounts[j] << "\n";
}
cout << "Enter selection [ ]\b\b";
}

//for printing receipt
void print_receipt(){
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2); //forces calculations to only have double int values
    cout << "====================\nSubtotal: $" << sub_total << "\n";
    cout << "Discount: $" << price_discounted << "\n";
    cout << "Tax: $" << tax << "\n";
    cout << "Total: $" << final_total << "\n====================\n";
}

//for calculations
void receipt_calculations(){
price_discounted = (sub_total * active_discount);
tax = (sub_total * tax_rate);
final_total = sub_total + (tax - price_discounted);
}

void customer_payment(){
cout << "Enter amount paid: ";
cin >> payment;
payment_amount = (payment_amount + payment);
if(payment_amount <= final_total){
    do{
     amount_due = (final_total - payment_amount);
     cout << "Amount Due " << amount_due << '\n';
     cout << "Enter amount paid: " << std::endl;
     cin >> payment;
     payment_amount = (payment_amount + payment);
     customer_change = (payment_amount - final_total);
     cout << "Thank you, your change back is: $" << customer_change  << std::endl;
    }while (payment_amount <= final_total);
}else{
    customer_change = (payment_amount - final_total);
    cout << "Thank you, your change back is: $" << customer_change  << std::endl;
}
}
//source citation for 'setf(std::ios::fixed, std::ios::floatfield)' as well as -->
//inspiration for 'customer_payment' function
/***************************************************************************************
*    Title: <Menu Program With Functions>
*    Author: <Dave Hayden>
*    Date: <7/11/17>
*    Code version: <c++14>
*    Link: <http://cplusplus.com/forum/beginner/218985/>
*
***************************************************************************************/


#endif // RECEIPT_PROJECT_H
