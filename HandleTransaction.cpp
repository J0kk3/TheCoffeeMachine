#include "HandleTransaction.h"
#include "Products.h"
#include <iostream>
#include <Windows.h>

void HandleTransaction::processTransaction(const Products::Product& selectedProduct, double moneyInserted)
{
	const double moneyRequired = selectedProduct.price;
	double totalMoneyInserted = 0.0;
	totalMoneyInserted += moneyInserted;

	while (totalMoneyInserted < moneyRequired)
	{
		std::cout << "\tNot enough money inserted. Please insert more." << std::endl;
		std::cout << "\n\tPlease insert money: ";
		std::cin >> moneyInserted;
		totalMoneyInserted += moneyInserted;
	}

	//Calculate and dispense change if overpaid
	double change = totalMoneyInserted - moneyRequired;
	if (change > 0)
	{
		dispenseChange(change);
	}

	// Acknowledge the purchase
	std::cout << "\tThank you for your purchase!" << std::endl;
	// Simulate beverage preparation
	std::cout << "\tPreparing your " << selectedProduct.name << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		Sleep(1000); // Wait for 1 second
		std::cout << "\n\t............................................" << std::endl;
	}

	std::cout << "\n\tYour beverage is ready, Enjoy!" << std::endl;
	Sleep(500);
	std::cout << "\t=============================" << std::endl;
}

void HandleTransaction::dispenseChange(double change)
{
	int totalCents = static_cast<int>(change * 100);

	int tens = totalCents / 1000;
	totalCents -= tens * 1000;

	int fives = (totalCents % 1000) / 500;
	totalCents -= fives * 500;

	int twos = ((totalCents % 1000) % 500) / 200;
	totalCents -= twos * 200;

	int ones = ((totalCents % 1000) % 500) / 100;
	totalCents -= ones * 100;

	int halfs = (((totalCents % 1000) % 500) % 100) / 50;
	totalCents -= halfs * 50;

	int rest = totalCents;

	// Output the change in coins
	std::cout << "\n\tChange:" << std::endl;
	std::cout << "\t10 kr coins: " << tens << std::endl;
	std::cout << "\t5 kr coins: " << fives << std::endl;
	std::cout << "\t2 kr coins: " << twos << std::endl;
	std::cout << "\t1 kr coins: " << ones << std::endl;
	std::cout << "\t50 ore coins: " << halfs << std::endl;
	std::cout << "\tRemaining ore: " << rest << std::endl;
};