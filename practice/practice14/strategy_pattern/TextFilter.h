#pragma once
#include <string>
class TextFilter {
public:
    virtual ~TextFilter() = default;
    virtual std::string apply(const std::string& input) const = 0;
};