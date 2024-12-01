#ifndef IPAYMENTMETHOD_H
#define IPAYMENTMETHOD_H

class IPaymentMethod {
public:
	virtual void pay() const = 0;
	virtual ~IPaymentMethod() = default;
};

#endif