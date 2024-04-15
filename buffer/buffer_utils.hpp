#pragma once

#include <cmath>

#include "buffer.hpp"

double_buffer operator+(const double_buffer &lhs, const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] += rhs[i];
  }
  return result;
}
double_buffer operator-(const double_buffer &lhs, const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] -= rhs[i];
  }
  return result;
}
double_buffer operator*(const double_buffer &lhs, const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] *= rhs[i];
  }
  return result;
}
double_buffer operator/(const double_buffer &lhs, const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] /= rhs[i];
  }
  return result;
}
// scalar operators
double_buffer operator+(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] += rhs;
  }
  return result;
}
double_buffer operator-(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] -= rhs;
  }
  return result;
}
double_buffer operator*(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] *= rhs;
  }
  return result;
}
double_buffer operator/(const double_buffer &lhs, const double &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] /= rhs;
  }
  return result;
}
// scalar operators
double_buffer operator+(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] += lhs;
  }
  return result;
}
double_buffer operator-(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] -= lhs;
  }
  return result;
}
double_buffer operator*(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] *= lhs;
  }
  return result;
}
double_buffer operator/(const double &lhs, const double_buffer &rhs) {
  double_buffer result = rhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] /= lhs;
  }
  return result;
}

double mean(const double_buffer &buffer) {
  double sum = 0;
  for (size_t i = 0; i < buffer.size(); i++) {
    sum += buffer[i];
  }
  return sum / buffer.size();
}

double sum(const double_buffer &buffer) {
  double sum = 0;
  for (size_t i = 0; i < buffer.size(); i++) {
    sum += buffer[i];
  }
  return sum;
}

double_buffer zeros(size_t size = CANLIB_CIRCULAR_BUFFER_SIZE) {
  double_buffer result;
  for (size_t i = 0; i < size && i < CANLIB_CIRCULAR_BUFFER_SIZE; ++i) {
    result.push(0.0);
  }
  return result;
}

double_buffer ones(size_t size = CANLIB_CIRCULAR_BUFFER_SIZE) {
  double_buffer result;
  for (size_t i = 0; i < size && i < CANLIB_CIRCULAR_BUFFER_SIZE; ++i) {
    result.push(1.0);
  }
  return result;
}

double_buffer operator==(const double_buffer &lhs, const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < rhs.size(); i++) {
    result[i] = lhs[i] == rhs[i];
  }
  return result;
}

namespace std {
double_buffer abs(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::abs(buffer[i]);
  }
  return result;
}

double_buffer sqrt(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::sqrt(buffer[i]);
  }
  return result;
}

double_buffer exp(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::exp(buffer[i]);
  }
  return result;
}

double_buffer log(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::log(buffer[i]);
  }
  return result;
}

double_buffer log10(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::log10(buffer[i]);
  }
  return result;
}

double_buffer pow(const double_buffer &buffer, const double &exponent) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::pow(buffer[i], exponent);
  }
  return result;
}

double_buffer pow(const double &base, const double_buffer &exponent) {
  double_buffer result = exponent;
  for (size_t i = 0; i < exponent.size(); i++) {
    result[i] = std::pow(base, exponent[i]);
  }
  return result;
}

double_buffer pow(const double_buffer &base, const double_buffer &exponent) {
  double_buffer result = base;
  for (size_t i = 0; i < base.size(); i++) {
    result[i] = std::pow(base[i], exponent[i]);
  }
  return result;
}

double_buffer sin(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::sin(buffer[i]);
  }
  return result;
}

double_buffer cos(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::cos(buffer[i]);
  }
  return result;
}

double_buffer tan(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::tan(buffer[i]);
  }
  return result;
}

double_buffer asin(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::asin(buffer[i]);
  }
  return result;
}

double_buffer acos(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::acos(buffer[i]);
  }
  return result;
}

double_buffer atan(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::atan(buffer[i]);
  }
  return result;
}

double_buffer atan2(const double_buffer &lhs, const double_buffer &rhs) {
  double_buffer result = lhs;
  for (size_t i = 0; i < lhs.size(); i++) {
    result[i] = std::atan2(lhs[i], rhs[i]);
  }
  return result;
}

double_buffer sinh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::sinh(buffer[i]);
  }
  return result;
}

double_buffer cosh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::cosh(buffer[i]);
  }
  return result;
}

double_buffer tanh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = std::tanh(buffer[i]);
  }
  return result;
}

double_buffer asinh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = asinh(buffer[i]);
  }
  return result;
}

double_buffer acosh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = acosh(buffer[i]);
  }
  return result;
}

double_buffer atanh(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = atanh(buffer[i]);
  }
  return result;
}

double_buffer ceil(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = ceil(buffer[i]);
  }
  return result;
}

double_buffer floor(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = floor(buffer[i]);
  }
  return result;
}

double_buffer round(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = round(buffer[i]);
  }
  return result;
}

double_buffer trunc(const double_buffer &buffer) {
  double_buffer result = buffer;
  for (size_t i = 0; i < buffer.size(); i++) {
    result[i] = trunc(buffer[i]);
  }
  return result;
}

}; // namespace std
