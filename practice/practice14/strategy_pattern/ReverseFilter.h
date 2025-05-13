#pragma once
#include "TextFilter.h"
#include <algorithm>
class ReverseFilter : public TextFilter {
public:
    std::string apply(const std::string& input) const override {
        std::string result = input;
        std::reverse(result.begin(), result.end());
        return result;
    }
};