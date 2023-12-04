#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <vector>
#include <string>

class Products
{
public:
	// Product structure
	struct Product
	{
		char code;
		std::string name;
		double price;

		Product(char c, std::string n, double p) : code(c), name(n), price(p) {}
	};

	static void displayProduct(const Product& product);
	static void displayMenu(const std::vector<Product>& products);

	// Static function to get a list of products
	static std::vector<Product> initializeProducts();
};
#endif // PRODUCTS_H