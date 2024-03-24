#pragma once

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
