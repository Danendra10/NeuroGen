#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <NeuroGen/Lut/Trigonom.hpp>
#include <cmath>
#include <string>

/**
 * User-defined literals for activation functions
 */
namespace Literals {
    constexpr double Sigmoid(double _x) { return 1.0 / (1.0 + std::exp(-_x)); }
    constexpr double Relu(double _x) { return _x < 0.0 ? 0.0 : _x; }
    constexpr double LeakyRelu(double _x, double _alpha) {
        return _x < 0.0 ? _alpha * _x : _x;
    }
    constexpr double Linear(double _x) { return _x; }
    constexpr double FastTanh(double _x) {
        int index = static_cast<int>((_x + 26.0) / 0.01);  // 0.01 is the step and 26 is the range
        return tanh_lut[index];
    }
    constexpr double Tanh(double _x) { return tanh(_x); }
    constexpr double Softmax(double _x) { return 1.0 / (1.0 + std::exp(-_x)); }
    constexpr double Softplus(double _x) { return std::log(1.0 + std::exp(_x)); }
    constexpr double Swish(double _x) {
        return _x / (1.0 + std::exp(-_x));
    }

    /**
     * @brief Sigmoid activation function
     *  1 / (1 + exp(-_x))
     * @param _x
     * @return Sigmoid(_x)
     *
     * Example usage:
     * ```
     * double result = 2.5_SigmoidFunc;
     * ```
     */
    constexpr double operator"" _SigmoidFunc(long double x) {
        return Sigmoid(static_cast<double>(x));
    }
    /**
     * A user-defined literal operator for computing the rectified linear unit (ReLU) function.
     *
     * @param x the input value for the ReLU function
     *
     * @return the computed output value of the ReLU function
     *
     * @brief
     * ReLU activation function (Rectified Linear Unit)
     * Equation: max(0, _x)
     */
    constexpr double operator"" _ReluFunc(long double x) {
        return Relu(static_cast<double>(x));
    }

    /**
     * A user-defined literal operator for computing the Leaky ReLU function
     *
     * @param x the input value for the Leaky ReLU function
     *
     * @return the computed output value of the Leaky ReLU function
     *
     * @brief
     * Leaky ReLU activation function
     * Equation: max(_alpha * _x, _x)
     */
    constexpr double operator"" _LeakyReluFunc(long double x) {
        return LeakyRelu(static_cast<double>(x), 0.01);
    }

    /**
     * A user-defined literal operator for computing the Linear Activation Function
     *
     * @param x the input value for the Linear Activation Function
     *
     * @return the computed output value of the Linear Activation Function
     *
     * @brief
     * Leaky Linear activation function
     * Equation: y = x
     */
    constexpr double operator"" _LinearFunc(long double x) {
        return Linear(static_cast<double>(x));
    }

        constexpr double operator"" _FastTanhFunc(long double x) {
        return FastTanh(static_cast<double>(x));
    }

    constexpr double operator"" _TanhFunc(long double x) {
        return Tanh(static_cast<double>(x));
    }

    constexpr double operator"" _SoftmaxFunc(long double x) {
        return Softmax(static_cast<double>(x));
    }

    constexpr double operator"" _SoftplusFunc(long double x) {
        return Softplus(static_cast<double>(x));
    }

    constexpr double operator"" _SwishFunc(long double x) {
        return Swish(static_cast<double>(x));
    }
}  // namespace Literals

#endif