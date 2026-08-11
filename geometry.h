#pragma once
#include <deque>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "numerical.h"

namespace periodicity {

    template<typename Number>
    class Amplitude;

    template<typename Number>
    class Frequency;

    template<typename Number>
    class Period;

    template<typename Number>
    class Omega;

    template<typename Number>
    class Phase;

    template<typename Number>
    class Epicycle;

    template<typename Number>
    class Ellipse;

    template<typename Number>
    class Rotation;

    template<typename Number>
    class Spectral;

    template<typename Number>
    class Waveform;

    template<typename Number>
    class Spectrum;

    template<typename Number>
    class Amplitude {
    private:
        Number value;
    public:
        Amplitude() : value(Zero<Number>) {}
        explicit Amplitude(Number initValue) : value(initValue) {}

        Number getValue() const {
            return value;
        }

        friend Amplitude<Number> operator+(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return Amplitude<Number>(first.value + second.value);
        }

        friend Amplitude<Number> operator-(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return Amplitude<Number>(first.value - second.value);
        }

        friend Amplitude<Number> operator*(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return Amplitude<Number>(first.value * second.value);
        }

        friend Amplitude<Number> operator/(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return Amplitude<Number>(first.value / second.value);
        }

        friend Amplitude<Number> operator*(const Number& scalar, const Amplitude<Number>& amplitude) {
            return Amplitude<Number>(scalar * amplitude.value);
        }

        friend Amplitude<Number> operator*(const Amplitude<Number>& amplitude, const Number& scalar) {
            return Amplitude<Number>(amplitude.value * scalar);
        }

        friend Amplitude<Number> operator/(const Amplitude<Number>& amplitude, const Number& scalar) {
            return Amplitude<Number>(amplitude.value / scalar);
        }

        friend bool operator==(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return first.value == second.value;
        }

        friend bool operator!=(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return !(first == second);
        }

        friend bool operator<(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return first.value < second.value;
        }

        friend bool operator<=(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return first.value <= second.value;
        }

        friend bool operator>(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return first.value > second.value;
        }

        friend bool operator>=(const Amplitude<Number>& first, const Amplitude<Number>& second) {
            return first.value >= second.value;
        }

        friend std::ostream& operator<<(std::ostream& output, const Amplitude<Number>& amplitude) {
            output << amplitude.value;
            return output;
        }
    };

    template<typename Number>
    class Frequency {
    private:
        Number frequency;
    public:
        Frequency() : frequency(Zero<Number>) {}

        explicit Frequency(Number initFrequency) : frequency(initFrequency) {}

        Number getValue() const {
            return frequency;
        }

        Frequency<Number>& operator=(const Number& value) {
            frequency = value;
            return *this;
        }

        Frequency<Number>& operator=(const Frequency<Number>& other) {
            frequency = other.frequency;
            return *this;
        }

        friend Frequency<Number> operator+(const Frequency<Number>& left, const Frequency<Number>& right) {
            return Frequency<Number>(left.frequency + right.frequency);
        }

        friend Frequency<Number> operator+(const Number& left, const Frequency<Number>& right) {
            return Frequency<Number>(left + right.frequency);
        }

        friend Frequency<Number> operator+(const Frequency<Number>& left, const Number& right) {
            return Frequency<Number>(left.frequency + right);
        }

        friend Frequency<Number> operator-(const Frequency<Number>& left, const Frequency<Number>& right) {
            return Frequency<Number>(left.frequency - right.frequency);
        }

        friend Frequency<Number> operator-(const Number& left, const Frequency<Number>& right) {
            return Frequency<Number>(left - right.frequency);
        }

        friend Frequency<Number> operator-(const Frequency<Number>& left, const Number& right) {
            return Frequency<Number>(left.frequency - right);
        }

        friend Frequency<Number> operator*(const Frequency<Number>& left, const Frequency<Number>& right) {
            return Frequency<Number>(left.frequency * right.frequency);
        }

        friend Frequency<Number> operator*(const Number& left, const Frequency<Number>& right) {
            return Frequency<Number>(left * right.frequency);
        }

        friend Frequency<Number> operator*(const Frequency<Number>& left, const Number& right) {
            return Frequency<Number>(left.frequency * right);
        }

        friend Frequency<Number> operator/(const Frequency<Number>& left, const Frequency<Number>& right) {
            return Frequency<Number>(left.frequency / right.frequency);
        }

        friend Frequency<Number> operator/(const Number& left, const Frequency<Number>& right) {
            return Frequency<Number>(left / right.frequency);
        }

        friend Frequency<Number> operator/(const Frequency<Number>& left, const Number& right) {
            return Frequency<Number>(left.frequency / right);
        }

        friend bool operator==(const Frequency<Number>& left, const Frequency<Number>& right) {
            return left.frequency == right.frequency;
        }

        friend bool operator!=(const Frequency<Number>& left, const Frequency<Number>& right) {
            return !(left == right);
        }

        friend bool operator<(const Frequency<Number>& left, const Frequency<Number>& right) {
            return left.frequency < right.frequency;
        }

        friend bool operator<=(const Frequency<Number>& left, const Frequency<Number>& right) {
            return left.frequency <= right.frequency;
        }

        friend bool operator>(const Frequency<Number>& left, const Frequency<Number>& right) {
            return left.frequency > right.frequency;
        }

        friend bool operator>=(const Frequency<Number>& left, const Frequency<Number>& right) {
            return left.frequency >= right.frequency;
        }

        Frequency<Number> operator+() const {
            return *this;
        }

        Frequency<Number> operator-() const {
            return Frequency<Number>(-frequency);
        }

        Frequency<Number>& operator+=(const Frequency<Number>& other) {
            frequency += other.frequency;
            return *this;
        }

        Frequency<Number>& operator-=(const Frequency<Number>& other) {
            frequency -= other.frequency;
            return *this;
        }

        Frequency<Number>& operator*=(const Number& scalar) {
            frequency *= scalar;
            return *this;
        }

        Frequency<Number>& operator/=(const Number& scalar) {
            frequency /= scalar;
            return *this;
        }

        Period<Number> toPeriod() const;

        Omega<Number> toOmega() const;

        friend std::ostream& operator<<(std::ostream& output, const Frequency<Number>& freq) {
            output << freq.frequency << " Hz";
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Frequency<Number>& freq) {
            input >> freq.frequency;
            return input;
        }
    };

    template<typename Number>
    class Period {
    private:
        Number period;
    public:
        Period() : period(Zero<Number>) {}

        explicit Period(Number initPeriod) : period(initPeriod) {}

        Number getValue() const {
            return period;
        }

