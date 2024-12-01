#pragma once
#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include "IPaymentMethod.h"
#include <memory>

class PaymentProcessor {
	std::unique_ptr<IPaymentMethod> m_uptrPaymentMethod;
public:
	explicit PaymentProcessor(std::unique_ptr<IPaymentMethod>uptrPaymentMethod);
	void processPayment() const;
};
#endif