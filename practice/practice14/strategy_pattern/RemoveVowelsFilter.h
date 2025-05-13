#pragma once
#include "TextFilter.h"
class RemoveVowelsFilter : public TextFilter {
public:
    std::string apply(const std::string& input) const override {
        std::string result;
        for (char c : input) {
            if (std::string("aeiouAEIOU").find(c) == std::string::npos)
                result += c;
        }
        return result;
    }
};