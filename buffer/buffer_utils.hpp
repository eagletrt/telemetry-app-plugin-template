#pragma once

#include <cmath>

#include "buffer.hpp"

static double_buffer operator+(const double_buffer &lhs,
                               const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] += rhs[i];
  }
  return result;
}
static double_buffer operator-(const double_buffer &lhs,
                               const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] -= rhs[i];
  }
  return result;
}
static double_buffer operator*(const double_buffer &lhs,
                               const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] *= rhs[i];
  }
  return result;
}
static double_buffer operator/(const double_buffer &lhs,
                               const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] /= rhs[i];
  }
  return result;
}
// scalar operators
static double_buffer operator+(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] += rhs;
  }
  return result;
}
static double_buffer operator-(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] -= rhs;
  }
  return result;
}
static double_buffer operator*(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] *= rhs;
  }
  return result;
}
static double_buffer operator/(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] /= rhs;
  }
  return result;
}
// scalar operators
static double_buffer operator+(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] += lhs;
  }
  return result;
}
static double_buffer operator-(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] = lhs - rhs[i];
  }
  return result;
}
static double_buffer operator*(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] *= lhs;
  }
  return result;
}
static double_buffer operator/(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] = lhs / rhs[i];
  }
  return result;
}

static double mean(const double_buffer &buffer) {
  double sum = 0;
  for (size_t i = 0; i < buffer.size(); i++) {
    sum += buffer[i];
  }
  return sum / buffer.size();
}

static double sum(const double_buffer &buffer) {
  double sum = 0;
  for (size_t i = 0; i < buffer.size(); i++) {
    sum += buffer[i];
  }
  return sum;
}

static double weighted_sum(const double_buffer &buffer,
                           const double_buffer &weights) {
  double sum = 0;
  for (size_t i = 0; i < buffer.size(); i++) {
    sum += buffer[i] * weights[i];
  }
  return sum;
}

static double_buffer differentiate(const double_buffer &buffer,
                                   const double_buffer &timestamps) {
  double_buffer result = buffer;
  for (size_t i = 1; i < buffer.size(); i++) {
    result[i] =
        (buffer[i] - buffer[i - 1]) / (timestamps[i] - timestamps[i - 1]);
  }
  return result;
}

static double_buffer integrate(const double_buffer &buffer,
                               const double_buffer &timestamps) {
  double_buffer result = buffer;
  for (size_t i = 1; i < buffer.size(); i++) {
    result[i] = result[i - 1] + (buffer[i] + buffer[i - 1]) / 2.0 *
                                    (timestamps[i] - timestamps[i - 1]);
  }
  return result;
}

static double_buffer cumsum(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 1; i < buffer.size(); i++) {
    result[i] = result[i - 1] + buffer[i];
  }
  return result;
}

static double_buffer zeros(const double_buffer &timestamp_vector) {
  double_buffer result = timestamp_vector;
  for (size_t i = 0; i < timestamp_vector.size(); i++) {
    result[i] = 0.0;
  }
  return result;
}

static double_buffer ones(const double_buffer &timestamp_vector) {
  double_buffer result = timestamp_vector;
  for (size_t i = 0; i < timestamp_vector.size(); i++) {
    result[i] = 1.0;
  }
  return result;
}

static double_buffer operator==(const double_buffer &lhs,
                                const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] = lhs[i] == rhs[i];
  }
  return result;
}

namespace std {
static double_buffer abs(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::abs(buffer[i]);
  }
  return result;
}

static double_buffer sqrt(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::sqrt(buffer[i]);
  }
  return result;
}

static double_buffer exp(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::exp(buffer[i]);
  }
  return result;
}

static double_buffer log(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::log(buffer[i]);
  }
  return result;
}

static double_buffer log10(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::log10(buffer[i]);
  }
  return result;
}

static double_buffer pow(const double_buffer &buffer, const double &exponent) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::pow(buffer[i], exponent);
  }
  return result;
}

static double_buffer pow(const double &base, const double_buffer &exponent) {
  double_buffer result = exponent;
  for (size_t i = 0; i < exponent.size(); i++) {
    result[i] = std::pow(base, exponent[i]);
  }
  return result;
}

static double_buffer pow(const double_buffer &base,
                         const double_buffer &exponent) {
  double_buffer result = base;
  for (size_t i = 0; i < base.size(); i++) {
    result[i] = std::pow(base[i], exponent[i]);
  }
  return result;
}

static double_buffer sin(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::sin(buffer[i]);
  }
  return result;
}

static double_buffer cos(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::cos(buffer[i]);
  }
  return result;
}

static double_buffer tan(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::tan(buffer[i]);
  }
  return result;
}

static double_buffer asin(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::asin(buffer[i]);
  }
  return result;
}

static double_buffer acos(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::acos(buffer[i]);
  }
  return result;
}

static double_buffer atan(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::atan(buffer[i]);
  }
  return result;
}

static double_buffer atan2(const double_buffer &y, const double_buffer &x) {
  double_buffer result = x;
  for (size_t i = 0; i < y.size(); i++) {
    result[i] = std::atan2(y[i], x[i]);
  }
  return result;
}

static double_buffer sinh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::sinh(buffer[i]);
  }
  return result;
}

static double_buffer cosh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::cosh(buffer[i]);
  }
  return result;
}

static double_buffer tanh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::tanh(buffer[i]);
  }
  return result;
}

static double_buffer asinh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = asinh(buffer[i]);
  }
  return result;
}

static double_buffer acosh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = acosh(buffer[i]);
  }
  return result;
}

static double_buffer atanh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = atanh(buffer[i]);
  }
  return result;
}

static double_buffer ceil(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = ceil(buffer[i]);
  }
  return result;
}

static double_buffer floor(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = floor(buffer[i]);
  }
  return result;
}

static double_buffer round(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = round(buffer[i]);
  }
  return result;
}

static double_buffer trunc(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = trunc(buffer[i]);
  }
  return result;
}

};  // namespace std
