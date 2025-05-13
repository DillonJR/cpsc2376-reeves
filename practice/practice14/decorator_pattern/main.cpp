#include "SimplePurchase.h"
#include "TaxDecorator.h"
#include "ShippingFeeDecorator.h"
#include "DiscountDecorator.h"
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<Purchase> p = std::make_shared<SimplePurchase>(100.0);
    int choice;

    std::cout << "Apply tax? (1=yes): ";
    std::cin >> choice;
    if (choice == 1) p = std::make_shared<TaxDecorator>(p);

    std::cout << "Apply shipping fee? (1=yes): ";
    std::cin >> choice;
    if (choice == 1) p = std::make_shared<ShippingFeeDecorator>(p);

    std::cout << "Apply discount? (1=yes): ";
    std::cin >> choice;
    if (choice == 1) {
        double rate;
        std::cout << "Enter discount rate (0.0 - 1.0): ";
        std::cin >> rate;
        p = std::make_shared<DiscountDecorator>(p, rate);
    }

    std::cout << "Final cost: $" << p->getCost() << "\n";
    return 0;
}
