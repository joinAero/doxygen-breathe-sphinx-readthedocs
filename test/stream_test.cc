#include <iostream>
#include <vector>

#include "stream/stream.hpp"

int main(int argc, char const *argv[]) {
  {
    std::vector<int> values{1, 2, 3, 4};

    std::cout << "values: ";
    std::copy(values.begin(), values.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "accumulate: "
        << stream::accumulate(values.begin(), values.end())
        << std::endl;
    std::cout << "average: "
        << stream::average_float(values.begin(), values.end())
        << std::endl;
  }
  return 0;
}
