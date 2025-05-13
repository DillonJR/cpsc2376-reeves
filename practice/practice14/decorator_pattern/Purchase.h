#pragma once
class Purchase {
public:
    virtual ~Purchase() = default;
    virtual double getCost() const = 0;
};