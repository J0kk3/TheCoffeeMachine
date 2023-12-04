#ifndef HANDLETRANSACTION_H
#define HANDLETRANSACTION_H

#include "Products.h"

class HandleTransaction
{
public:
	void processTransaction(const Products::Product& selectedProduct, double moneyInserted);
	void dispenseChange(double change);
};

#endif // HANDLETRANSACTION_H