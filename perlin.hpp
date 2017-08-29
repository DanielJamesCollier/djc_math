#ifndef perlin_hpp 
#define perlin_hpp

// my
#include "common.hpp" // djc::math::lerp

// std
#include <type_traits> // std::is_floating_point
#include <vector> // std::vector
#include <numeric> // std::iota
#include <random> // std::default_random_engine 
#include <algorithm> // std::shuffle
#include <cmath>

namespace djc::math {

template<typename T>
class perlin final {
    static_assert(std::is_floating_point<T>::value, "T must be a float or a double");
public:
//                         RAII                             // 
//------------------------------------------------------------
    perlin() noexcept(false);
    explicit perlin(unsigned int seed) noexcept(false);

//                       functions                         // 
//------------------------------------------------------------
    T noise(T x, T y, T z) const noexcept;
     
//                         data                             // 
//------------------------------------------------------------
private:
    std::vector<T> m_permutation;
}; // perlin

} // namespace djc::math
#include "./inline/perlin.inl"
#endif // perlin_hpp
