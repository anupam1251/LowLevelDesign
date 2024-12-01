#include "PaymentProcessor.h"

PaymentProcessor::PaymentProcessor(std::unique_ptr<IPaymentMethod> uptrPaymentMethod):
	m_uptrPaymentMethod (std::move(uptrPaymentMethod)) {}

void PaymentProcessor::processPayment() const {
	m_uptrPaymentMethod->pay();
}