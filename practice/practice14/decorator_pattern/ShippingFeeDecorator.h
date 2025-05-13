#pragma once
#include "Purchase.h"
#include <memory>
class ShippingFeeDecorator : public Purchase {
    std::shared_ptr<Purchase> base;
public:
    ShippingFeeDecorator(std::shared_ptr<Purchase> b) : base(b) {}
    double getCost() const override {
        return base->getCost() + 5.00;
    }
};