#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "item.h"

using namespace std;

void space() {
	std::cout << std::endl;
}

int main() {
	std::string menu;
	std::string choice_str;

	int choice;
	double total{};

	int apple;
	int chip;
	int jerky;
	int coffee;
	int donut;
	int cheese;
	int water;
	int sprite;

	int apple_cart = 0;
	int chip_cart = 0;
	int jerky_cart = 0;
	int coffee_cart = 0;
	int donut_cart = 0;
	int cheese_cart = 0;
	int water_cart = 0;
	int sprite_cart = 0;

	int apple_stock = 10;
	int chips_stock = 5;
	int jerky_stock = 7;
	int coffee_stock = 15;
	int donut_stock = 10;
	int cheese_stock = 8;
	int water_stock = 4;
	int sprite_stock = 7;

	time_t now;
	struct tm localtime;

	time(&now);

	localtime_s(&localtime, &now);

	int current_month = localtime.tm_mon + 1;
	int current_day = localtime.tm_mday;
	int user_input;

	if ((current_month == 3 && current_day == 11) ||
		(current_month == 5 && current_day == 2) ||
		(current_month == 9 && current_day == 13)) {
		cout << "Sorry, we are closed today!" << endl;
		return 0;
	}
	else {
		cout << "Welcome! We are open today." << endl;
	}

	do {
		std::cout << "[1] Add Item" << std::endl;
		std::cout << "[2] View Cart" << std::endl;
		std::cout << "[3] View Stock" << std::endl;
		std::cout << "[4] Check Out" << std::endl;
		std::cout << "[5] Leave Store" << std::endl;

		space();

		std::getline(std::cin, choice_str);
		choice = stoi(choice_str);

		item stock[8]{
			item("Apple", 0.69, apple_stock),
			item("Chips", 2.49, chips_stock),
			item("Beef Jerky", 3.99, jerky_stock),
			item("Coffee", 1.79, coffee_stock),
			item("Donut", 1.29, donut_stock),
			item("Cheese Stick", 0.89, cheese_stock),
			item("Water", 1.59, water_stock),
			item("Sprite", 3.49, sprite_stock)
		};

		if (choice == 1) {
			space();

			std::cout << "What would you like to add to your cart? (Please enter name exactly as shown)" << std::endl;
			for (int i = 0; i < 8; i++) {
				stock[i].print();
			}

			string buy_str;
			getline(cin, buy_str);

			if (buy_str == "Apple") {
				do {
					cout << "How many apples would you like to buy? There are " << apple_stock << " in stock. ";
					string apple_str;
					getline(cin, apple_str);
					apple = stoi(apple_str);

					space();

					if (apple > apple_stock) {
						std::cout << "You cannot buy more than " << apple_stock << " apples." << std::endl;
					}
					else {

						cout << apple << " apple(s) have been added to your cart" << endl;
						apple_cart = apple_cart + apple;
					}
				} while (apple > apple_stock);
				apple_stock = apple_stock - apple;
			}
			else if (buy_str == "Chips") {
				do {
					cout << "How many bags of chips would you like to buy? There are " << chips_stock << " in stock. ";
					string chips_str;
					getline(cin, chips_str);
					chip = stoi(chips_str);

					space();

					if (chip > chips_stock) {
						std::cout << "You cannot buy more than " << chips_stock << " chips." << std::endl;
					}
					else {
						cout << chip << " bag(s) of chips have been added to your cart" << endl;
						chip_cart = chip_cart + chip;
					}

				} while (chip > chips_stock);
				chips_stock = chips_stock - chip;
			}
			else if (buy_str == "Beef Jerky") {
				do {
					cout << "How many bags of beef jerky would you like to buy? There are " << jerky_stock << " in stock. ";
					string jerky_str;
					getline(cin, jerky_str);
					jerky = stoi(jerky_str);

					space();

					if (jerky > jerky_stock) {
						std::cout << "You cannot buy more than " << jerky_stock << " jerky." << std::endl;
					}
					else {
						cout << jerky << " bag(s) of beef jerky have been added to your cart" << endl;
						jerky_cart = jerky_cart + jerky;
					}
				} while (jerky > jerky_stock);
				jerky_stock = jerky_stock - jerky;
			}
			else if (buy_str == "Coffee") {
				do {
					cout << "How many cups of coffee would you like to buy? There are " << coffee_stock << " in stock. ";
					string coffee_str;
					getline(cin, coffee_str);
					coffee = stoi(coffee_str);

					space();

					if (coffee > coffee_stock) {
						std::cout << "You cannot buy more than " << coffee_stock << " cup(s) of coffee. " << std::endl;
					}
					else {
						cout << coffee << " cup(s) of coffee have been added to your cart" << endl;
						coffee_cart = coffee_cart + coffee;
					}
				} while (coffee > coffee_stock);
				coffee_stock = coffee_stock - coffee;
			}
			else if (buy_str == "Donut") {
				do {
					cout << "How many donuts would you like to buy? There are " << donut_stock << " in stock. ";
					string donut_str;
					getline(cin, donut_str);
					donut = stoi(donut_str);

					space();

					if (donut > donut_stock) {
						std::cout << "You cannot buy more than " << donut_stock << " donuts." << std::endl;
					}
					else {
						cout << donut << " donut(s) have been added to your cart" << endl;
						donut_cart = donut_cart + donut;
					}
				} while (donut > donut_stock);
				donut_stock = donut_stock - donut;
			}
			else if (buy_str == "Cheese Stick") {
				do {
					cout << "How many cheese sticks would you like to buy? There are " << cheese_stock << " in stock. ";
					string cheese_str;
					getline(cin, cheese_str);
					cheese = stoi(cheese_str);

					space();

					if (cheese > cheese_stock) {
						std::cout << "You cannot buy more than " << cheese_stock << " cheese sticks. " << std::endl;
					}
					else {
						cout << cheese << " cheese stick(s) have been added to your cart" << endl;
						cheese_cart = cheese_cart + cheese;
					}
				} while (cheese > cheese_stock);
				cheese_stock = cheese_stock - cheese;
			}
			else if (buy_str == "Water") {
				do {
					cout << "How bottles of water would you like to buy? There are " << water_stock << " in stock. ";
					string water_str;
					getline(cin, water_str);
					water = stoi(water_str);

					space();

					if (water > water_stock) {
						std::cout << "You cannot buy more than " << water_stock << " bottle(s) of water. " << std::endl;
					}
					else {
						cout << water << " water bottle(s) have been added to your cart" << endl;
						water_cart = water_cart + water;
					}
				} while (water > water_stock);
				water_stock = water_stock - water;
			}
			else if (buy_str == "Sprite") {
				do {
					cout << "How many bottles of sprite would you like to buy? There are " << sprite_stock << " in stock. ";
					string sprite_str;
					getline(cin, sprite_str);
					sprite = stoi(sprite_str);

					space();

					if (sprite > sprite_stock) {
						std::cout << "You cannot buy more than " << sprite_stock << " bottle(s) of sprite." << std::endl;
					}
					else {
						cout << sprite << " bottle(s) of sprite have been added to your cart" << endl;
						sprite_cart = sprite_cart + sprite;
					}
				} while (sprite > sprite_stock);
				sprite_stock = sprite_stock - sprite;
			}
			else {
				std::cout << "Invalid Choice" << std::endl;
			}
		}
		else if (choice == 2) {
			space();
			if ((apple_cart == 0) && (chip_cart == 0) && (jerky_cart == 0) && (coffee_cart == 0) && (donut_cart) == 0 && (cheese_cart == 0) && (water_cart == 0) && (sprite_cart == 0)) {
				cout << "Your cart is empty." << endl;
			}
			else {
				std::cout << "Your cart: " << std::endl;
				if (apple_cart >= 1) {
					cout << apple_cart << " apples" << endl;
				}
				if (chip_cart >= 1) {
					cout << chip_cart << " bag(s) of chips" << endl;
				}
				if (jerky_cart >= 1) {
					cout << jerky_cart << " bag(s) of beef jerky" << endl;
				}
				if (coffee_cart >= 1) {
					cout << coffee_cart << " cup(s) of coffee" << endl;
				}
				if (donut_cart >= 1) {
					cout << donut_cart << " donut(s)" << endl;
				}
				if (cheese_cart >= 1) {
					cout << cheese_cart << " stick(s) of cheese" << endl;
				}
				if (water_cart >= 1) {
					cout << water_cart << " bottle(s) of water" << endl;
				}
				if (sprite_cart >= 1) {
					cout << sprite_cart << " bottle(s) of sprite" << endl;
				}
				space();

				cout << "Would you like to remove anything from your cart?" << endl;
				cout << "     Yes                 No" << endl;
				string cart_remove;
				getline(cin, cart_remove);
				if (cart_remove == "Yes" || cart_remove == "yes" || cart_remove == "YES") {
					cout << "What would you like to remove? (Please type item as shown)" << endl;
					space();
					if (apple_cart >= 1) {
						cout << "Apple" << endl;
					}
					if (chip_cart >= 1) {
						cout << "Chips" << endl;
					}
					if (jerky_cart >= 1) {
						cout << "Beef jerky" << endl;
					}
					if (coffee_cart >= 1) {
						cout << "Coffee" << endl;
					}
					if (donut_cart >= 1) {
						cout << "Donut" << endl;
					}
					if (cheese_cart >= 1) {
						cout << "String Cheese" << endl;
					}
					if (water_cart >= 1) {
						cout << "Water" << endl;
					}
					if (sprite_cart >= 1) {
						cout << "Sprite" << endl;
					}
					string edit_cart;
					getline(cin, edit_cart);
					if (edit_cart == "Apple") {
						cout << "How many apples would you like to remove" << endl;
						string apple_remove_str;
						getline(cin, apple_remove_str);
						int apple_remove;
						apple_remove = stoi(apple_remove_str);
						if (apple_remove > apple_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							apple_cart = apple_cart - apple_remove;
							cout << apple_remove << " apple(s) have been removed from your cart" << endl;
						}
					}
					if (edit_cart == "Chips") {
						cout << "Chips" << endl;
						cout << "How many bags of chips would you like to remove" << endl;
						string chips_remove_str;
						getline(cin, chips_remove_str);
						int chip_remove;
						chip_remove = stoi(chips_remove_str);
						if (chip_remove > chip_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							chip_cart = chip_cart - chip_remove;
							cout << chip_remove << " bag(s) of chips have been removed from your cart" << endl;
						}
					}
					if (edit_cart == "Beef Jerky") {
						cout << "Beef jerky" << endl;
						cout << "How many bags of beef jerky would you like to remove" << endl;
						string jerky_remove_str;
						getline(cin, jerky_remove_str);
						int jerky_remove;
						jerky_remove = stoi(jerky_remove_str);
						if (jerky_remove > jerky_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							jerky_cart = jerky_cart - jerky_remove;
							cout << jerky_remove << " bag(s) of beef jerky have been removed from your cart" << endl;
						}
					}
					if (edit_cart == "Coffee") {
						cout << "Coffee" << endl;
						cout << "How many cups of coffee would you like to remove" << endl;
						string coffee_remove_str;
						getline(cin, coffee_remove_str);
						int coffee_remove;
						coffee_remove = stoi(coffee_remove_str);
						if (coffee_remove > coffee_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							coffee_cart = coffee_cart - coffee_remove;
							cout << coffee_remove << " cup(s) of coffee have been removed from your cart" << endl;
						}
					}
					if (edit_cart == "Donut") {
						cout << "Donut" << endl;
						cout << "How many donuts would you like to remove" << endl;
						string donut_remove_str;
						getline(cin, donut_remove_str);
						int donut_remove;
						donut_remove = stoi(donut_remove_str);
						if (donut_remove > donut_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							donut_cart = donut_cart - donut_remove;
							cout << donut_remove << " donut(s) have been removed from your cart" << endl;
						}
					}
					if (edit_cart == "String Cheese") {
						cout << "String Cheese" << endl;
						cout << "How many sticks of string cheese would you like to remove" << endl;
						string cheese_remove_str;
						getline(cin, cheese_remove_str);
						int cheese_remove;
						cheese_remove = stoi(cheese_remove_str);
						if (cheese_remove > cheese_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							cheese_cart = cheese_cart - cheese_remove;
							cout << cheese_remove << " stick(s) of string cheese have been removed from your cart" << endl;
						}
					}
					if (edit_cart == "Water") {
						cout << "Water" << endl;
						cout << "How many bottles of water would you like to remove" << endl;
						string water_remove_str;
						getline(cin, water_remove_str);
						int water_remove;
						water_remove = stoi(water_remove_str);
						if (water_remove > water_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							water_cart = water_cart - water_remove;
							cout << water_remove << " bottle(s) of water have been removed from your cart" << endl;
						}
					}
					if (edit_cart == "Sprite") {
						cout << "Sprite" << endl;
						cout << "How many bottles of sprite would you like to remove" << endl;
						string sprite_remove_str;
						getline(cin, sprite_remove_str);
						int sprite_remove;
						sprite_remove = stoi(sprite_remove_str);
						if (sprite_remove > sprite_cart) {
							cout << "Invalid request" << endl;
						}
						else {
							sprite_cart = sprite_cart - sprite_remove;
							cout << sprite_remove << " bottle(s) of sprite have been removed from your cart" << endl;
						}
					}
				}
			}
			std::cout << "Press 'Enter' to return to main menu" << std::endl;
			std::getline(std::cin, menu);
		}
		else if (choice == 3) {
			for (int i = 0; i < 8; i++) {
				stock[i].print();
			}
			space();

			std::cout << "Press 'Enter' to return to main menu" << std::endl;
			std::getline(std::cin, menu);
		}
		else if (choice == 4) {
			tax_calc calc;
			string user_state;

			space();

			cout << "Enter your state of residence (Please enter Wisconsin, Minnesota, Michigan, Iowa or Illinois): ";
			getline(cin, user_state);

			total = (apple_cart * 0.69) + (chip_cart * 2.49) + (jerky_cart * 3.99) + (coffee_cart * 1.79) + (donut_cart * 1.29) + (cheese_cart * 0.89) + (water_cart * 1.59) + (sprite_cart * 3.49);

			double tax_rate = calc.get_tax_rate(user_state);
			double sales_tax = round((total * tax_rate) * 100) / 100.0;
			double total_amount = round((total + sales_tax) * 100) / 100.0;

			space();
			std::cout << "Your total is: $" << total_amount << std::endl;
			space();

			double total_pay;
			cout << "How much would you like to pay? ";
			cin >> total_pay;

			if (total_pay < total_amount) {
				cout << "Transaction cancelled, insufficient payment" << endl;
				return 2;
			}

			double change_due = total_pay - total_amount;

			space();
			cout << "Change Due: $" << change_due << endl;
			space();
			cout << "Here is your receipt:" << endl;
			space();
			cout << "---RECEIPT---" << endl;
			space();
			cout << "Item(s): " << std::endl;
			if (apple_cart >= 1) {
				cout << apple_cart << " apple(s)    $" << ((apple_cart * 0.69) * 100) / 100.0 << endl;
			}
			if (chip_cart >= 1) {
				cout << chip_cart << " bag(s) of chips    $" << ((chip_cart * 2.49) * 100) / 100.0 << endl;
			}
			if (jerky_cart >= 1) {
				cout << jerky_cart << " bag(s) of beef jerky    $" << ((jerky_cart * 3.99) * 100) / 100.0 << endl;
			}
			if (coffee_cart >= 1) {
				cout << coffee_cart << " cup(s) of coffee    $" << ((coffee_cart * 1.79) * 100) / 100.0 << endl;
			}
			if (donut_cart >= 1) {
				cout << donut_cart << " donut(s)    $" << ((donut_cart * 1.29) * 100) / 100.0 << endl;
			}
			if (cheese_cart >= 1) {
				cout << cheese_cart << " stick(s) of cheese    $" << ((cheese_cart * 0.89) * 100) / 100.0 << endl;
			}
			if (water_cart >= 1) {
				cout << water_cart << " bottle(s) of water    $" << ((water_cart * 1.59) * 100) / 100.0 << endl;
			}
			if (sprite_cart >= 1) {
				cout << sprite_cart << " bottle(s) of sprite    $" << ((sprite_cart * 3.49) * 100) / 100.0 << endl;
			}
			space();
			cout << "SALES TAX: $" << sales_tax << endl;
			cout << "------" << endl;
			cout << "TOTAL: $" << total_amount << endl;
			space();
			cout << "AMOUNT PAID: $" << total_pay << endl;
			cout << "CHANGE DUE: $" << change_due << endl;
			space();
			cout << "---THANK YOU FOR SHOPPING WITH US---" << endl;
			space();

			ofstream receipt("receipt.txt");
			if (receipt.is_open()) {
				receipt << "---RECEIPT---" << endl;
				receipt << " " << endl;
				receipt << "Item(s): " << endl;
				if (apple_cart >= 1) {
					receipt << apple_cart << " apple(s)    $" << ((apple_cart * 0.69) * 100) / 100.0 << endl;
				}
				if (chip_cart >= 1) {
					receipt << chip_cart << " bag(s) of chips    $" << ((chip_cart * 2.49) * 100) / 100.0 << endl;
				}
				if (jerky_cart >= 1) {
					receipt << jerky_cart << " bag(s) of beef jerky    $" << ((jerky_cart * 3.99) * 100) / 100.0 << endl;
				}
				if (coffee_cart >= 1) {
					receipt << coffee_cart << " cup(s) of coffee    $" << ((coffee_cart * 1.79) * 100) / 100.0 << endl;
				}
				if (donut_cart >= 1) {
					receipt << donut_cart << " donut(s)    $" << ((donut_cart * 1.29) * 100) / 100.0 << endl;
				}
				if (cheese_cart >= 1) {
					receipt << cheese_cart << " stick(s) of cheese    $" << ((cheese_cart * 0.89) * 100) / 100.0 << endl;
				}
				if (water_cart >= 1) {
					receipt << water_cart << " bottle(s) of water    $" << ((water_cart * 1.59) * 100) / 100.0 << endl;
				}
				if (sprite_cart >= 1) {
					receipt << sprite_cart << " bottle(s) of sprite    $" << ((sprite_cart * 3.49) * 100) / 100.0 << endl;
				}
				receipt << " " << endl;
				receipt << "SALES TAX: $" << sales_tax << endl;
				receipt << "--------------------" << endl;
				receipt << "TOTAL: $" << total_amount << endl;
				receipt << " " << endl;
				receipt << "AMOUNT PAID: $" << total_pay << endl;
				receipt << "CHANGE DUE: $" << change_due << endl;
				receipt << " " << endl;
				receipt << "---THANK YOU FOR SHOPPING WITH US---" << endl;
				receipt.close();
			}
			return 0;
		}
		else if (choice == 5) {
			std::cout << "Thank you for shopping at the store" << std::endl;
			return 0;
		}
		else {
			std::cout << "Invalid Choice" << std::endl;

			std::cout << "Press 'Enter' to return to main menu" << std::endl;
			std::getline(std::cin, menu);
		}
	} while (choice != 5);
}