        Period<Number>& operator=(const Number& value) {
            period = value;
            return *this;
        }

        Period<Number>& operator=(const Period<Number>& other) {
            period = other.period;
            return *this;
        }

        friend Period<Number> operator+(const Period<Number>& left, const Period<Number>& right) {
            return Period<Number>(left.period + right.period);
        }

        friend Period<Number> operator+(const Number& left, const Period<Number>& right) {
            return Period<Number>(left + right.period);
        }

        friend Period<Number> operator+(const Period<Number>& left, const Number& right) {
            return Period<Number>(left.period + right);
        }

        friend Period<Number> operator-(const Period<Number>& left, const Period<Number>& right) {
            return Period<Number>(left.period - right.period);
        }

        friend Period<Number> operator-(const Number& left, const Period<Number>& right) {
            return Period<Number>(left - right.period);
        }

        friend Period<Number> operator-(const Period<Number>& left, const Number& right) {
            return Period<Number>(left.period - right);
        }

        friend Period<Number> operator*(const Period<Number>& left, const Period<Number>& right) {
            return Period<Number>(left.period * right.period);
        }

        friend Period<Number> operator*(const Number& left, const Period<Number>& right) {
            return Period<Number>(left * right.period);
        }

        friend Period<Number> operator*(const Period<Number>& left, const Number& right) {
            return Period<Number>(left.period * right);
        }

        friend Period<Number> operator/(const Period<Number>& left, const Period<Number>& right) {
            return Period<Number>(left.period / right.period);
        }

        friend Period<Number> operator/(const Number& left, const Period<Number>& right) {
            return Period<Number>(left / right.period);
        }

        friend Period<Number> operator/(const Period<Number>& left, const Number& right) {
            return Period<Number>(left.period / right);
        }

        friend bool operator==(const Period<Number>& left, const Period<Number>& right) {
            return left.period == right.period;
        }

        friend bool operator!=(const Period<Number>& left, const Period<Number>& right) {
            return !(left == right);
        }

        friend bool operator<(const Period<Number>& left, const Period<Number>& right) {
            return left.period < right.period;
        }

        friend bool operator<=(const Period<Number>& left, const Period<Number>& right) {
            return left.period <= right.period;
        }

        friend bool operator>(const Period<Number>& left, const Period<Number>& right) {
            return left.period > right.period;
        }

        friend bool operator>=(const Period<Number>& left, const Period<Number>& right) {
            return left.period >= right.period;
        }

        Period<Number> operator+() const {
            return *this;
        }

        Period<Number> operator-() const {
            return Period<Number>(-period);
        }

        Period<Number>& operator+=(const Period<Number>& other) {
            period += other.period;
            return *this;
        }

        Period<Number>& operator-=(const Period<Number>& other) {
            period -= other.period;
            return *this;
        }

        Period<Number>& operator*=(const Number& scalar) {
            period *= scalar;
            return *this;
        }

        Period<Number>& operator/=(const Number& scalar) {
            period /= scalar;
            return *this;
        }

        Frequency<Number> toFrequency() const;

        Omega<Number> toOmega() const;

        friend std::ostream& operator<<(std::ostream& output, const Period<Number>& periodObj) {
            output << periodObj.period << " s";
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Period<Number>& periodObj) {
            input >> periodObj.period;
            return input;
        }
    };

    template<typename Number>
    class Omega {
    private:
        Number omega;
    public:
        Omega() : omega(Zero<Number>) {}

        explicit Omega(Number initOmega) : omega(initOmega) {}

        Number getValue() const {
            return omega;
        }

        Omega<Number>& operator=(const Number& value) {
            omega = value;
            return *this;
        }

        Omega<Number>& operator=(const Omega<Number>& other) {
            omega = other.omega;
            return *this;
        }

        friend Omega<Number> operator+(const Omega<Number>& left, const Omega<Number>& right) {
            return Omega<Number>(left.omega + right.omega);
        }

        friend Omega<Number> operator+(const Number& left, const Omega<Number>& right) {
            return Omega<Number>(left + right.omega);
        }

        friend Omega<Number> operator+(const Omega<Number>& left, const Number& right) {
            return Omega<Number>(left.omega + right);
        }

        friend Omega<Number> operator-(const Omega<Number>& left, const Omega<Number>& right) {
            return Omega<Number>(left.omega - right.omega);
        }

        friend Omega<Number> operator-(const Number& left, const Omega<Number>& right) {
            return Omega<Number>(left - right.omega);
        }

        friend Omega<Number> operator-(const Omega<Number>& left, const Number& right) {
            return Omega<Number>(left.omega - right);
        }

        friend Omega<Number> operator*(const Omega<Number>& left, const Omega<Number>& right) {
            return Omega<Number>(left.omega * right.omega);
        }

        friend Omega<Number> operator*(const Number& left, const Omega<Number>& right) {
            return Omega<Number>(left * right.omega);
        }

        friend Omega<Number> operator*(const Omega<Number>& left, const Number& right) {
            return Omega<Number>(left.omega * right);
        }

        friend Omega<Number> operator/(const Omega<Number>& left, const Omega<Number>& right) {
            return Omega<Number>(left.omega / right.omega);
        }

        friend Omega<Number> operator/(const Number& left, const Omega<Number>& right) {
            return Omega<Number>(left / right.omega);
        }

        friend Omega<Number> operator/(const Omega<Number>& left, const Number& right) {
            return Omega<Number>(left.omega / right);
        }

        friend bool operator==(const Omega<Number>& left, const Omega<Number>& right) {
            return left.omega == right.omega;
        }

        friend bool operator!=(const Omega<Number>& left, const Omega<Number>& right) {
            return !(left == right);
        }

        friend bool operator<(const Omega<Number>& left, const Omega<Number>& right) {
            return left.omega < right.omega;
        }

        friend bool operator<=(const Omega<Number>& left, const Omega<Number>& right) {
            return left.omega <= right.omega;
        }

        friend bool operator>(const Omega<Number>& left, const Omega<Number>& right) {
            return left.omega > right.omega;
        }

        friend bool operator>=(const Omega<Number>& left, const Omega<Number>& right) {
            return left.omega >= right.omega;
        }

        Omega<Number> operator+() const {
            return *this;
        }

        Omega<Number> operator-() const {
            return Omega<Number>(-omega);
        }

        Omega<Number>& operator+=(const Omega<Number>& other) {
            omega += other.omega;
            return *this;
        }

        Omega<Number>& operator-=(const Omega<Number>& other) {
            omega -= other.omega;
            return *this;
        }

        Omega<Number>& operator*=(const Number& scalar) {
            omega *= scalar;
            return *this;
        }

