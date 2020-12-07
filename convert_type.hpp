#include <iostream>
#include <limits>
#include <cstddef>
template<typename T, typename U>
constexpr T convert_to(U v){
  unsigned long long int t2n = 1;
  t2n <<= sizeof(T)*8;
  // a - b = k*t2n
  auto min = std::numeric_limits<T>::min();
  auto max = std::numeric_limits<T>::max();
//   std::cout<<"[ "<<min<<", "<<max<<"]\n";
  for(std::size_t k = 0;k<200000;k++){
      T c0 = v - k * t2n;
      T c1 = v + k * t2n;
      if(c0>=min && c0<=max){
          return c0;
      }
      if(c1>=min && c1<=max){
          return c1;
      }
  }
  return 0;
}
