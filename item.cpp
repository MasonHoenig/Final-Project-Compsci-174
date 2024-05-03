#include <iostream>
#include "item.h"

item::item(const std::string name, double price, int stock) {
    this->name = name;
    this->price = price;
    this->stock = stock;
}

std::string item::get_name() const {
    return name;
}

double item::get_price() const {
    return price;
}

int item::get_stock() const {
    return stock;
}

void item::set_name(const std::string& name) {
    this->name = name;
}

void item::set_price(double price) {
    this->price = price;
}

void item::set_stock(int stock) {
    this->stock = stock;
}

void item::print() const {
    std::cout << get_name() << " - $" << get_price() << " (" << get_stock() << " left) " << std::endl;
}

tax_calc::tax_calc() {}

double tax_calc::get_tax_rate(const std::string& user_state) {
    double tax_rate = 0.0;

    if (user_state == "Wisconsin") {
        tax_rate = 0.05;
    }
    else if (user_state == "Michigan") {
        tax_rate = 0.06;
    }
    else if (user_state == "Minnesota") {
        tax_rate = 0.0688;
    }
    else if (user_state == "Iowa") {
        tax_rate = 0.06;
    }
    else if (user_state == "Illinois") {
        tax_rate = 0.0625;
    }
    else {
        std::cout << "Error: " << user_state << " is not available." << std::endl;
    }
    return tax_rate;
}
