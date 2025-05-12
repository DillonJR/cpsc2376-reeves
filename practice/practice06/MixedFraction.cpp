#include "MixedFraction.h"
#include <cmath>

MixedFraction::MixedFraction(int w, int n, int d)
    : Fraction(w* d + n, d), whole(w) {}

MixedFraction::MixedFraction(const Fraction& f)
    : Fraction(f) {
    whole = getNumerator() / getDenominator();
}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    int n = mf.getNumerator();
    int d = mf.getDenominator();
    int wholePart = n / d;
    int remainder = std::abs(n % d);
    if (remainder == 0) {
        os << wholePart;
    }
    else {
        os << wholePart << " " << remainder << "/" << d;
    }
    return os;
}
