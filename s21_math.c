#include "s21_math.h"

long double s21_fact(double x) {
  if (x <= 1) {
    return 1;
  } else {
    return x * s21_fact(x - 1);
  }
}

int s21_abs(int x) { return x > 0 ? x : -x; }

long double s21_fabs(double x) { return x > 0 ? x : -x; }

long double s21_floor(double x) {
  long double result = 0;
  if (!S21_ISINF(x) && !S21_ISNAN(x)) {
    result = x >= 0 ? (long long int)x : (long long int)(x - 1);
  } else {
    result = x;
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = 0;
  if (!S21_ISINF(x) && !S21_ISNAN(x)) {
    result = x > 0 ? (long long int)(x + 1) : (long long int)x;
  } else {
    result = x;
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (!S21_ISINF(x) && !S21_ISINF(y) && !S21_ISNAN(x) && !S21_ISNAN(y) &&
      y != 0.0) {
    result = x - (long long int)(x / y) * y;
  } else {
    result = S21_NAN;
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1, pow_x = 1, temp = 1;
  if (S21_ISINF(x)) {
    result = x == S21_INF_POS ? S21_INF_POS : 0;
  } else {
    for (int i = 1; s21_fabs(temp) > S21_EPS; i++) {
      pow_x *= x;
      temp = pow_x / s21_fact(i);
      result += temp;
    }
  }
  return result;
}

long double s21_log(double x) {
  long double result = 0, pow_x = 1, temp = 1;
  int sign = 1;
  if (x == S21_INF_POS) {
    result = S21_INF_POS;
  } else if (x <= 0) {
    result = x == 0 ? S21_INF_NEG : S21_NAN;
  } else {
    x = x > 0.5 ? x / (x - 1) : x - 1;
    for (int i = 1; s21_fabs(temp) > S21_EPS; i++) {
      pow_x *= x;
      temp = s21_fabs(x) >= 1 ? 1 / (i * pow_x) : (pow_x / i) * sign;
      result += temp;
      sign *= -1;
    }
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (exp == 0) {
    result = 1;
  } else if (base == 0 || base == 1 || exp == 1) {
    result = base;
  } else if (S21_ISNAN(base) || S21_ISNAN(exp)) {
    result = S21_NAN;
  } else if (S21_ISINF(exp)) {
    if (base == -1) {
      result = 1;
    } else if (s21_fabs(base) < 1) {
      result = exp == S21_INF_POS ? 0 : S21_INF_POS;
    } else {
      result = exp == S21_INF_POS ? S21_INF_POS : 0;
    }
  } else if (S21_ISINF(base)) {
    if (exp < 0) {
      result = 0;
    } else {
      result = s21_fmod(exp, 2) == 1 ? S21_INF_NEG : S21_INF_POS;
    }
  } else {
    result = s21_exp(s21_log(base) * exp);
  }
  return result;
}

long double s21_sqrt(double x) { return s21_pow(x, 0.5); }

long double s21_sin(double x) {
  long double result = 0, temp = 1, temp_x = 0;
  int sign = 1;
  temp_x = s21_fmod(s21_fabs(x), 2 * S21_PI);
  for (int i = 1; s21_fabs(temp) > S21_EPS; i += 2) {
    temp = s21_pow(temp_x, i) / s21_fact(i);
    result += temp * sign;
    sign *= -1;
  }
  return x >= 0 ? result : -result;
}

long double s21_cos(double x) {
  long double result = 1, temp = 1, temp_x = 0;
  int sign = -1;
  temp_x = s21_fmod(s21_fabs(x), 2 * S21_PI);
  for (int i = 2; s21_fabs(temp) > S21_EPS; i += 2) {
    temp = s21_pow(temp_x, i) / s21_fact(i);
    result += temp * sign;
    sign *= -1;
  }
  return result;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_atan(double x) {
  long double result = 0, temp = 0;
  int flag = s21_fabs(x) > 1;
  int neg_flag = x == S21_INF_NEG;
  if (s21_fabs(x) == 1) {
    result = x < 0 ? -(S21_PI / 4) : (S21_PI / 4);
  } else {
    x = flag ? 1 / x : x;
    result = (temp = x);
    for (int i = 1; s21_fabs(temp) > S21_EPS; i++) {
      temp *= -1 * (2 * i - 1) * x * x / (2 * i + 1);
      result += temp;
    }
    result = flag ? (S21_PI / 2 - result) : result;
    result = neg_flag ? -result : result;
  }
  return result;
}

long double s21_asin(double x) {
  long double result = x, temp = x;
  if (s21_fabs(x) > 1) {
    result = S21_NAN;
  } else if (s21_fabs(x) == 1) {
    result = x < 0 ? -(S21_PI / 2) : (S21_PI / 2);
  } else {
    for (int i = 1; s21_fabs(temp) > S21_EPS; i++) {
      temp *= (2 * i - 1) * (2 * i - 1) * x * x / (2 * i * (2 * i + 1));
      result += temp;
    }
  }
  return result;
}

long double s21_acos(double x) { return S21_PI / 2 - s21_asin(x); }