#pragma once
#ifndef PAYPAL_H
#define PAYPAL_H

#include "IPaymentMethod.h"
#include <iostream>
class PayPal : public IPaymentMethod{
public:
	void pay() const override;
};

#endif