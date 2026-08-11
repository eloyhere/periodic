#pragma once
#include <tuple>
#include <cmath>
#include <complex>
#include <algorithm>
#include "periodicity.h"
#include <initializer_list>

namespace periodicity {

    template<typename Number>
    const Number pi = static_cast<Number>(3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342);

    template<typename Number>
    const Number e = static_cast<Number>(2.718281828459045235360287471352662497757247093699959574966967627);

    template<typename Number>
    const Number Zero = static_cast<Number>(0);

    template<typename Number>
    const Number One = static_cast<Number>(1);

    template<typename Number, Number Minimum, Number Maximum>
    class Angle;

    template<typename Number>
    class Complex;

    template<typename Number>
    struct IsComplex<Complex<Number>> : std::true_type {};

    template<typename Number>
    class Quaternion;

    template<typename Number>
    struct IsQuaternion<Quaternion<Number>> : std::true_type {};

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> ofRadian(const Number& radian);

    template<typename Number>
    Angle < Number, Number{ 0 }, Number{ 360 } > ofDegree(const Number& degree);

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arcsine(const Number& value);

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arccosine(const Number& value);

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arctangent(const Number& value);

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arctangent(const Number& x, const Number& y);

    template<typename Number, Number Minimum, Number Maximum>
    class Angle {
        static_assert(Minimum < Maximum, "Minimum must be less than Maximum");
    private:
        Number value;
    public:
        Angle() : value(Zero<Number>) {}
        explicit Angle(const Number& value) : value(value) {}
        Angle(const Angle<Number, Minimum, Maximum>& other) : value(other.value) {}
        ~Angle() {}

        Angle<Number, Minimum, Maximum>& operator=(const Number& value) {
            this->value = value;
            return *this;
        }

        Angle<Number, Minimum, Maximum>& operator=(const Angle<Number, Minimum, Maximum>& other) {
            value = other.value;
            return *this;
        }

        Angle<Number, Minimum, Maximum> normalize() const {
            if constexpr (std::is_integral_v<Number>) {
                constexpr Number range = Maximum - Minimum;
                Number result = value;

                result = result - Minimum;
                result = result % range;
                if (result < 0) {
                    result += range;
                }
                result = result + Minimum;
                if (result >= Maximum) {
                    result = Minimum;
                }

                return Angle<Number, Minimum, Maximum>(result);
            }
            else if constexpr (std::is_floating_point_v<Number>) {
                constexpr Number range = Maximum - Minimum;
                Number result = value;

                result = std::fmod(result - Minimum, range);
                if (result < 0) {
                    result += range;
                }
                result = result + Minimum;

                return Angle<Number, Minimum, Maximum>(result);
            }
            else {
                return Angle<Number, Minimum, Maximum>(value);
            }
        }

        bool isRadian() const {
            return Minimum != Zero<Number> && Maximum != static_cast<Number>(360.0);
        }

        bool isDegree() const {
            return Minimum == Zero<Number> && Maximum == static_cast<Number>(360.0);
        }

        Angle<Number, -pi<Number>, pi<Number>> toRadian() const {
            using Radian = Angle<Number, -pi<Number>, pi<Number>>;

            if (isRadian()) {
                return Radian(value);
            }

            Number value = this->value * pi<Number> / static_cast<Number>(180.0);
            return Radian(value);
        }

        Angle<Number, Zero<Number>, static_cast<Number>(360.0)> toDegree() const {
            using Degree = Angle<Number, Zero<Number>, static_cast<Number>(360.0)>;

            if (isDegree()) {
                return Degree(value);
            }

            Number value = this->value * static_cast<Number>(180.0) / pi<Number>;
            return Degree(value);
        }

        Number getValue() const {
            return value;
        }

        Number getMinimum() const {
            return Minimum;
        }

        Number getMaximum() const {
            return Maximum;
        }

        Number sine() const {
            if (this->isDegree()) {
                Number radian = this->value * pi<Number> / static_cast<Number>(180.0);
                return std::sin(static_cast<double>(radian));
            }
            else {
                return std::sin(static_cast<double>(this->value));
            }
        }

        Number sine(const Number& ratio) const {
            if (this->isDegree()) {
                Number radian = this->value * ratio * pi<Number> / static_cast<Number>(180.0);
                return std::sin(static_cast<double>(radian));
            }
            else {
                return std::sin(static_cast<double>(this->value * ratio));
            }
        }

        Number cosine() const {
            if (this->isDegree()) {
                Number radian = this->value * pi<Number> / static_cast<Number>(180.0);
                return std::cos(static_cast<double>(radian));
            }
            else {
                return std::cos(static_cast<double>(this->value));
            }
        }

