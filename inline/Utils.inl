namespace djc::math {

//------------------------------------------------------------
template<typename T> 
constexpr T 
to_radians(T degrees) {
    return (degrees * pi<T>) / T(180);
}

//------------------------------------------------------------
inline float 
rand_float_between_zero_one() {
    return (double)rand() / ((double)RAND_MAX + 1);
}

// @todo: remove this
//------------------------------------------------------------
inline unsigned char 
rand_UC_between_0_N_255() {
    return static_cast<unsigned char>(std::rand() % (255 + 1));
}

//------------------------------------------------------------
constexpr float
normalise(float valToNormalise, float min, float max) {
    return (valToNormalise - min) / (max - min);
}

//------------------------------------------------------------
template <typename T>
constexpr T
lerp(T v0, T v1, float t) {
    return (T(1) - t) * v0 + t * v1;
}

//------------------------------------------------------------
template <typename T>
constexpr T
lerp(T v0, T v1, double t) {
    return (T(1) - t) * v0 + t * v1;
}

//------------------------------------------------------------
template<typename T>
constexpr T 
clamp(T v, T low, T hi) {
    if(v < low) {
        return low;
    } else if(v > hi){
        return hi;
    }
    return v;
}

} // namespace djc::math 

