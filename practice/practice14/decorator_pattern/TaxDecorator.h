#pragma once
#include "Purchase.h"
#include <memory>
class TaxDecorator : public Purchase {
    std::shared_ptr<Purchase> base;
public:
    TaxDecorator(std::shared_ptr<Purchase> b) : base(b) {}
    double getCost() const override {
        return base->getCost() * 1.10;
    }
};