        Number cosine(const Number& ratio) const {
            if (this->isDegree()) {
                Number radian = this->value * ratio * pi<Number> / static_cast<Number>(180.0);
                return std::cos(static_cast<double>(radian));
            }
            else {
                return std::cos(static_cast<double>(this->value * ratio));
            }
        }

        Number tangent() const {
            if (this->isDegree()) {
                Number radian = this->value * pi<Number> / static_cast<Number>(180.0);
                return std::tan(static_cast<double>(radian));
            }
            else {
                return std::tan(static_cast<double>(this->value));
            }
        }

        Number tangent(const Number& ratio) const {
            if (this->isDegree()) {
                Number radian = this->value * ratio * pi<Number> / static_cast<Number>(180.0);
                return std::tan(static_cast<double>(radian));
            }
            else {
                return std::tan(static_cast<double>(this->value * ratio));
            }
        }

        friend Angle<Number, Minimum, Maximum> operator+(const Angle<Number, Minimum, Maximum>& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a.value + b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator+(const Number& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a + b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator+(const Angle<Number, Minimum, Maximum>& a, const Number& b) {
            return Angle<Number, Minimum, Maximum>(a + b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator-(const Angle<Number, Minimum, Maximum>& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a.value - b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator-(const Number& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a - b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator-(const Angle<Number, Minimum, Maximum>& a, const Number& b) {
            return Angle<Number, Minimum, Maximum>(a - b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator*(const Angle<Number, Minimum, Maximum>& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a.value * b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator*(const Number& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a * b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator*(const Angle<Number, Minimum, Maximum>& a, const Number& b) {
            return Angle<Number, Minimum, Maximum>(a * b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator/(const Angle<Number, Minimum, Maximum>& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a.value / b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator/(const Number& a, const Angle<Number, Minimum, Maximum>& b) {
            return Angle<Number, Minimum, Maximum>(a / b.value).normalize();
        }

        friend Angle<Number, Minimum, Maximum> operator%(const Angle<Number, Minimum, Maximum>& left,
            const Angle<Number, Minimum, Maximum>& right) {
            if (right.value == Zero<Number>) {
                throw std::invalid_argument("Modulo by zero angle");
            }
            Number result = left.value;
            Number divisor = right.value;
            if constexpr (std::is_integral_v<Number>) {
                result = result % divisor;
            }
            else {
                result = std::fmod(result, divisor);
            }
            if (result < Minimum) {
                result = Minimum;
            }
            if (result > Maximum) {
                result = Maximum;
            }
            return Angle<Number, Minimum, Maximum>(result);
        }

        friend Angle<Number, Minimum, Maximum> operator%(const Angle<Number, Minimum, Maximum>& left,
            const Number& right) {
            if (right == Zero<Number>) {
                throw std::invalid_argument("Modulo by zero");
            }
            Number result = left.value;
            if constexpr (std::is_integral_v<Number>) {
                result = result % right;
            }
            else {
                result = std::fmod(result, right);
            }
            if (result < Minimum) {
                result = Minimum;
            }
            if (result > Maximum) {
                result = Maximum;
            }
            return Angle<Number, Minimum, Maximum>(result);
        }

        friend bool operator==(const Angle<Number, Minimum, Maximum>& left, const Angle<Number, Minimum, Maximum>& right) {
            return left.value == right.value;
        }

        friend bool operator!=(const Angle<Number, Minimum, Maximum>& left, const Angle<Number, Minimum, Maximum>& right) {
            return !(left == right);
        }

        friend bool operator<(const Angle<Number, Minimum, Maximum>& left, const Angle<Number, Minimum, Maximum>& right) {
            return left.value < right.value;
        }

        friend bool operator<=(const Angle<Number, Minimum, Maximum>& left, const Angle<Number, Minimum, Maximum>& right) {
            return left.value <= right.value;
        }

        friend bool operator>(const Angle<Number, Minimum, Maximum>& left, const Angle<Number, Minimum, Maximum>& right) {
            return left.value > right.value;
        }

        friend bool operator>=(const Angle<Number, Minimum, Maximum>& left, const Angle<Number, Minimum, Maximum>& right) {
            return left.value >= right.value;
        }

        Angle<Number, Minimum, Maximum> operator+() const {
            return *this;
        }

        Angle<Number, Minimum, Maximum> operator-() const {
            Number result = -value;
            if (result < Minimum) {
                result = Minimum;
            }
            if (result > Maximum) {
                result = Maximum;
            }
            return Angle<Number, Minimum, Maximum>(result);
        }

        Angle<Number, Minimum, Maximum>& operator+=(const Angle<Number, Minimum, Maximum>& other) {
            value = value + other.value;
            if (value < Minimum) {
                value = Minimum;
            }
            if (value > Maximum) {
                value = Maximum;
            }
            return *this;
        }

        Angle<Number, Minimum, Maximum>& operator-=(const Angle<Number, Minimum, Maximum>& other) {
            value = value - other.value;
            if (value < Minimum) {
                value = Minimum;
            }
            if (value > Maximum) {
                value = Maximum;
            }
            return *this;
        }

        Angle<Number, Minimum, Maximum>& operator*=(const Number& scalar) {
            value = value * scalar;
            if (value < Minimum) {
                value = Minimum;
            }
            if (value > Maximum) {
                value = Maximum;
            }
            return *this;
        }

        Angle<Number, Minimum, Maximum>& operator/=(const Number& scalar) {
            if (scalar == Zero<Number>) {
                throw std::invalid_argument("Division by zero");
            }
            value = value / scalar;
            if (value < Minimum) {
                value = Minimum;
            }
            if (value > Maximum) {
                value = Maximum;
            }
            return *this;
        }

        Angle<Number, Minimum, Maximum>& operator%=(const Number& scalar) {
            if (scalar == Zero<Number>) {
                throw std::invalid_argument("Modulo by zero");
            }
            if constexpr (std::is_integral_v<Number>) {
                value = value % scalar;
            }
            else {
                value = std::fmod(value, scalar);
            }
            if (value < Minimum) {
                value = Minimum;
            }
            if (value > Maximum) {
                value = Maximum;
            }
            return *this;
        }

        Angle<Number, Minimum, Maximum>& operator++() {
            value++;
            return *this;
        }

        Angle<Number, Minimum, Maximum> operator++(int) {
            Angle<Number, Minimum, Maximum> temp = *this;
            ++value;
            return temp;
        }

        Angle<Number, Minimum, Maximum>& operator--() {
            value--;
            return *this;
        }

        Angle<Number, Minimum, Maximum> operator--(int) {
            Angle<Number, Minimum, Maximum> temp = *this;
            --value;
            return temp;
        }

        friend std::ostream& operator<<(std::ostream& output, const Angle<Number, Minimum, Maximum>& angle) {
            output << angle.value;
            if (angle.isDegree()) {
                output << " degree";
            }
            else if (angle.isRadian()) {
                output << " radian";
            }
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Angle<Number, Minimum, Maximum>& angle) {
            input >> angle.value;
            if (angle.value < Minimum) {
                angle.value = Minimum;
            }
            if (angle.value > Maximum) {
                angle.value = Maximum;
            }
            return input;
        }
    };

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> ofRadian(const Number& radian) {
        return Angle<Number, -pi<Number>, pi<Number>>(radian);
    }

    template<typename Number>
    Angle < Number, Number{ 0 }, Number{ 360 } > ofDegree(const Number& degree) {
        return Angle<Number, Zero<Number>, static_cast<Number>(360)>(degree);
    }

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arcsine(const Number& value) {
        Number radian = std::asin(static_cast<double>(value));
        return Angle<Number, -pi<Number>, pi<Number>>(static_cast<Number>(radian));
    }

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arccosine(const Number& value) {
        Number radian = std::acos(static_cast<double>(value));
        return Angle<Number, -pi<Number>, pi<Number>>(static_cast<Number>(radian));
    }

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arctangent(const Number& value) {
        Number radian = std::atan(static_cast<double>(value));
        return Angle<Number, -pi<Number>, pi<Number>>(static_cast<Number>(radian));
    }

    template<typename Number>
    Angle<Number, -pi<Number>, pi<Number>> arctangent(const Number& x, const Number& y) {
        Number radian = std::atan2(static_cast<double>(y), static_cast<double>(x));
        return Angle<Number, -pi<Number>, pi<Number>>(static_cast<Number>(radian));
    }

    template<typename Number>
    class Complex {
    private:
        Number real;
        Number imaginary;
    public:
        Complex() : real(Zero<Number>), imaginary(Zero<Number>) {}
        Complex(const Number& real, const Number& imaginary) : real(real), imaginary(imaginary) {}
        Complex(const std::complex<Number>& number) : real(number.real()), imaginary(number.imag()) {}
        Complex(const std::pair<Number, Number>&& number) : real(number.first), imaginary(number.second) {}
        Complex(const std::tuple<Number, Number>&& number) : real(std::get<0>(number)), imaginary(std::get<1>(number)) {}
        Complex(const std::initializer_list<Number>& number) {
            switch (number.size()) {
            case 0:
                real = Zero<Number>;
                imaginary = Zero<Number>;
                break;
            case 1:
                real = *number.begin();
                imaginary = Zero<Number>;
                break;
            case 2:
                real = *number.begin();
                imaginary = *(number.begin() + One<Number>);
                break;
            default:
                real = *number.begin();
                imaginary = *(number.begin() + One<Number>);
                break;
            }
        }
        Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}
        ~Complex() {}

        Complex<Number>& operator=(const std::complex<Number>& number) {
            real = number.real();
            imaginary = number.imag();
            return *this;
        }
        Complex<Number>& operator=(const std::pair<Number, Number>&& number) {
            real = number.first;
            imaginary = number.second;
            return *this;
        }
        Complex<Number>& operator=(const std::tuple<Number, Number>&& number) {
            real = std::get<0>(number);
            imaginary = std::get<1>(number);
            return *this;
        }
        Complex<Number>& operator=(const std::initializer_list<Number>& number) {
            switch (number.size()) {
            case 0:
                real = Zero<Number>;
                imaginary = Zero<Number>;
                break;
            case 1:
                real = *number.begin();
                imaginary = Zero<Number>;
                break;
            case 2:
                real = *number.begin();
                imaginary = *(number.begin() + One<Number>);
                break;
            default:
                real = *number.begin();
                imaginary = *(number.begin() + One<Number>);
                break;
            }
            return *this;
        }

        Complex<Number>& operator=(const Complex<Number>& other) {
            real = other.real;
            imaginary = other.imaginary;
            return *this;
        }

        Number getReal() const {
            return real;
        }

        Number getImaginary() const {
            return imaginary;
        }

        Angle<Number, -pi<Number>, pi<Number>> argument() const {
            return arctangent(imaginary, real);
        }

        Complex<Number> absolute() const {
            return Complex<Number>(std::abs(real), std::abs(imaginary));
        }

        Complex<Number> negate() const {
            return Complex<Number>(-real, -imaginary);
        }

        Number magnitude() const {
            return std::sqrt(real * real + imaginary * imaginary);
        }

        Complex<Number> conjugate() const {
            return Complex<Number>(real, -imaginary);
        }

        Complex<Number> reciprocal() const {
            Number denominator = real * real + imaginary * imaginary;
            return Complex<Number>(real / denominator, -imaginary / denominator);
        }

        Complex<Number> normalize() const {
            const Number magnitude = this->magnitude();
            if (magnitude == Zero<Number>) {
                return Complex<Number>(Zero<Number>, Zero<Number>);
            }
            return Complex<Number>(real / magnitude, imaginary / magnitude);
        }

        Complex<Number> similarity(const Complex<Number>& other) const {
            Angle<Number, -pi<Number>, pi<Number>> angle = argument() - other.argument();
            return Complex<Number>(angle.cosine(), angle.sine());
        }

        Complex<Number> tendency(const Complex<Number>& other) const {
            return Complex<Number>(dot(other), cross(other));
        }

        Number dot(const Complex<Number>& other) const {
            return real * other.real + imaginary * other.imaginary;
        }

        Number cross(const Complex<Number>& other) const {
            return real * other.imaginary - imaginary * other.real;
        }

        Complex<Number> normal(const Complex<Number>& surface) const {
            Complex<Number> unitNormal = Complex<Number>(-surface.imaginary, surface.real).normalize();
            Number dotProduct = real * unitNormal.real + imaginary * unitNormal.imaginary;
            return Complex<Number>(dotProduct * unitNormal.real, dotProduct * unitNormal.imaginary);
        }

        Complex<Number> reflect(const Complex<Number>& surfaceNormal) const {
            Number dotProduct = real * surfaceNormal.real + imaginary * surfaceNormal.imaginary;
            return Complex<Number>(real - static_cast<Number>(2.0) * dotProduct * surfaceNormal.real, imaginary - static_cast<Number>(2.0) * dotProduct * surfaceNormal.imaginary);
        }

        Complex<Number> refract(const Complex<Number>& surfaceNormal, Number refractiveIndex) const {
            Number dotProduct = real * surfaceNormal.real + imaginary * surfaceNormal.imaginary;
            Number discriminant = static_cast<Number>(1.0) - refractiveIndex * refractiveIndex * (static_cast<Number>(1.0) - dotProduct * dotProduct);

            if (discriminant < Zero<Number>) {
                return reflect(surfaceNormal);
            }

            Number sqrtDiscriminant = std::sqrt(discriminant);
            return Complex<Number>(refractiveIndex * real - (refractiveIndex * dotProduct + sqrtDiscriminant) * surfaceNormal.real, refractiveIndex * imaginary - (refractiveIndex * dotProduct + sqrtDiscriminant) * surfaceNormal.imaginary);
        }

        friend Complex<Number> operator+(const Complex<Number>& a, const Complex<Number>& b) {
            return Complex<Number>(a.real + b.real, a.imaginary + b.imaginary);
        }

        friend Complex<Number> operator+(const Number& a, const Complex<Number>& b) {
            return Complex<Number>(a + b.real, b.imaginary);
        }

        friend Complex<Number> operator+(const Complex<Number>& a, const Number& b) {
            return Complex<Number>(a.real + b, a.imaginary);
        }

        friend Complex<Number> operator-(const Complex<Number>& a, const Complex<Number>& b) {
            return Complex<Number>(a.real - b.real, a.imaginary - b.imaginary);
        }

        friend Complex<Number> operator-(const Number& a, const Complex<Number>& b) {
            return Complex<Number>(a - b.real, -b.imaginary);
        }

        friend Complex<Number> operator-(const Complex<Number>& a, const Number& b) {
            return Complex<Number>(a.real - b, a.imaginary);
        }

        friend Complex<Number> operator*(const Complex<Number>& a, const Complex<Number>& b) {
            return Complex<Number>(
                a.real * b.real - a.imaginary * b.imaginary,
                a.real * b.imaginary + a.imaginary * b.real
            );
        }

        friend Complex<Number> operator*(const Number& a, const Complex<Number>& b) {
            return Complex<Number>(a * b.real, a * b.imaginary);
        }

        friend Complex<Number> operator*(const Complex<Number>& a, const Number& b) {
            return Complex<Number>(a.real * b, a.imaginary * b);
        }

        friend Complex<Number> operator/(const Complex<Number>& a, const Complex<Number>& b) {
            Number denominator = b.real * b.real + b.imaginary * b.imaginary;
            return Complex<Number>(
                (a.real * b.real + a.imaginary * b.imaginary) / denominator,
                (a.imaginary * b.real - a.real * b.imaginary) / denominator
            );
        }

        friend Complex<Number> operator/(const Number& a, const Complex<Number>& b) {
            Number denominator = b.real * b.real + b.imaginary * b.imaginary;
            return Complex<Number>(
                a * b.real / denominator,
                -a * b.imaginary / denominator
            );
        }

        friend Complex<Number> operator/(const Complex<Number>& a, const Number& b) {
            return Complex<Number>(a.real / b, a.imaginary / b);
        }

        friend bool operator==(const Complex<Number>& a, const Complex<Number>& b) {
            return a.real == b.real && a.imaginary == b.imaginary;
        }

        friend bool operator!=(const Complex<Number>& a, const Complex<Number>& b) {
            return !(a == b);
        }

        friend bool operator>(const Complex<Number>& a, const Complex<Number>& b) {
            return a.magnitude() > b.magnitude();
        }

        friend bool operator>=(const Complex<Number>& a, const Complex<Number>& b) {
            return a.magnitude() >= b.magnitude();
        }

        friend bool operator<(const Complex<Number>& a, const Complex<Number>& b) {
            return a.magnitude() < b.magnitude();
        }

        friend bool operator<=(const Complex<Number>& a, const Complex<Number>& b) {
            return a.magnitude() <= b.magnitude();
        }

        explicit operator std::complex<Number>() const {
            return std::complex<Number>(real, imaginary);
        }

        template<size_t Index>
        Number get() const {
            static_assert(Index < 2, "Index out of range for Complex");
            if constexpr (Index == 0) {
                return real;
            }
            else {
                return imaginary;
            }
        }

        friend std::ostream& operator<<(std::ostream& output, const Complex<Number>& complex) {
            output << complex.real;
            if (complex.imaginary >= Zero<Number>) {
                output << " + ";
            }
            else {
                output << " - ";
            }
            output << std::abs(complex.imaginary) << "i";
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Complex<Number>& complex) {
            input >> complex.real;
            char sign;
            input >> sign;
            input >> complex.imaginary;
            return input;
        }
    };

    template<typename Number>
    class Quaternion {
    private:
        Number a;
        Number b;
        Number c;
        Number d;
    public:
        Quaternion() : a(Zero<Number>), b(Zero<Number>), c(Zero<Number>), d(Zero<Number>) {}
        Quaternion(const Number& a, const Number& b, const Number& c, const Number& d) : a(a), b(b), c(c), d(d) {}
        Quaternion(const std::tuple<Number, Number, Number, Number>&& number) : a(std::get<0>(number)), b(std::get<1>(number)), c(std::get<2>(number)), d(std::get<3>(number)) {}
        Quaternion(const std::initializer_list<Number>& number) {
            switch (number.size()) {
            case 0:
                a = Zero<Number>;
                b = Zero<Number>;
                c = Zero<Number>;
                d = Zero<Number>;
                break;
            case 1:
                a = *number.begin();
                b = Zero<Number>;
                c = Zero<Number>;
                d = Zero<Number>;
                break;
            case 2:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = Zero<Number>;
                d = Zero<Number>;
                break;
            case 3:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = *(number.begin() + 2);
                d = Zero<Number>;
                break;
            case 4:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = *(number.begin() + 2);
                d = *(number.begin() + 3);
                break;
            default:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = *(number.begin() + 2);
                d = *(number.begin() + 3);
                break;
            }
        }
        Quaternion(const Quaternion& other) : a(other.a), b(other.b), c(other.c), d(other.d) {}
        ~Quaternion() {}

        Quaternion<Number>& operator=(const std::tuple<Number, Number, Number, Number>&& number) {
            a = std::get<0>(number);
            b = std::get<1>(number);
            c = std::get<2>(number);
            d = std::get<3>(number);
            return *this;
        }
        Quaternion<Number>& operator=(const std::initializer_list<Number>& number) {
            switch (number.size()) {
            case 0:
                a = Zero<Number>;
                b = Zero<Number>;
                c = Zero<Number>;
                d = Zero<Number>;
                break;
            case 1:
                a = *number.begin();
                b = Zero<Number>;
                c = Zero<Number>;
                d = Zero<Number>;
                break;
            case 2:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = Zero<Number>;
                d = Zero<Number>;
                break;
            case 3:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = *(number.begin() + 2);
                d = Zero<Number>;
                break;
            case 4:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = *(number.begin() + 2);
                d = *(number.begin() + 3);
                break;
            default:
                a = *number.begin();
                b = *(number.begin() + 1);
                c = *(number.begin() + 2);
                d = *(number.begin() + 3);
                break;
            }
            return *this;
        }
        Quaternion<Number>& operator=(const Quaternion<Number>& other) {
            a = other.a;
            b = other.b;
            c = other.c;
            d = other.d;
            return *this;
        }

        template<size_t Index>
        Number get() const {
            static_assert(Index < 4, "Index out of range for Complex");
            if constexpr (Index == 0) {
                return a;
            }else if constexpr (Index == 1) {
                return b;
            }
            else if constexpr (Index == 2) {
                return c;
            }
            else {
                return d;
            }
        }

        Number getA() const {
            return a;
        }

        Number getB() const {
            return b;
        }

        Number getC() const {
            return c;
        }

        Number getD() const {
            return d;
        }

        Quaternion<Number> absolute() const {
            return Quaternion<Number>(std::abs(a), std::abs(b), std::abs(c), std::abs(d));
        }

        Quaternion<Number> negate() const {
            return Quaternion<Number>(-a, -b, -c, -d);
        }

        Number normalize() const {
            const Number magnitude = this->magnitude();
            if (magnitude == Zero<Number>) {
                return Quaternion<Number>(Zero<Number>, Zero<Number>, Zero<Number>, Zero<Number>);
            }
            return Quaternion<Number>(a / magnitude, b / magnitude, c / magnitude, d / magnitude);
        }

        Number magnitude() const {
            return std::sqrt(a * a + b * b + c * c + d * d);
        }

        Quaternion<Number> normal(const Quaternion<Number>& surface) const {
            Quaternion<Number> unitVector = surface.vector().normalize();
            Number dotProduct = b * unitVector.b + c * unitVector.c + d * unitVector.d;
            return Quaternion<Number>(
                Zero<Number>,
                b - dotProduct * unitVector.b,
                c - dotProduct * unitVector.c,
                d - dotProduct * unitVector.d
            );
        }

        Quaternion<Number> reflect(const Quaternion<Number>& surfaceNormal) const {
            Number dotProduct = a * surfaceNormal.a + b * surfaceNormal.b + c * surfaceNormal.c + d * surfaceNormal.d;
            return Quaternion<Number>(
                a - static_cast<Number>(2.0) * dotProduct * surfaceNormal.a,
                b - static_cast<Number>(2.0) * dotProduct * surfaceNormal.b,
                c - static_cast<Number>(2.0) * dotProduct * surfaceNormal.c,
                d - static_cast<Number>(2.0) * dotProduct * surfaceNormal.d
            );
        }

        Quaternion<Number> refract(const Quaternion<Number>& surfaceNormal, Number refractiveIndex) const {
            Number dotProduct = a * surfaceNormal.a + b * surfaceNormal.b + c * surfaceNormal.c + d * surfaceNormal.d;
            Number discriminant = static_cast<Number>(1.0) - refractiveIndex * refractiveIndex * (static_cast<Number>(1.0) - dotProduct * dotProduct);

            if (discriminant < Zero<Number>) {
                return reflect(surfaceNormal);
            }

            Number sqrtDiscriminant = std::sqrt(discriminant);
            return Quaternion<Number>(
                refractiveIndex * a - (refractiveIndex * dotProduct + sqrtDiscriminant) * surfaceNormal.a,
                refractiveIndex * b - (refractiveIndex * dotProduct + sqrtDiscriminant) * surfaceNormal.b,
                refractiveIndex * c - (refractiveIndex * dotProduct + sqrtDiscriminant) * surfaceNormal.c,
                refractiveIndex * d - (refractiveIndex * dotProduct + sqrtDiscriminant) * surfaceNormal.d
            );
        }

        Angle<Number, -pi<Number>, pi<Number>> argument() const {
            Number scalar = a;
            Number vectorNorm = std::sqrt(b * b + c * c + d * d);
            Number halfAngle = std::atan2(vectorNorm, scalar);
            Number angle = static_cast<Number>(2.0) * halfAngle;
            if (angle > pi<Number>) {
                angle -= static_cast<Number>(2.0) * pi<Number>;
            }
            return Angle<Number, -pi<Number>, pi<Number>>(angle);
        }

        Quaternion<Number> cross(const Quaternion<Number>& other) const {
            return Quaternion<Number>( Zero<Number>,c * other.d - d * other.c, d * other.b - b * other.d,b * other.c - c * other.b  );
        }

        Number dot(const Quaternion<Number>& other) const {
            return a * other.a + b * other.b + c * other.c + d * other.d;
        }

        Quaternion<Number> similarity(const Quaternion<Number>& other) const {
            Quaternion<Number> self = this->normalize();
            Quaternion<Number> otherNormalized = other.normalize();
            Quaternion<Number> difference = otherNormalized * self.conjugate();
            return difference;
        }

        Quaternion<Number> tendency(const Quaternion<Number>& other) const {
            Quaternion<Number> difference = other * conjugate();
            return difference;
        }

        Quaternion<Number> reciprocal() const {
            Number denominator = magnitude();
            return Quaternion<Number>(a / denominator, -b / denominator, -c / denominator, -d / denominator);
        }

        Quaternion<Number> conjugate() const {
            return Quaternion<Number>(a, -b, -c, -d);
        }

        friend Quaternion<Number> operator+(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return Quaternion<Number>(
                left.a + right.a,
                left.b + right.b,
                left.c + right.c,
                left.d + right.d
            );
        }

        friend Quaternion<Number> operator+(const Number& left, const Quaternion<Number>& right) {
            return Quaternion<Number>(left + right.a, right.b, right.c, right.d);
        }

        friend Quaternion<Number> operator+(const Quaternion<Number>& left, const Number& right) {
            return Quaternion<Number>(left.a + right, left.b, left.c, left.d);
        }

        friend Quaternion<Number> operator-(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return Quaternion<Number>(
                left.a - right.a,
                left.b - right.b,
                left.c - right.c,
                left.d - right.d
            );
        }

        friend Quaternion<Number> operator-(const Number& left, const Quaternion<Number>& right) {
            return Quaternion<Number>(left - right.a, -right.b, -right.c, -right.d);
        }

        friend Quaternion<Number> operator-(const Quaternion<Number>& left, const Number& right) {
            return Quaternion<Number>(left.a - right, left.b, left.c, left.d);
        }

        friend Quaternion<Number> operator*(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return Quaternion<Number>(
                left.a * right.a - left.b * right.b - left.c * right.c - left.d * right.d,
                left.a * right.b + left.b * right.a + left.c * right.d - left.d * right.c,
                left.a * right.c - left.b * right.d + left.c * right.a + left.d * right.b,
                left.a * right.d + left.b * right.c - left.c * right.b + left.d * right.a
            );
        }

        Quaternion<Number> lerp(const Quaternion<Number>& other, Number factor) const {
            return Quaternion<Number>(
                a + (other.a - a) * factor,
                b + (other.b - b) * factor,
                c + (other.c - c) * factor,
                d + (other.d - d) * factor
            );
        }

        Quaternion<Number> nlerp(const Quaternion<Number>& other, Number factor) const {
            return lerp(other, factor).normalize();
        }

        Quaternion<Number> slerp(const Quaternion<Number>& other, Number factor) const {
            Quaternion<Number> selfNormalized = this->normalize();
            Quaternion<Number> otherNormalized = other.normalize();

            Number cosOmega = selfNormalized.dot(otherNormalized);

            Quaternion<Number> adjustedOther = otherNormalized;
            if (cosOmega < Zero<Number>) {
                adjustedOther = adjustedOther.negate();
                cosOmega = -cosOmega;
            }

            if (cosOmega > static_cast<Number>(0.9995)) {
                return selfNormalized.nlerp(adjustedOther, factor);
            }

            Number omega = std::acos(static_cast<double>(cosOmega));
            Number sinOmega = std::sin(static_cast<double>(omega));

            Number selfWeight = std::sin(static_cast<double>((static_cast<Number>(1.0) - factor) * omega)) / sinOmega;
            Number otherWeight = std::sin(static_cast<double>(factor * omega)) / sinOmega;

            return Quaternion<Number>(
                selfWeight * selfNormalized.a + otherWeight * adjustedOther.a,
                selfWeight * selfNormalized.b + otherWeight * adjustedOther.b,
                selfWeight * selfNormalized.c + otherWeight * adjustedOther.c,
                selfWeight * selfNormalized.d + otherWeight * adjustedOther.d
            );
        }

        friend Quaternion<Number> operator*(const Number& left, const Quaternion<Number>& right) {
            return Quaternion<Number>(left * right.a, left * right.b, left * right.c, left * right.d);
        }

        friend Quaternion<Number> operator*(const Quaternion<Number>& left, const Number& right) {
            return Quaternion<Number>(left.a * right, left.b * right, left.c * right, left.d * right);
        }

        friend Quaternion<Number> operator/(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return left * right.reciprocal();
        }

        friend Quaternion<Number> operator/(const Number& left, const Quaternion<Number>& right) {
            return left * right.reciprocal();
        }

        friend Quaternion<Number> operator/(const Quaternion<Number>& left, const Number& right) {
            return Quaternion<Number>(left.a / right, left.b / right, left.c / right, left.d / right);
        }

        friend bool operator==(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return left.a == right.a && left.b == right.b && left.c == right.c && left.d == right.d;
        }

        friend bool operator!=(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return !(left == right);
        }

        friend bool operator>(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return left.magnitude() > right.magnitude();
        }

        friend bool operator>=(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return left.magnitude() >= right.magnitude();
        }

        friend bool operator<(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return left.magnitude() < right.magnitude();
        }

        friend bool operator<=(const Quaternion<Number>& left, const Quaternion<Number>& right) {
            return left.magnitude() <= right.magnitude();
        }

        Quaternion<Number> operator+() const {
            return *this;
        }

        Quaternion<Number> operator-() const {
            return Quaternion<Number>(-a, -b, -c, -d);
        }

        Quaternion<Number>& operator+=(const Quaternion<Number>& other) {
            a += other.a;
            b += other.b;
            c += other.c;
            d += other.d;
            return *this;
        }

        Quaternion<Number>& operator-=(const Quaternion<Number>& other) {
            a -= other.a;
            b -= other.b;
            c -= other.c;
            d -= other.d;
            return *this;
        }

        Quaternion<Number>& operator*=(const Quaternion<Number>& other) {
            *this = *this * other;
            return *this;
        }

        Quaternion<Number>& operator*=(const Number& scalar) {
            a *= scalar;
            b *= scalar;
            c *= scalar;
            d *= scalar;
            return *this;
        }

        Quaternion<Number>& operator/=(const Number& scalar) {
            a /= scalar;
            b /= scalar;
            c /= scalar;
            d /= scalar;
            return *this;
        }

        explicit operator std::complex<Number>() const {
            return std::complex<Number>(a, b);
        }

        friend std::ostream& operator<<(std::ostream& output, const Quaternion<Number>& quaternion) {
            output << quaternion.a;
            if (quaternion.b >= Zero<Number>) {
                output << " + ";
            }
            else {
                output << " - ";
            }
            output << std::abs(quaternion.b) << "i";
            if (quaternion.c >= Zero<Number>) {
                output << " + ";
            }
            else {
                output << " - ";
            }
            output << std::abs(quaternion.c) << "j";
            if (quaternion.d >= Zero<Number>) {
                output << " + ";
            }
            else {
                output << " - ";
            }
            output << std::abs(quaternion.d) << "k";
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Quaternion<Number>& quaternion) {
            input >> quaternion.a >> quaternion.b >> quaternion.c >> quaternion.d;
            return input;
        }
    };
};

namespace std {
    template<typename Number>
    struct tuple_size<periodicity::Complex<Number>> : integral_constant<size_t, 2> {};

    template<typename Number>
    struct tuple_element<0, periodicity::Complex<Number>> {
        using type = Number;
    };

    template<typename Number>
    struct tuple_element<1, periodicity::Complex<Number>> {
        using type = Number;
    };

    template<size_t Index, typename Number>
    Number get(const periodicity::Complex<Number>& complex) {
        return complex.template get<Index>();
    }

    template<typename Number>
    struct tuple_size<periodicity::Quaternion<Number>> : integral_constant<size_t, 4> {};

    template<typename Number>
    struct tuple_element<0, periodicity::Quaternion<Number>> {
        using type = Number;
    };

    template<typename Number>
    struct tuple_element<1, periodicity::Quaternion<Number>> {
        using type = Number;
    };

    template<size_t Index, typename Number>
    Number get(const periodicity::Quaternion<Number>& quaternion) {
        return quaternion.template get<Index>();
    }
}
