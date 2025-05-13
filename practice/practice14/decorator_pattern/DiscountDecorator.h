#pragma once
#include "Purchase.h"
#include <memory>
class DiscountDecorator : public Purchase {
    std::shared_ptr<Purchase> base;
    double discountRate;
public:
    DiscountDecorator(std::shared_ptr<Purchase> b, double rate) : base(b), discountRate(rate) {}
    double getCost() const override {
        return base->getCost() * (1.0 - discountRate);
    }
};