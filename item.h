#pragma once

class item {
private:
	std::string name;
	double price;
	int stock;

public:
	item(const std::string name, double price, int stock);

	std::string get_name() const;
	double get_price() const;
	int get_stock() const;

	void set_name(const std::string& name);
	void set_price(double price);
	void set_stock(int stock);
	void print() const;
};

struct state_info {
	std::string name;
	double tax_rate;
};

class tax_calc {
public:
	tax_calc();
	double get_tax_rate(const std::string& user_state);
};