        Omega<Number>& operator/=(const Number& scalar) {
            omega /= scalar;
            return *this;
        }

        Frequency<Number> toFrequency() const;

        Period<Number> toPeriod() const;

        friend std::ostream& operator<<(std::ostream& output, const Omega<Number>& omegaObj) {
            output << omegaObj.omega << " rad/s";
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Omega<Number>& omegaObj) {
            input >> omegaObj.omega;
            return input;
        }
    };

    template<typename Number>
    class Phase {
    private:
        Angle<Number, -pi<Number>, pi<Number>> phase;
    public:
        Phase() : phase() {}

        explicit Phase(const Angle<Number, -pi<Number>, pi<Number>>& initPhase) : phase(initPhase) {}

        Phase(const Number& value) : phase(Angle<Number, -pi<Number>, pi<Number>>(value)) {}

        Angle<Number, -pi<Number>, pi<Number>> getAngle() const {
            return phase;
        }

        Number getValue() const {
            return phase.getValue();
        }

        Phase<Number>& operator=(const Number& value) {
            phase = Angle<Number, -pi<Number>, pi<Number>>(value);
            return *this;
        }

        Phase<Number>& operator=(const Angle<Number, -pi<Number>, pi<Number>>& angle) {
            phase = angle;
            return *this;
        }

        Phase<Number>& operator=(const Phase<Number>& other) {
            phase = other.phase;
            return *this;
        }

        friend Phase<Number> operator+(const Phase<Number>& left, const Phase<Number>& right) {
            return Phase<Number>(left.phase + right.phase);
        }

        friend Phase<Number> operator+(const Number& left, const Phase<Number>& right) {
            return Phase<Number>(left + right.phase);
        }

        friend Phase<Number> operator+(const Phase<Number>& left, const Number& right) {
            return Phase<Number>(left.phase + right);
        }

        friend Phase<Number> operator-(const Phase<Number>& left, const Phase<Number>& right) {
            return Phase<Number>(left.phase - right.phase);
        }

        friend Phase<Number> operator-(const Number& left, const Phase<Number>& right) {
            return Phase<Number>(left - right.phase);
        }

        friend Phase<Number> operator-(const Phase<Number>& left, const Number& right) {
            return Phase<Number>(left.phase - right);
        }

        friend Phase<Number> operator*(const Phase<Number>& left, const Phase<Number>& right) {
            return Phase<Number>(left.phase * right.phase);
        }

        friend Phase<Number> operator*(const Number& left, const Phase<Number>& right) {
            return Phase<Number>(left * right.phase);
        }

        friend Phase<Number> operator*(const Phase<Number>& left, const Number& right) {
            return Phase<Number>(left.phase * right);
        }

        friend Phase<Number> operator/(const Phase<Number>& left, const Phase<Number>& right) {
            return Phase<Number>(left.phase / right.phase);
        }

        friend Phase<Number> operator/(const Number& left, const Phase<Number>& right) {
            return Phase<Number>(left / right.phase);
        }

        friend Phase<Number> operator/(const Phase<Number>& left, const Number& right) {
            return Phase<Number>(left.phase / right);
        }

        friend bool operator==(const Phase<Number>& left, const Phase<Number>& right) {
            return left.phase == right.phase;
        }

        friend bool operator!=(const Phase<Number>& left, const Phase<Number>& right) {
            return !(left == right);
        }

        friend bool operator<(const Phase<Number>& left, const Phase<Number>& right) {
            return left.phase < right.phase;
        }

        friend bool operator<=(const Phase<Number>& left, const Phase<Number>& right) {
            return left.phase <= right.phase;
        }

        friend bool operator>(const Phase<Number>& left, const Phase<Number>& right) {
            return left.phase > right.phase;
        }

        friend bool operator>=(const Phase<Number>& left, const Phase<Number>& right) {
            return left.phase >= right.phase;
        }

        Phase<Number> operator+() const {
            return *this;
        }

        Phase<Number> operator-() const {
            return Phase<Number>(-phase);
        }

        Phase<Number>& operator+=(const Phase<Number>& other) {
            phase += other.phase;
            return *this;
        }

        Phase<Number>& operator-=(const Phase<Number>& other) {
            phase -= other.phase;
            return *this;
        }

        Phase<Number>& operator*=(const Number& scalar) {
            phase *= scalar;
            return *this;
        }

        Phase<Number>& operator/=(const Number& scalar) {
            phase /= scalar;
            return *this;
        }

        Number sine() const {
            return phase.sine();
        }

        Number cosine() const {
            return phase.cosine();
        }

        Number tangent() const {
            return phase.tangent();
        }

        Complex<Number> toComplex() const {
            return Complex<Number>(phase.cosine(), phase.sine());
        }

        friend std::ostream& operator<<(std::ostream& output, const Phase<Number>& phaseObj) {
            output << phaseObj.phase;
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Phase<Number>& phaseObj) {
            input >> phaseObj.phase;
            return input;
        }
    };

    template<typename Number>
    Period<Number> Frequency<Number>::toPeriod() const {
        return Period<Number>(One<Number> / frequency);
    }

    template<typename Number>
    Omega<Number> Frequency<Number>::toOmega() const {
        return Omega<Number>(static_cast<Number>(2) * pi<Number> *frequency);
    }

    template<typename Number>
    Period<Number> Omega<Number>::toPeriod() const {
        return Period<Number>(static_cast<Number>(2) * pi<Number> / omega);
    }

    template<typename Number>
    Frequency<Number> Omega<Number>::toFrequency() const {
        return Frequency<Number>(omega / (static_cast<Number>(2) * pi<Number>));
    }

    template<typename Number>
    Frequency<Number> Period<Number>::toFrequency() const {
        return Frequency<Number>(One<Number> / period);
    }

    template<typename Number>
    Omega<Number> Period<Number>::toOmega() const {
        return Omega<Number>(static_cast<Number>(2) * pi<Number> / period);
    }

    template<typename Number>
    class Epicycle {
    private:
        Amplitude<Number> amplitude;
        Frequency<Number> frequency;
        Phase<Number> phase;
    public:
        Epicycle() : amplitude(), frequency(), phase() {}
        Epicycle(const Amplitude<Number>& initAmplitude, const Frequency<Number>& initFrequency, const Phase<Number>& initPhase)
            : amplitude(initAmplitude), frequency(initFrequency), phase(initPhase) {}

        Amplitude<Number> getAmplitude() const { return amplitude; }
        Frequency<Number> getFrequency() const { return frequency; }
        Phase<Number> getPhase() const { return phase; }

