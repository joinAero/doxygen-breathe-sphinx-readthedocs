#pragma once

#include <algorithm>
#include <iterator>

namespace stream {

/**
 * Sum class to accumulate the values.
 */
template <typename T>
struct Sum {
  /**
   * Constructor.
   */
  Sum() : sum{Zero()} {}
  /**
   * Get the initial value.
   * @return The initial value.
   */
  T Zero() { return 0; }
  /**
   * Call operator to accumulate a value.
   * @param n a value to be accumulated.
   */
  void operator()(T n) { sum += n; }

  T sum;  /**< The sum value. */
};

/**
 * Computes the sum of the given values.
 * @param first the range first.
 * @param last the range last.
 * @return The result.
 */
template <typename It,
          typename Result = typename std::iterator_traits<It>::value_type>
Result accumulate(It first, It last) {
  using value_type = typename std::iterator_traits<It>::value_type;
  return std::for_each(first, last, Sum<value_type>()).sum;
}

/**
 * Computes the average of the given values.
 * @param first the range first.
 * @param last the range last.
 * @return The result.
 */
template <typename It,
          typename Result = typename std::iterator_traits<It>::value_type>
Result average(It first, It last) {
  typename std::iterator_traits<It>::difference_type n =
      std::distance(first, last);
  Result result = 1;
  return result * accumulate(first, last) / n;
}

/**
 * Computes the average(float) of the given values.
 * @param first the range first.
 * @param last the range last.
 * @return The float result.
 */
template <typename It>
float average_float(It first, It last) {
  return average<It, float>(first, last);
}

}  // namespace stream
