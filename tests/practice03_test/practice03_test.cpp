#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\dillo\GitHub\cpsc2376-reeves\practice\practice03\practice03.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(MathUtilsTests)
    {
    public:


        TEST_METHOD(SumRangeTest)
        {
            // Standard range test: sumRange(1, 5) should return 10
            Assert::AreEqual(10, MathUtils::sumRange(1, 5));

            // Edge case where start == end: sumRange(5, 5) should return 0
            Assert::AreEqual(0, MathUtils::sumRange(5, 5));

            // Negative range test: sumRange(-3, 3) should return 0
            Assert::AreEqual(0, MathUtils::sumRange(-3, 3));
        }

        // Test for containsNegative
        TEST_METHOD(ContainsNegativeTest)
        {
            // Vector with negative number: should return true
            Assert::IsTrue(MathUtils::containsNegative({ 1, -2, 3 }));

            // Vector with no negative number: should return false
            Assert::IsFalse(MathUtils::containsNegative({ 1, 2, 3 }));

            // Empty vector: should return false
            Assert::IsFalse(MathUtils::containsNegative({}));
        }

        // Test for findMax
        TEST_METHOD(FindMaxTest)
        {
            // Normal case: findMax({1, 2, 3}) should return 3
            Assert::AreEqual(3, MathUtils::findMax({ 1, 2, 3 }));

            // Empty vector: findMax({}) should return INT_MIN (or a value that represents error)
            Assert::AreEqual(INT_MIN, MathUtils::findMax({}));

            // All elements the same: findMax({5, 5, 5}) should return 5
            Assert::AreEqual(5, MathUtils::findMax({ 5, 5, 5 }));
        }
    };
}

