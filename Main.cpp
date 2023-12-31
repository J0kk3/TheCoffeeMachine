#include "Products.h"
#include "HandleTransaction.h"
#include <iostream>
#include <string>

int main()
{
	// Initialize the list of products
	std::vector<Products::Product> products = Products::initializeProducts();

	// Name of the local machine
	const std::string machineName = "The Coffee Machine";

	// Store the users choice
	char choice;
	// Variable to store the amount of money the user has inserted
	double money = 0.0;

	while (true)
	{
		//Display welcome message & Menu
		std::cout << "\tWelcome to " << machineName << "!" << std::endl;
		std::cout << "\t=============================" << std::endl;
		std::cout << "\n\tPlease select a product:" << std::endl;

		// Display the menu
		Products::displayMenu(products);

		std::cout << "\n\tYour choice: ";
		std::cin >> choice;
		// Convert the choice to uppercase for comparison
		choice = toupper(choice);

		//Check the users choice
		bool productFound = false;
		for (const Products::Product& product : products)
		{
			if (choice == toupper(product.code))
			{
				productFound = true;
				double money = 0.0;

				if (product.price > 0)
				{
					std::cout << "\n\tInsert money:";
					std::cin >> money;
				}
				
				// Create an instance of HandleTransaction
				HandleTransaction transactionHandler;
				//The product is found, ask the user to insert money
				transactionHandler.processTransaction(product, money);
				// A product is found, break the loop
				break;
			}
		}

		if (!productFound)
		{			
			std::cout << "\n\tInvalid choice, please try again!" << std::endl;
		}
	}
	return 0;
}