#include "djc_math.hpp"
#include <iostream>

using namespace djc::math;

//------------------------------------------------------------
void 
vec2_tests() {
    /* Runtime */
    // -----------------------------------
    
    // constructors
    //
        vec2f vec2_default;
        vec2f vec2_explicit(5, 4);
        vec2f vec2_copy(vec2_default);
    //

    // members
    {   
        auto len  = vec2_default.length();
        auto len2 = vec2_default.length2();
        
        vec2_default.normalise();
    
        auto dot  = vec2_default.dot(vec2_explicit);
    }

    // members - operator overloads
    {
        auto pos = +vec2_default;
        auto neg = -vec2_default;

        vec2_default += vec2_explicit;
        vec2_default -= vec2_explicit;
        vec2_default *= vec2_explicit;
        vec2_default /= vec2_explicit;

        vec2_default += 1.0f;
        vec2_default -= 1.0f;
        vec2_default *= 1.0f;
        vec2_default /= 1.0f;
    }
    
    // free functions - operator overloads
    {
        auto add = vec2_default + vec2_default;
        auto sub = vec2_default - vec2_default;
        auto mul = vec2_default * vec2_default;
        auto div = vec2_default / vec2_default;   
    
        auto addF = 1.0f + vec2_default;
        auto subF = 1.0f - vec2_default;
        auto mulF = 1.0f * vec2_default;
        auto divF = 1.0f / vec2_default;
    
        auto addFF = vec2_default + 1.0f;
        auto subFF = vec2_default - 1.0f;
        auto mulFF = vec2_default * 1.0f;
        auto divFF = vec2_default / 1.0f;
    
        std::cout << vec2_default << std::endl;
    }

    // free functions
    {
        ::normalise(vec2_default);
        auto dot_free = ::dot(vec2_default, vec2_default);
        auto limit = ::limit(vec2_default, 2.0f); 

        auto limit_vec = djc::math::vec3f(1.0f, 1.0f, 1.0f);
        
        limit_vec = ::limit(limit_vec, 0.5f);

        std::cout << "limit " << limit_vec << std::endl;
        
    }

    // CONSTEXPR
    // -----------------------------------
    
    // constructors
    //
        constexpr vec2f constexpr1(1.0, 1.0);
        constexpr vec2f constexpr2(2.0, 2.0);
    //

    constexpr vec2f constexpr_add(constexpr1 + constexpr2);
    constexpr vec2f constexpr_min(constexpr1 - constexpr2);
    constexpr vec2f constexpr_mul(constexpr1 * constexpr2);
    constexpr vec2f constexpr_div(constexpr1 / constexpr2);
   
    constexpr vec2f constexpr_add_float(constexpr1 + 1.0f);    
    constexpr vec2f constexpr_min_float(constexpr1 - 1.0f);
    constexpr vec2f constexpr_mul_float(constexpr1 * 1.0f);
    constexpr vec2f constexpr_div_float(constexpr1 / 1.0f);
    
    constexpr vec2f constexpr_copy(constexpr1);
}