        Complex<Number> evaluate(Number time) const {
            Number angle = static_cast<Number>(2) * pi<Number> *frequency.getValue() * time + phase.getValue();
            return Complex<Number>(
                amplitude.getValue() * std::cos(static_cast<double>(angle)),
                amplitude.getValue() * std::sin(static_cast<double>(angle))
            );
        }

        friend Epicycle<Number> operator+(const Epicycle<Number>& first, const Epicycle<Number>& second) {
            return Epicycle<Number>(
                Amplitude<Number>(first.amplitude.getValue() + second.amplitude.getValue()),
                Frequency<Number>(first.frequency.getValue() + second.frequency.getValue()),
                Phase<Number>(first.phase.getValue() + second.phase.getValue())
            );
        }

        friend std::ostream& operator<<(std::ostream& output, const Epicycle<Number>& epicycle) {
            output << "Epicycle(A=" << epicycle.amplitude
                << ", f=" << epicycle.frequency
                << ", phase=" << epicycle.phase << ")";
            return output;
        }
    };

    template<typename Number>
    class Ellipse {
    private:
        Number semiMajor;
        Number semiMinor;
        Angle<Number, -pi<Number>, pi<Number>> rotation;
    public:
        Ellipse() : semiMajor(Zero<Number>), semiMinor(Zero<Number>), rotation() {}
        Ellipse(Number majorAxis, Number minorAxis, const Angle<Number, -pi<Number>, pi<Number>>& rotationAngle)
            : semiMajor(majorAxis), semiMinor(minorAxis), rotation(rotationAngle) {}

        Number getSemiMajor() const { return semiMajor; }
        Number getSemiMinor() const { return semiMinor; }
        Angle<Number, -pi<Number>, pi<Number>> getRotation() const { return rotation; }

        Number eccentricity() const {
            return std::sqrt(static_cast<double>(
                static_cast<Number>(1) - (semiMinor * semiMinor) / (semiMajor * semiMajor)
                ));
        }

        Complex<Number> evaluate(Number angle) const {
            Number x = semiMajor * std::cos(static_cast<double>(angle));
            Number y = semiMinor * std::sin(static_cast<double>(angle));
            Complex<Number> point(x, y);
            return point * Complex<Number>(rotation.cosine(), rotation.sine());
        }

        friend std::ostream& operator<<(std::ostream& output, const Ellipse<Number>& ellipse) {
            output << "Ellipse(a=" << ellipse.semiMajor
                << ", b=" << ellipse.semiMinor
                << ", rotation=" << ellipse.rotation << ")";
            return output;
        }
    };

    template<typename Number>
    class Rotation {
    private:
        std::deque<Epicycle<Number>> epicycles;
    public:
        Rotation() {}

        Rotation(const std::deque<Epicycle<Number>>& cycles) : epicycles(cycles) {}

        Rotation(const std::initializer_list<Epicycle<Number>>& cycles) : epicycles(cycles) {}

        Rotation(const Rotation& other) : epicycles(other.epicycles) {}

        ~Rotation() {}

        Rotation<Number>& operator=(const Rotation<Number>& other) {
            epicycles = other.epicycles;
            return *this;
        }

        const std::deque<Epicycle<Number>>& getEpicycles() const {
            return epicycles;
        }

        void addEpicycle(const Epicycle<Number>& epicycle) {
            epicycles.push_back(epicycle);
        }

        void removeLastEpicycle() {
            if (!epicycles.empty()) {
                epicycles.pop_back();
            }
        }

        size_t getCount() const {
            return epicycles.size();
        }

        Complex<Number> evaluate(Number time) const {
            Complex<Number> position(Zero<Number>, Zero<Number>);
            for (const auto& epicycle : epicycles) {
                position = position + epicycle.evaluate(time);
            }
            return position;
        }

        Rotation<Number> convolve(const Rotation<Number>& other) const {
            std::deque<Epicycle<Number>> result;

            for (const auto& selfEpicycle : epicycles) {
                for (const auto& otherEpicycle : other.epicycles) {
                    Number selfAmplitude = selfEpicycle.getAmplitude().getValue();
                    Number otherAmplitude = otherEpicycle.getAmplitude().getValue();
                    Number selfFrequency = selfEpicycle.getFrequency().getValue();
                    Number otherFrequency = otherEpicycle.getFrequency().getValue();
                    Angle<Number, -pi<Number>, pi<Number>> selfPhase(selfEpicycle.getPhase().getValue());
                    Angle<Number, -pi<Number>, pi<Number>> otherPhase(otherEpicycle.getPhase().getValue());

                    Number combinedFrequency = selfFrequency + otherFrequency;
                    Angle<Number, -pi<Number>, pi<Number>> combinedPhase = selfPhase + otherPhase;
                    Number combinedAmplitude = selfAmplitude * otherAmplitude;

                    result.push_back(Epicycle<Number>(
                        Amplitude<Number>(combinedAmplitude),
                        Frequency<Number>(combinedFrequency),
                        Phase<Number>(combinedPhase)
                    ));
                }
            }

            return Rotation<Number>(result);
        }

        Rotation<Number> convolve(const Rotation<Number>& other, const Number& ratio) const {
            std::deque<Epicycle<Number>> result;

            for (const auto& selfEpicycle : epicycles) {
                for (const auto& otherEpicycle : other.epicycles) {
                    Number selfAmplitude = selfEpicycle.getAmplitude().getValue();
                    Number otherAmplitude = otherEpicycle.getAmplitude().getValue();
                    Number selfFrequency = selfEpicycle.getFrequency().getValue();
                    Number otherFrequency = otherEpicycle.getFrequency().getValue();
                    Angle<Number, -pi<Number>, pi<Number>> selfPhase(selfEpicycle.getPhase().getValue());
                    Angle<Number, -pi<Number>, pi<Number>> otherPhase(otherEpicycle.getPhase().getValue());

                    Number combinedFrequency = selfFrequency + otherFrequency;
                    Angle<Number, -pi<Number>, pi<Number>> phaseDifference = selfPhase - otherPhase;
                    Number similarityWeight = phaseDifference.cosine(ratio);
                    Number combinedAmplitude = selfAmplitude * otherAmplitude * similarityWeight;
                    Angle<Number, -pi<Number>, pi<Number>> combinedPhase = selfPhase + otherPhase;

                    result.push_back(Epicycle<Number>(
                        Amplitude<Number>(combinedAmplitude),
                        Frequency<Number>(combinedFrequency),
                        Phase<Number>(combinedPhase)
                    ));
                }
            }

            return Rotation<Number>(result);
        }

        Complex<Number> evaluateEpicycle(size_t index, Number time) const {
            if (index >= epicycles.size()) {
                throw std::out_of_range("Epicycle index out of range");
            }
            return epicycles[index].evaluate(time);
        }

