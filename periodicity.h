#pragma once
#include <type_traits>
namespace periodicity {

    template<typename Number>
    struct IsNatural : std::conjunction<std::is_unsigned<Number>, std::is_integral<Number>> {};

    template<typename Number>
    inline constexpr bool isNaturalValue = IsNatural<Number>::value;

    template<typename Number>
    struct IsInteger : std::is_integral<Number> {};

    template<typename Number>
    inline constexpr bool isIntegerValue = IsInteger<Number>::value;

    template<typename Number>
    struct IsFloating : std::is_floating_point<Number> {};

    template<typename Number>
    inline constexpr bool isFloatingValue = IsFloating<Number>::value;

    template<typename Number>
    struct IsReal : std::conjunction<std::is_arithmetic<Number>, std::negation<std::is_same<Number, bool>>> {};

    template<typename Number>
    inline constexpr bool IsRealValue = IsReal<Number>::value;

    template<typename Number>
    struct IsComplex : std::false_type {};

    template<typename Number>
    inline constexpr bool isComplexValue = IsComplex<Number>::value;

    template<typename Number>
    struct IsQuaternion : std::false_type {};

    template<typename Number>
    inline constexpr bool isQuaternionValue = IsQuaternion<Number>::value;
};
