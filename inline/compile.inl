namespace djc::math::compile {

//------------------------------------------------------------
template <typename T>
constexpr T constexpr_power(T const& x, std::size_t n) {
    return n > 0 ? x * constexpr_power(x, n - 1) : 1;
}

//------------------------------------------------------------
template<typename T>
constexpr T constexpr_factoral(T x) {
    if (x == 1) {
        return 1;
    }
    return x * constexpr_factoral(x-1);
}

//------------------------------------------------------------
constexpr double
constexpr_sqrt(double x) {
    struct {
        constexpr double operator() (double x, double current, double previous) {
            return current == previous ? current : (*this)(x, 0.5 * (current + x / current), current);
        }
    } sqrtNewtonRaphson{};
    
    return x >= 0 && x < std::numeric_limits<double>::infinity()
    ? sqrtNewtonRaphson(x, x, 0)
    : std::numeric_limits<double>::quiet_NaN();
}
    
// internal sin implementation
namespace internal::sin {
    //-------------------------------------
    template<std::size_t INDEX, std::size_t LENGTH>
    struct sin_solver {
        constexpr double operator () (double x) {
            return sin_solver<INDEX + 1, LENGTH>{}(x) + (constexpr_power<double>(-1, INDEX)        *
                                                         constexpr_power<double>(x, 2 * INDEX + 1) /
                                                         constexpr_factoral<double>(2 * INDEX + 1));
        }
    };
    
    //-------------------------------------
    template<std::size_t LENGTH>
    struct sin_solver<LENGTH, LENGTH> {
        constexpr double operator () (double x) {
            return 0;
        }
    };
}

//-------------------------------------
constexpr double
constexpr_sin(double x) {
    return internal::sin::sin_solver<0, 30>{}(x);
}

// internal cos implementation
namespace internal::cos {
    
}
    
} // namespace djc::math::compile