        Complex<Number> evaluatePartial(size_t count, Number time) const {
            if (count > epicycles.size()) {
                count = epicycles.size();
            }
            Complex<Number> position(Zero<Number>, Zero<Number>);
            for (size_t i = 0; i < count; ++i) {
                position = position + epicycles[i].evaluate(time);
            }
            return position;
        }

        friend Rotation<Number> operator+(const Rotation<Number>& left, const Rotation<Number>& right) {
            std::deque<Epicycle<Number>> combined = left.epicycles;
            for (const auto& epicycle : right.epicycles) {
                combined.push_back(epicycle);
            }
            return Rotation<Number>(combined);
        }

        Rotation<Number>& operator+=(const Rotation<Number>& other) {
            for (const auto& epicycle : other.epicycles) {
                epicycles.push_back(epicycle);
            }
            return *this;
        }

        friend bool operator==(const Rotation<Number>& left, const Rotation<Number>& right) {
            return left.epicycles == right.epicycles;
        }

        friend bool operator!=(const Rotation<Number>& left, const Rotation<Number>& right) {
            return !(left == right);
        }

        Epicycle<Number>& operator[](size_t index) {
            return epicycles[index];
        }

        const Epicycle<Number>& operator[](size_t index) const {
            return epicycles[index];
        }

        friend std::ostream& operator<<(std::ostream& output, const Rotation<Number>& rotation) {
            output << "Rotation(epicycles=" << rotation.epicycles.size() << ")";
            return output;
        }
    };

    template<typename Number>
    class Spectral {
    private:
        Frequency<Number> frequency;
        Amplitude<Number> amplitude;
        Phase<Number> phase;
    public:
        Spectral() : frequency(), amplitude(), phase() {}
        Spectral(const Frequency<Number>& initFrequency, const Amplitude<Number>& initAmplitude, const Phase<Number>& initPhase)
            : frequency(initFrequency), amplitude(initAmplitude), phase(initPhase) {}

        Frequency<Number> getFrequency() const {
            return frequency;
        }

        Amplitude<Number> getAmplitude() const {
            return amplitude;
        }

        Phase<Number> getPhase() const {
            return phase;
        }

        Complex<Number> evaluate(Number time) const {
            Number angle = static_cast<Number>(2) * pi<Number> *frequency.getValue() * time + phase.getValue();
            return Complex<Number>(
                amplitude.getValue() * std::cos(static_cast<double>(angle)),
                amplitude.getValue() * std::sin(static_cast<double>(angle))
            );
        }

        Epicycle<Number> toEpicycle() const {
            return Epicycle<Number>(amplitude, frequency, phase);
        }

        friend bool operator==(const Spectral<Number>& left, const Spectral<Number>& right) {
            return left.frequency == right.frequency &&
                left.amplitude == right.amplitude &&
                left.phase == right.phase;
        }

        friend bool operator!=(const Spectral<Number>& left, const Spectral<Number>& right) {
            return !(left == right);
        }

        friend bool operator<(const Spectral<Number>& left, const Spectral<Number>& right) {
            return left.frequency < right.frequency;
        }

        friend bool operator<=(const Spectral<Number>& left, const Spectral<Number>& right) {
            return left.frequency <= right.frequency;
        }

        friend bool operator>(const Spectral<Number>& left, const Spectral<Number>& right) {
            return left.frequency > right.frequency;
        }

        friend bool operator>=(const Spectral<Number>& left, const Spectral<Number>& right) {
            return left.frequency >= right.frequency;
        }

        friend std::ostream& operator<<(std::ostream& output, const Spectral<Number>& spectral) {
            output << "(" << spectral.frequency << ", " << spectral.amplitude << ", " << spectral.phase << ")";
            return output;
        }
    };

    template<typename Number>
    class Spectrum {
    private:
        std::deque<Spectral<Number>> components;
    public:
        Spectrum() {}

        Spectrum(const std::deque<Spectral<Number>>& initComponents) : components(initComponents) {}

        Spectrum(const Rotation<Number>& rotation);

        Spectrum(const Waveform<Number>& waveform);

        Spectrum(const Spectrum& other) : components(other.components) {}

        ~Spectrum() {}

        Spectrum<Number>& operator=(const Spectrum<Number>& other) {
            components = other.components;
            return *this;
        }

        size_t size() const {
            return components.size();
        }

        Spectral<Number>& operator[](size_t index) {
            return components[index];
        }

        const Spectral<Number>& operator[](size_t index) const {
            return components[index];
        }

        const std::deque<Spectral<Number>>& getComponents() const {
            return components;
        }

        Rotation<Number> toRotation() const;

        Waveform<Number> reconstruct(Number duration, Number timeStep) const;

        Spectrum<Number> top(size_t count) const {
            std::deque<Spectral<Number>> sorted = components;
            std::sort(sorted.begin(), sorted.end(),
                [](const Spectral<Number>& left, const Spectral<Number>& right) {
                    return left.getAmplitude().getValue() > right.getAmplitude().getValue();
                });
            std::deque<Spectral<Number>> topComponents(sorted.begin(), sorted.begin() + std::min(count, sorted.size()));
            return Spectrum<Number>(topComponents);
        }

        Spectrum<Number> bandpass(const Frequency<Number>& low, const Frequency<Number>& high) const {
            std::deque<Spectral<Number>> filtered;
            for (const auto& component : components) {
                if (component.getFrequency().getValue() >= low.getValue() &&
                    component.getFrequency().getValue() <= high.getValue()) {
                    filtered.push_back(component);
                }
            }
            return Spectrum<Number>(filtered);
        }

        Spectrum<Number> lowpass(const Frequency<Number>& cutoff) const {
            return bandpass(Frequency<Number>(Zero<Number>), cutoff);
        }

        Spectrum<Number> highpass(const Frequency<Number>& cutoff) const {
            std::deque<Spectral<Number>> filtered;
            for (const auto& component : components) {
                if (component.getFrequency().getValue() >= cutoff.getValue()) {
                    filtered.push_back(component);
                }
            }
            return Spectrum<Number>(filtered);
        }

        Number totalEnergy() const {
            Number energy = Zero<Number>;
            for (const auto& component : components) {
                Number amp = component.getAmplitude().getValue();
                energy = energy + amp * amp;
            }
            return energy;
        }

        friend Spectrum<Number> operator+(const Spectrum<Number>& left, const Spectrum<Number>& right) {
            std::deque<Spectral<Number>> combined = left.components;
            for (const auto& component : right.components) {
                combined.push_back(component);
            }
            return Spectrum<Number>(combined);
        }

