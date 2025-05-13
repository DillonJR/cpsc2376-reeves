#pragma once
#include "TextFilter.h"
#include <algorithm>
class UppercaseFilter : public TextFilter {
public:
    std::string apply(const std::string& input) const override {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};