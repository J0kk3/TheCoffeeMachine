#include "Products.h"
#include <iostream>

void Products::displayProduct(const Products::Product& product)
{
	// Calculate the number of spaces needed for alignment
	// Total length for the product display
	int totalLength = 30;
	// Length of the code and name
	int currentLength = 4 + product.name.length();
	// Calculate spaces needed
	int spacesNeeded = totalLength - currentLength;

	// Display the product with consistent formatting
	std::cout << "\t" << product.code << "(" << product.name << ")";
	for (int i = 0; i < spacesNeeded; ++i)
	{
		// Add the calculated number of spaces
		std::cout << " ";
	}
	std::cout << product.price << " kr" << std::endl;
}

void Products::displayMenu(const std::vector<Products::Product>& products)
{
	for (const auto& product : products)
	{
		Products::displayProduct(product);
	}
}

std::vector<Products::Product> Products::initializeProducts()
{
	return
	{
		Product('V', "Varmvatten", 0.00),
		Product('K', "Kaffe", 10.00),
		Product('E', "Espresso", 14.00),
		Product('C', "Chocolate", 11.50),
		Product('L', "Latte", 13.00),
		Product('P', "Cappucino", 13.50)
	};
}