//------------------------------------------------------------
void 
vec3_tests() {
    /* Runtime */ 
    // -----------------------------------
    
    // constructors //
    //
        vec3f vec3_default;
        vec3f vec3_explicit(4, 5, 6);
        vec3f vec3_vec2_float(vec2f(1.0f, 1.0), 1.0);
        vec3f vec3_float_vec2(1.0f, vec2f(1.0f, 1.0f));
        vec3f vec3_copy(vec3_default);
    //

    // member functions
    {   
        auto len     = vec3_explicit.length();
        auto len2    = vec3_explicit.length2();
       
        vec3_explicit.normalise();
        
        auto dot     = vec3_explicit.dot(vec3_vec2_float);
        auto cross   = vec3_explicit.cross(vec3_vec2_float); 
        auto to_vec2 = vec3_explicit.to_vec2();
    }

    // member operator overloads
    {
        auto pos     = +vec3_explicit;
        auto neg     = -vec3_explicit;
        
        pos += neg;
        pos -= neg;
        pos *= neg;
        pos /= neg;

        pos += 1.0f;
        pos -= 1.0f;
        pos *= 1.0f;
        pos /= 1.0f;
    }

    // free function operator overloads
    {   
        auto add   = vec3_explicit + vec3_explicit;
        auto sub   = vec3_explicit - vec3_explicit;
        auto mul   = vec3_explicit * vec3_explicit;
        auto div   = vec3_explicit / vec3_explicit;
    
        auto addF  = 1.0f + vec3_explicit;
        auto subnF = 1.0f - vec3_explicit;
        auto mulF  = 1.0f * vec3_explicit;
        auto divF  = 1.0f / vec3_explicit;

        auto addFF = vec3_explicit + 1.0f;
        auto subFF = vec3_explicit - 1.0f;
        auto mulFF = vec3_explicit * 1.0f;
        auto divFF = vec3_explicit / 1.0f;
    
        std::cout << vec3_explicit << std::endl;
    }
       
    // free function operator overload for use with other classes
    {  
        auto matrix_test = mat3f() * vec3_explicit;
    }
    
    // free functions
    {   
        ::normalise(vec3_explicit);
        auto dot_free = ::dot(vec3_explicit, vec3_default);
    }
    
    /* constexpr */
    // -----------------------------------

    // constructors
    //
        constexpr vec3f constexpr_default;
        constexpr vec3f constexpr_explicit(1.0, 1.0, 1.0);
        constexpr vec3f constexpr_vec2_float(vec2f(1.0, 1.0), 1.0);
        constexpr vec3f constexpr_copy(constexpr_default);
    //

    // members
    {
        constexpr auto constexpr_pos     = +constexpr_default;
        constexpr auto constexpr_neg     = -constexpr_default;
        constexpr auto constexpr_length2 = constexpr_default.length2();
        constexpr auto constexpr_dot     = constexpr_default.dot(constexpr_explicit); 
        constexpr auto constexpr_cross   = constexpr_default.cross(constexpr_explicit);
        constexpr auto constexpr_tovec2  = constexpr_default.to_vec2();
    }

    // free functions - operator overloads
    {
        constexpr auto constexpr_add = constexpr_default + constexpr_explicit;
        constexpr auto constexpr_min = constexpr_default - constexpr_explicit;
        constexpr auto constexpr_mul = constexpr_default * constexpr_explicit;
        constexpr auto constexpr_div = constexpr_default / constexpr_explicit;
    
        constexpr auto constexpr_add_float = constexpr_default + 1.0f; 
        constexpr auto constexpr_min_float = constexpr_default - 1.0f; 
        constexpr auto constexpr_mul_float = constexpr_default * 1.0f; 
        constexpr auto constexpr_div_float = constexpr_default / 1.0f; 
    
        constexpr auto constexpr_add_float_vec = 2.0f + constexpr_explicit; 
        constexpr auto constexpr_min_float_vec = 2.0f - constexpr_explicit;
        constexpr auto constexpr_mul_float_vec = 2.0f * constexpr_explicit;
        constexpr auto constexpr_div_float_vec = 2.0f / constexpr_explicit;
    }

    // free function operator overload for use with other classes
    {  
        auto matrix_test = mat3f() * vec3_explicit;
    }

    // free functions
    {
        constexpr auto constexpr_free_dot = ::dot(constexpr_explicit, constexpr_vec2_float);
    }

}

