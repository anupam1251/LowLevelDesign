#pragma once
#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "IPaymentMethod.h"
#include <iostream>

class CreditCard : public IPaymentMethod {
public:
	void pay() const override;
};

#endif
