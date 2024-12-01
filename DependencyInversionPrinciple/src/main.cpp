#include "PaymentProcessor.h"
#include "CreditCard.h"
#include "PayPal.h"

int main() {
	PaymentProcessor processor1(std::make_unique<CreditCard>());
	processor1.processPayment();

	std::unique_ptr<PayPal> paypal = std::make_unique<PayPal>();
	PaymentProcessor processor2(std::move(paypal));
	processor2.processPayment();

	return 0;

}