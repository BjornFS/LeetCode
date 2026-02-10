#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

namespace printer {

    // ---------- base case: printable scalar ----------
    template<typename T>
    void value(const T& x) {
        std::cout << x;
    }

    // ---------- vector ----------
    template<typename T>
    void vector(const std::vector<T>& v,
                const std::string& sep = " ",
                const std::string& end = "\n") {

        for (size_t i = 0; i < v.size(); ++i) {
            value(v[i]);
            if (i + 1 < v.size()) std::cout << sep;
        }
        std::cout << end;
    }

    // ---------- matrix (vector of vectors) ----------
    template<typename T>
    void matrix(const std::vector<std::vector<T>>& m,
                const std::string& sep = " ",
                const std::string& end = "\n") {

        for (const auto& row : m) {
            vector(row, sep, end);
        }
    }

    // ---------- labeled debug ----------
    template<typename T>
    void debug(const std::string& name, const T& x) {
        std::cout << name << " = ";
        value(x);
        std::cout << '\n';
    }

    template<typename T>
    void debug(const std::string& name, const std::vector<T>& v) {
        std::cout << name << " = ";
        vector(v);
    }

} // namespace print
