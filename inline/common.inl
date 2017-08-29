namespace djc::math {

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

// @todo: fix the floating point return floor functions

//------------------------------------------------------------
constexpr float
floor(float val) {
    int i = static_cast<int>(val); // truncate
    return static_cast<float>(i - (i > val)); // convert trunc to floor 
}

//------------------------------------------------------------
constexpr double
floor(double val) {
    int i = static_cast<int>(val); // truncate
    return static_cast<double>(i - (i > val)); // convert trunc to floor 
}

//------------------------------------------------------------
constexpr int 
floor_int(float val) {
    int i = static_cast<int>(val); // truncate
    return i - (i > val); // convert trunc to floor 
}

//------------------------------------------------------------
constexpr int 
floor_int(double val) {
    int i = static_cast<int>(val); // truncate
    return i - (i > val); // convert trunc to floor 
}

//------------------------------------------------------------
constexpr float 
to_radians(float degrees) {
    return (degrees * pi<float>) / 180.0f;
}

//------------------------------------------------------------
constexpr double 
to_radians(double degrees) {
    return (degrees * pi<double>) / 180.0;
}

//------------------------------------------------------------
constexpr float 
to_degrees(float radians) {
    return radians * (180.0f / pi<float>);
}

//------------------------------------------------------------
constexpr double 
to_degrees(double radians) {
    return radians * (180.0 / pi<double>);
}

} // namespace djc::math 