//------------------------------------------------------------
void 
vec4_tests() {
    /* Runtime */ 
    // -----------------------------------
    {   
        // constructors //
        //
            vec4f vec4_default;
            vec4f vec4_explicit(4, 5, 6, 7);
            vec4f vec4_vec2_float_float(vec2f(1.0f, 1.0), 1.0, 1.0);
            vec4f vec4_float_float_vec2(1.0, 1.0, vec2f(1.0, 1.0));
            vec4f vec4_vec2_vec2(vec2f(1.0f, 1.0f), vec2f(1.0f, 1.0f));
            vec4f vec4_vec3_float(vec3f(1.0, 1.0, 1.0), 1.0f);
            vec4f vec4_float_vec3(1.0f, vec3f(1.0, 1.0, 1.0));
            vec4f vec4_copy(vec4_default);
        //

        // member functions
        {   
            auto len     = vec4_explicit.length();
            auto len2    = vec4_explicit.length2();
           
            vec4_explicit.normalise();
            
            auto dot     = vec4_explicit.dot(vec4_vec2_float_float);
            auto to_vec2 = vec4_explicit.to_vec2();
            auto to_vec3 = vec4_explicit.to_vec3();
        }

        // member operator overloads
        {
            auto pos     = +vec4_explicit;
            auto neg     = -vec4_explicit;
            
            pos += neg;
            pos -= neg;
            pos *= neg;
            pos /= neg;
        
            pos += 1.0f;
            pos -= 1.0f;
            pos *= 1.0f;
            pos /= 1.0f; 
        }

        // free function operator overloads
        {   
            auto add   = vec4_explicit + vec4_explicit;
            auto sub   = vec4_explicit - vec4_explicit;
            auto mul   = vec4_explicit * vec4_explicit;
            auto div   = vec4_explicit / vec4_explicit;
        
            auto addF  = 1.0f + vec4_explicit;
            auto subnF = 1.0f - vec4_explicit;
            auto mulF  = 1.0f * vec4_explicit;
            auto divF  = 1.0f / vec4_explicit;

            auto addFF = vec4_explicit + 1.0f;
            auto subFF = vec4_explicit - 1.0f;
            auto mulFF = vec4_explicit * 1.0f;
            auto divFF = vec4_explicit / 1.0f;
        
            std::cout << vec4_explicit << std::endl;
        }
           
        // free function operator overload for use with other classes
        {  
            auto matrix_test = mat4f() * vec4_explicit;
        }
        
        // free functions
        {   
            ::normalise(vec4_explicit);
            auto dot_free = ::dot(vec4_explicit, vec4_default);
        }
    }
    
    /* constexpr */
    // -----------------------------------
    {
        // constructors //
        //
            constexpr vec4f vec4_default;
            constexpr vec4f vec4_explicit(4, 5, 6, 7);
            constexpr vec4f vec4_vec2_float_float(vec2f(1.0f, 1.0), 1.0, 1.0);
            constexpr vec4f vec4_vec2_vec2(vec2f(1.0f, 1.0f), vec2f(1.0f, 1.0f));
            constexpr vec4f vec4_vec3_float(vec3f(1.0, 1.0, 1.0), 1.0f);
            constexpr vec4f vec4_copy(vec4_default);
        //

        // member functions
        {   
            constexpr auto len2    = vec4_explicit.length2();
            constexpr auto dot     = vec4_explicit.dot(vec4_vec2_float_float);
            constexpr auto to_vec2 = vec4_explicit.to_vec2();
            constexpr auto to_vec3 = vec4_explicit.to_vec3();
         }

        // member operator overloads
        {
            constexpr auto pos     = +vec4_explicit;
            constexpr auto neg     = -vec4_explicit;
        }   

        // free function operator overloads
        {   
            constexpr auto add   = vec4_explicit + vec4_explicit;
            constexpr auto sub   = vec4_explicit - vec4_explicit;
            constexpr auto mul   = vec4_explicit * vec4_explicit;
            constexpr auto div   = vec4_explicit / vec4_explicit;
    
            constexpr auto addF  = 1.0f + vec4_explicit;
            constexpr auto subnF = 1.0f - vec4_explicit;
            constexpr auto mulF  = 1.0f * vec4_explicit;
            constexpr auto divF  = 1.0f / vec4_explicit;

            constexpr auto addFF = vec4_explicit + 1.0f;
            constexpr auto subFF = vec4_explicit - 1.0f;
            constexpr auto mulFF = vec4_explicit * 1.0f;
            constexpr auto divFF = vec4_explicit / 1.0f;
    
            std::cout << vec4_explicit << std::endl;
         }
       
        // free function operator overload for use with other classes
        {  
            constexpr auto matrix_test = mat4f() * vec4_explicit;
        }
        
        // free functions
        {   
            constexpr auto dot_free = ::dot(vec4_explicit, vec4_default);
        }
    }
}