        Spectrum<Number>& operator+=(const Spectrum<Number>& other) {
            for (const auto& component : other.components) {
                components.push_back(component);
            }
            return *this;
        }

        friend bool operator==(const Spectrum<Number>& left, const Spectrum<Number>& right) {
            return left.components == right.components;
        }

        friend bool operator!=(const Spectrum<Number>& left, const Spectrum<Number>& right) {
            return !(left == right);
        }

        friend std::ostream& operator<<(std::ostream& output, const Spectrum<Number>& spectrum) {
            output << "Spectrum(components=" << spectrum.components.size() << ")";
            for (const auto& component : spectrum.components) {
                output << "\n  " << component;
            }
            return output;
        }
    };

    template<typename Number>
    class Waveform {
    private:
        std::deque<Complex<Number>> samples;
        Number timeStep;
    public:
        Waveform() : timeStep(One<Number>) {}

        Waveform(const Rotation<Number>& rotation, Number duration, Number step);

        Waveform(const std::deque<Complex<Number>>& data, Number step) : samples(data), timeStep(step) {}

        Waveform(const Waveform& other) : samples(other.samples), timeStep(other.timeStep) {}

        ~Waveform() {}

        Waveform<Number>& operator=(const Waveform<Number>& other) {
            samples = other.samples;
            timeStep = other.timeStep;
            return *this;
        }

        size_t size() const {
            return samples.size();
        }

        Number getTimeStep() const {
            return timeStep;
        }

        Complex<Number>& operator[](size_t index) {
            return samples[index];
        }

        const Complex<Number>& operator[](size_t index) const {
            return samples[index];
        }

        const std::deque<Complex<Number>>& getSamples() const {
            return samples;
        }

        Spectrum<Number> discreteFourierTransform() const;

        Spectrum<Number> fastFourierTransform() const;

        Spectrum<Number> radix2() const;

        Spectrum<Number> radix3() const;

        Spectrum<Number> radix5() const;

        Spectrum<Number> radix7() const;

        Spectrum<Number> bluestein() const;

        Spectrum<Number> mellinTransform() const;

        Spectrum<Number> waveletTransform() const;

        Spectrum<Number> laplacianTransform() const;

        Waveform<Number> window(const std::function<Number(Number)>& windowFunction) const {
            std::deque<Complex<Number>> windowed;
            for (size_t i = 0; i < samples.size(); ++i) {
                Number weight = windowFunction(static_cast<Number>(i) * timeStep);
                windowed.push_back(samples[i] * weight);
            }
            return Waveform<Number>(windowed, timeStep);
        }

        Waveform<Number> convolve(const Waveform<Number>& other) const {
            std::deque<Complex<Number>> result;
            for (size_t i = 0; i < samples.size() + other.samples.size() - 1; ++i) {
                Complex<Number> sum(Zero<Number>, Zero<Number>);
                for (size_t j = 0; j <= i && j < other.samples.size(); ++j) {
                    size_t k = i - j;
                    if (k < samples.size()) {
                        sum = sum + samples[k] * other.samples[j];
                    }
                }
                result.push_back(sum);
            }
            return Waveform<Number>(result, timeStep);
        }

        friend bool operator==(const Waveform<Number>& left, const Waveform<Number>& right) {
            return left.samples == right.samples && left.timeStep == right.timeStep;
        }

        friend bool operator!=(const Waveform<Number>& left, const Waveform<Number>& right) {
            return !(left == right);
        }

        friend std::ostream& operator<<(std::ostream& output, const Waveform<Number>& waveform) {
            output << "Waveform(samples=" << waveform.samples.size() << ", step=" << waveform.timeStep << ")";
            return output;
        }
    };

    template<typename Number>
    Waveform<Number>::Waveform(const Rotation<Number>& rotation, Number duration, Number step) : timeStep(step) {
        for (Number t = Zero<Number>; t < duration; t += step) {
            samples.push_back(rotation.evaluate(t));
        }
    }

    template<typename Number>
    Spectrum<Number>::Spectrum(const Rotation<Number>& rotation) {
        for (const auto& epicycle : rotation.getEpicycles()) {
            components.push_back(Spectral<Number>(
                epicycle.getFrequency(),
                epicycle.getAmplitude(),
                epicycle.getPhase()
            ));
        }
    }

    template<typename Number>
    Spectrum<Number>::Spectrum(const Waveform<Number>& waveform) {
        size_t sampleCount = waveform.size();
        Number timeStep = waveform.getTimeStep();
        for (size_t k = 0; k < sampleCount / 2 + 1; ++k) {
            Complex<Number> sum(Zero<Number>, Zero<Number>);
            for (size_t n = 0; n < sampleCount; ++n) {
                Number angle = -static_cast<Number>(2) * pi<Number> *static_cast<Number>(k) * static_cast<Number>(n) / static_cast<Number>(sampleCount);
                sum = sum + waveform[n] * Complex<Number>(std::cos(static_cast<double>(angle)), std::sin(static_cast<double>(angle)));
            }
            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = sum.magnitude() / static_cast<Number>(sampleCount);
            if (k > 0 && k < sampleCount / 2) {
                amp = amp * static_cast<Number>(2);
            }
            Number phase = std::atan2(static_cast<double>(sum.getImaginary()), static_cast<double>(sum.getReal()));
            components.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }
    }

    template<typename Number>
    Rotation<Number> Spectrum<Number>::toRotation() const {
        std::deque<Epicycle<Number>> epicycles;
        for (const auto& component : components) {
            epicycles.push_back(component.toEpicycle());
        }
        return Rotation<Number>(epicycles);
    }

