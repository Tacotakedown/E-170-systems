#ifndef ARINC429_H
#define ARINC429_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <random>
#include <optional>
#include <cassert>

    enum class SignStatus : uint64_t {
        FailureWarning = 0b00,
        NoComputedData = 0b01,
        FunctionalTest = 0b10,
        NormalOperation = 0b11
    };

    template <typename T>
    class Arinc429Word {
    private:
        T value;
        SignStatus ssm;

    public:
        Arinc429Word(T value, SignStatus ssm);
        T getValue() const { return value; };
        std::optional<T> getNormalValue() const { return std::optional<T>; };
        SignStatus getSSM() const { return ssm; };
        bool isFailureWarning() const;
        bool isNoComputedData() const;
        bool isFunctionalTest() const;
        bool isNormalOperation() const;

    };

    template <>
    class Arinc429Word<uint32_t> {
    private:
        uint32_t value;
        SignStatus ssm;

    public:
        Arinc429Word(uint32_t value, SignStatus ssm);
        uint32_t getValue() const;
        void setBit(uint8_t bit, bool value);
        bool getBit(uint8_t bit) const;
        SignStatus getSSM() const { return ssm; };

    };

    Arinc429Word<uint32_t> double_to_arinc429(double simvar);
    double arinc429_to_double(const Arinc429Word<uint32_t>& word);
     
#endif // !ARINC429_H