//------------------------------------------------------------
void 
mat3_tests() {
    // construction
    mat3f mat_one;
    mat3f mat_two;

    // friend free - // @TODO : clear() clear(T) need implementing 

    // friend free operators
    auto mult = mat_one * mat_two;
    auto mult_vec4 = mat_one * vec3f(1.0f);
    
    std::cout << mat_one << std::endl;

    // private operators - cant test
    // ...
}

//------------------------------------------------------------
void 
mat4_tests() {
    // construction
    mat4f mat_one;
    mat4f mat_two;

    // member functions
    auto to_mat3 = mat_one.to_mat3();

    // friend free - // @TODO : clear() clear(T) need implementing 
    

    // friend free operators
    auto mult = mat_one * mat_two;
    auto mult_vec4 = mat_one * vec4f(1.0f);
    std::cout << mat_one << std::endl;

    // private operators - cant test
    // ...
}

//------------------------------------------------------------
void 
transform_tests() {
    // mat3 
    constexpr auto iden_mat3 = create_mat3_identity_matrix<float>();
    auto rot_mat3 = create_mat3_rotation_matrix(vec3f(1.0f));
    
    // mat4
    constexpr auto iden_mat4              = create_mat4_identity_matrix<float>();
    constexpr auto trans_mat4             = create_mat4_translation_matrix(vec3f(1.0f));
    auto rot_mat4                         = create_mat4_rotation_matrix(vec3f(1.0f));
    constexpr auto scale_mat4             = create_mat4_scale_matrix(vec3f(1.0f));
    auto model_mat4                       = create_mat4_model_matrix(vec3f(0.0f), vec3f(0.0f), vec3f(1.0f)); 
    constexpr auto ortho_mat4             = create_mat4_orthographic_matrix(900, 600, 0.01f, 1000.0f);
    auto proj_mat4                        = create_mat4_projection_matrix(to_radians(70.0f), 900.0f / 600.0f, 0.01f, 1000.0f);
    constexpr auto view_mat4              = create_mat4_view_matrix(vec3f(0), vec3f(0), vec3f(0,1,0));
    constexpr auto bird_view_mat4         = create_mat4_birds_eye_view_matrix<float>();
    constexpr auto screen_spaceTrans_mat4 = create_mat4_screenspace_transform(90.0f / 2.0f, 600.0f / 2.0f);
    
    // other
    vec4f position(1.0, 1.0f, 1.0f, 1.0f);
    transform(position, trans_mat4);
    auto rotate_mat = rotate(90.0f, vec3f(0,1,0));
}

//------------------------------------------------------------
void
common_tests() {
    constexpr auto lerp_f = ::lerp(0.0f, 100.0f, 50.0f);
    constexpr auto lerp_d = ::lerp(0.0, 100.0, 50.0);
    constexpr auto clamp = ::clamp(100.0f, 10.0f, 50.0f);
    constexpr auto floor_int_f = djc::math::floor_int(10.7f);
    constexpr auto floor_int_d = djc::math::floor_int(10.7);
    constexpr auto floor_f = djc::math::floor(10.7f);
    constexpr auto floor_d = djc::math::floor(10.7);
    constexpr auto toRad_f = to_radians(90.0f);
    constexpr auto toRad_d = to_radians(90.0);
    constexpr auto toDeg_f = to_degrees(1.0f);
    constexpr auto toDeg_d = to_degrees(1.0);

}

//------------------------------------------------------------
void 
constexpr_math_tests() {
    constexpr auto pow = compile::constexpr_power(2, 4);
    constexpr auto fac = compile::constexpr_factoral(5);
    constexpr auto sqrt = compile::constexpr_sqrt(24);
    constexpr auto sin = compile::constexpr_sin(0.5); 
}

//------------------------------------------------------------
void
perlin_tests() {
    perlin<double> height_map{2555};

    auto value {height_map.noise(0.45, 0.8, 0.55)};
}
//------------------------------------------------------------
int 
main() {
    // vector tests
    vec2_tests();
    vec3_tests();
    vec4_tests(); 
    
    // matrix tests
    mat3_tests();
    mat4_tests(); 

    // other
    transform_tests();
    common_tests();
    constexpr_math_tests();
    perlin_tests();

    return 0;
}