    template<typename Number>
    Waveform<Number> Spectrum<Number>::reconstruct(Number duration, Number timeStep) const {
        Rotation<Number> rotation = toRotation();
        return Waveform<Number>(rotation, duration, timeStep);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::discreteFourierTransform() const {
        size_t sampleCount = samples.size();
        std::deque<Spectral<Number>> result;
        for (size_t k = 0; k < sampleCount; ++k) {
            Complex<Number> sum(Zero<Number>, Zero<Number>);
            for (size_t n = 0; n < sampleCount; ++n) {
                Number angle = -static_cast<Number>(2) * pi<Number> *static_cast<Number>(k) * static_cast<Number>(n) / static_cast<Number>(sampleCount);
                Complex<Number> twiddle(std::cos(static_cast<double>(angle)), std::sin(static_cast<double>(angle)));
                sum = sum + samples[n] * twiddle;
            }
            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = sum.magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(sum.getImaginary()), static_cast<double>(sum.getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }
        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::fastFourierTransform() const {
        return radix2();
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::radix2() const {
        size_t sampleCount = samples.size();
        if ((sampleCount & (sampleCount - 1)) != 0) {
            return discreteFourierTransform();
        }

        std::deque<Complex<Number>> data = samples;
        for (size_t i = 0, j = 0; i < sampleCount; ++i) {
            if (i < j) {
                Complex<Number> temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            size_t bit = sampleCount >> 1;
            for (; j & bit; bit >>= 1) {
                j ^= bit;
            }
            j ^= bit;
        }

        for (size_t length = 2; length <= sampleCount; length <<= 1) {
            Number angle = -static_cast<Number>(2) * pi<Number> / static_cast<Number>(length);
            Complex<Number> wlen(std::cos(static_cast<double>(angle)), std::sin(static_cast<double>(angle)));
            for (size_t i = 0; i < sampleCount; i += length) {
                Complex<Number> w(One<Number>, Zero<Number>);
                for (size_t j = 0; j < length / 2; ++j) {
                    Complex<Number> u = data[i + j];
                    Complex<Number> v = data[i + j + length / 2] * w;
                    data[i + j] = u + v;
                    data[i + j + length / 2] = u - v;
                    w = w * wlen;
                }
            }
        }

        std::deque<Spectral<Number>> result;
        for (size_t k = 0; k < sampleCount; ++k) {
            Number frequency = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amplitude = data[k].magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(data[k].getImaginary()), static_cast<double>(data[k].getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(frequency), Amplitude<Number>(amplitude), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }
        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::radix3() const {
        size_t sampleCount = samples.size();
        size_t power = 0;
        size_t temp = sampleCount;
        while (temp % 3 == 0) {
            temp /= 3;
            power++;
        }
        if (temp != 1) {
            return discreteFourierTransform();
        }

        std::deque<Complex<Number>> data = samples;
        for (size_t length = 3; length <= sampleCount; length *= 3) {
            size_t subLength = length / 3;
            Number angle = -static_cast<Number>(2) * pi<Number> / static_cast<Number>(length);
            Complex<Number> omega(std::cos(static_cast<double>(angle)), std::sin(static_cast<double>(angle)));
            Complex<Number> omega2 = omega * omega;

            for (size_t i = 0; i < sampleCount; i += length) {
                for (size_t j = 0; j < subLength; ++j) {
                    Complex<Number> t0 = data[i + j];
                    Complex<Number> t1 = data[i + j + subLength];
                    Complex<Number> t2 = data[i + j + 2 * subLength];

                    Complex<Number> w1(std::cos(static_cast<double>(static_cast<Number>(j) * static_cast<Number>(2) * pi<Number> / static_cast<Number>(length))),
                        std::sin(static_cast<double>(static_cast<Number>(j) * static_cast<Number>(2) * pi<Number> / static_cast<Number>(length))));
                    Complex<Number> w2 = w1 * w1;

                    data[i + j] = t0 + t1 + t2;
                    data[i + j + subLength] = t0 + t1 * omega + t2 * omega2;
                    data[i + j + 2 * subLength] = t0 + t1 * omega2 + t2 * omega;
                }
            }
        }

        std::deque<Spectral<Number>> result;
        for (size_t k = 0; k < sampleCount; ++k) {
            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = data[k].magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(data[k].getImaginary()), static_cast<double>(data[k].getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }
        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::radix5() const {
        size_t sampleCount = samples.size();
        size_t power = 0;
        size_t temp = sampleCount;
        while (temp % 5 == 0) {
            temp /= 5;
            power++;
        }
        if (temp != 1) {
            return discreteFourierTransform();
        }

        std::deque<Complex<Number>> data = samples;
        for (size_t length = 5; length <= sampleCount; length *= 5) {
            size_t subLength = length / 5;
            Number angle = -static_cast<Number>(2) * pi<Number> / static_cast<Number>(length);

            for (size_t i = 0; i < sampleCount; i += length) {
                for (size_t j = 0; j < subLength; ++j) {
                    Complex<Number> t[5];
                    for (size_t m = 0; m < 5; ++m) {
                        t[m] = data[i + j + m * subLength];
                    }

                    Number baseAngle = static_cast<Number>(2) * pi<Number> / static_cast<Number>(5);
                    Complex<Number> omega1(std::cos(static_cast<double>(baseAngle)), std::sin(static_cast<double>(baseAngle)));
                    Complex<Number> omega2 = omega1 * omega1;
                    Complex<Number> omega3 = omega2 * omega1;
                    Complex<Number> omega4 = omega3 * omega1;

                    data[i + j] = t[0] + t[1] + t[2] + t[3] + t[4];
                    data[i + j + subLength] = t[0] + t[1] * omega1 + t[2] * omega2 + t[3] * omega3 + t[4] * omega4;
                    data[i + j + 2 * subLength] = t[0] + t[1] * omega2 + t[2] * omega4 + t[3] * omega1 + t[4] * omega3;
                    data[i + j + 3 * subLength] = t[0] + t[1] * omega3 + t[2] * omega1 + t[3] * omega4 + t[4] * omega2;
                    data[i + j + 4 * subLength] = t[0] + t[1] * omega4 + t[2] * omega3 + t[3] * omega2 + t[4] * omega1;
                }
            }
        }

        std::deque<Spectral<Number>> result;
        for (size_t k = 0; k < sampleCount; ++k) {
            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = data[k].magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(data[k].getImaginary()), static_cast<double>(data[k].getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }
        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::radix7() const {
        size_t sampleCount = samples.size();
        size_t power = 0;
        size_t temp = sampleCount;
        while (temp % 7 == 0) {
            temp /= 7;
            power++;
        }
        if (temp != 1) {
            return discreteFourierTransform();
        }

        std::deque<Complex<Number>> data = samples;
        for (size_t length = 7; length <= sampleCount; length *= 7) {
            size_t subLength = length / 7;

            for (size_t i = 0; i < sampleCount; i += length) {
                for (size_t j = 0; j < subLength; ++j) {
                    Complex<Number> t[7];
                    for (size_t m = 0; m < 7; ++m) {
                        t[m] = data[i + j + m * subLength];
                    }

                    Number baseAngle = static_cast<Number>(2) * pi<Number> / static_cast<Number>(7);
                    Complex<Number> omega1(std::cos(static_cast<double>(baseAngle)), std::sin(static_cast<double>(baseAngle)));
                    Complex<Number> omega2 = omega1 * omega1;
                    Complex<Number> omega3 = omega2 * omega1;
                    Complex<Number> omega4 = omega3 * omega1;
                    Complex<Number> omega5 = omega4 * omega1;
                    Complex<Number> omega6 = omega5 * omega1;

                    data[i + j] = t[0] + t[1] + t[2] + t[3] + t[4] + t[5] + t[6];
                    data[i + j + subLength] = t[0] + t[1] * omega1 + t[2] * omega2 + t[3] * omega3 + t[4] * omega4 + t[5] * omega5 + t[6] * omega6;
                    data[i + j + 2 * subLength] = t[0] + t[1] * omega2 + t[2] * omega4 + t[3] * omega6 + t[4] * omega1 + t[5] * omega3 + t[6] * omega5;
                    data[i + j + 3 * subLength] = t[0] + t[1] * omega3 + t[2] * omega6 + t[3] * omega2 + t[4] * omega5 + t[5] * omega1 + t[6] * omega4;
                    data[i + j + 4 * subLength] = t[0] + t[1] * omega4 + t[2] * omega1 + t[3] * omega5 + t[4] * omega2 + t[5] * omega6 + t[6] * omega3;
                    data[i + j + 5 * subLength] = t[0] + t[1] * omega5 + t[2] * omega3 + t[3] * omega1 + t[4] * omega6 + t[5] * omega4 + t[6] * omega2;
                    data[i + j + 6 * subLength] = t[0] + t[1] * omega6 + t[2] * omega5 + t[3] * omega4 + t[4] * omega3 + t[5] * omega2 + t[6] * omega1;
                }
            }
        }

        std::deque<Spectral<Number>> result;
        for (size_t k = 0; k < sampleCount; ++k) {
            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = data[k].magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(data[k].getImaginary()), static_cast<double>(data[k].getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }
        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::bluestein() const {
        size_t sampleCount = samples.size();
        size_t M = 1;
        while (M < 2 * sampleCount - 1) {
            M <<= 1;
        }

        std::deque<Complex<Number>> sequenceA(M, Complex<Number>(Zero<Number>, Zero<Number>));
        std::deque<Complex<Number>> sequenceB(M, Complex<Number>(Zero<Number>, Zero<Number>));

        for (size_t n = 0; n < sampleCount; ++n) {
            Number angle = pi<Number> *static_cast<Number>(n * n) / static_cast<Number>(sampleCount);
            Complex<Number> chirp(std::cos(static_cast<double>(angle)), std::sin(static_cast<double>(angle)));
            sequenceA[n] = samples[n] * chirp;
        }

        for (size_t n = 0; n < 2 * sampleCount - 1; ++n) {
            size_t index = n < sampleCount ? n : 2 * sampleCount - 2 - n;
            Number angle = -pi<Number> *static_cast<Number>(index * index) / static_cast<Number>(sampleCount);
            Complex<Number> chirp(std::cos(static_cast<double>(angle)), std::sin(static_cast<double>(angle)));
            sequenceB[n] = chirp;
        }

        Waveform<Number> waveformA(sequenceA, One<Number>);
        Waveform<Number> waveformB(sequenceB, One<Number>);
        Waveform<Number> convolution = waveformA.convolve(waveformB);

        std::deque<Spectral<Number>> result;
        for (size_t k = 0; k < sampleCount; ++k) {
            Number angle = pi<Number> *static_cast<Number>(k * k) / static_cast<Number>(sampleCount);
            Complex<Number> chirp(std::cos(static_cast<double>(angle)), std::sin(static_cast<double>(angle)));
            Complex<Number> value = convolution[k] * chirp;
            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = value.magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(value.getImaginary()), static_cast<double>(value.getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }
        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::laplacianTransform() const {
        std::deque<Spectral<Number>> result;
        size_t sampleCount = samples.size();

        for (size_t k = 0; k < sampleCount; ++k) {
            Number sigma = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Complex<Number> sum(Zero<Number>, Zero<Number>);

            for (size_t n = 0; n < sampleCount; ++n) {
                Number t = static_cast<Number>(n) * timeStep;
                Number exponent = -sigma * t;
                Number decay = std::exp(static_cast<double>(exponent));
                Number angle = -static_cast<Number>(2) * pi<Number> *static_cast<Number>(k) * static_cast<Number>(n) / static_cast<Number>(sampleCount);
                Complex<Number> kernel(decay * std::cos(static_cast<double>(angle)), decay * std::sin(static_cast<double>(angle)));
                sum = sum + samples[n] * kernel;
            }

            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = sum.magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(sum.getImaginary()), static_cast<double>(sum.getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }

        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::mellinTransform() const {
        std::deque<Spectral<Number>> result;
        size_t sampleCount = samples.size();

        for (size_t k = 0; k < sampleCount; ++k) {
            Number s = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Complex<Number> sum(Zero<Number>, Zero<Number>);

            for (size_t n = 0; n < sampleCount; ++n) {
                Number x = static_cast<Number>(n + 1) * timeStep;
                if (x <= Zero<Number>) {
                    continue;
                }
                Number power = std::pow(static_cast<double>(x), static_cast<double>(s - One<Number>));
                sum = sum + samples[n] * Complex<Number>(power, Zero<Number>);
            }

            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = sum.magnitude() / static_cast<Number>(sampleCount);
            Number phase = std::atan2(static_cast<double>(sum.getImaginary()), static_cast<double>(sum.getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }

        return Spectrum<Number>(result);
    }

    template<typename Number>
    Spectrum<Number> Waveform<Number>::waveletTransform() const {
        std::deque<Spectral<Number>> result;
        size_t sampleCount = samples.size();

        for (size_t k = 0; k < sampleCount; ++k) {
            Number scale = static_cast<Number>(k + 1) * timeStep;
            Complex<Number> sum(Zero<Number>, Zero<Number>);

            for (size_t n = 0; n < sampleCount; ++n) {
                Number t = (static_cast<Number>(n) - static_cast<Number>(sampleCount) / static_cast<Number>(2)) * timeStep;
                Number argument = t / scale;
                Number mexicanHat = (One<Number> -argument * argument) * std::exp(static_cast<double>(-argument * argument / static_cast<Number>(2)));
                sum = sum + samples[n] * Complex<Number>(mexicanHat, Zero<Number>);
            }

            Number freq = static_cast<Number>(k) / (static_cast<Number>(sampleCount) * timeStep);
            Number amp = sum.magnitude() / std::sqrt(static_cast<double>(scale));
            Number phase = std::atan2(static_cast<double>(sum.getImaginary()), static_cast<double>(sum.getReal()));
            result.push_back(Spectral<Number>(Frequency<Number>(freq), Amplitude<Number>(amp), Phase<Number>(Angle<Number, -pi<Number>, pi<Number>>(phase))));
        }

        return Spectrum<Number>(result);
    }
};