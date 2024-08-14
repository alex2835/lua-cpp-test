#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <print>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>

namespace bubble
{
void CreateVec2Bind( sol::state& lua )
{
	auto vec2_multiply_overloads = sol::overload( []( const glm::vec2& v1, const glm::vec2& v2 ) { return v1 * v2; },
												  []( const glm::vec2& v1, float value ) { return v1 * value; },
												  []( float value, const glm::vec2& v1 ) { return v1 * value; } );

	auto vec2_divide_overloads = sol::overload( []( const glm::vec2& v1, const glm::vec2& v2 ) { return v1 / v2; },
												[]( const glm::vec2& v1, float value ) { return v1 / value; },
												[]( float value, const glm::vec2& v1 ) { return v1 / value; } );

	auto vec2_addition_overloads = sol::overload( []( const glm::vec2& v1, const glm::vec2& v2 ) { return v1 + v2; },
												  []( const glm::vec2& v1, float value ) { return v1 + value; },
												  []( float value, const glm::vec2& v1 ) { return v1 + value; } );

	auto vec2_subtraction_overloads = sol::overload( []( const glm::vec2& v1, const glm::vec2& v2 ) { return v1 - v2; },
													 []( const glm::vec2& v1, float value ) { return v1 - value; },
													 []( float value, const glm::vec2& v1 ) { return v1 - value; } );

	lua.new_usertype<glm::vec2>(
		"vec2",
		sol::call_constructor,
		sol::constructors<glm::vec2(), glm::vec2( float ), glm::vec2( float, float )>(),
		"x",
		&glm::vec2::x,
		"y",
		&glm::vec2::y,
		sol::meta_function::multiplication,
		vec2_multiply_overloads,
		sol::meta_function::division,
		vec2_divide_overloads,
		sol::meta_function::addition,
		vec2_addition_overloads,
		sol::meta_function::subtraction,
		vec2_subtraction_overloads,
        sol::meta_function::to_string,
        []( const glm::vec2& v ) { return std::format( "[{}, {}]", v.x, v.y ); },
		"length",
		[]( const glm::vec2& v ) { return glm::length( v ); },
		"lengthSq",
		[]( const glm::vec2& v ) { return glm::length2( v ); },
		"normalize",
		[]( const glm::vec2& v1 ) { return glm::normalize( v1 ); },
		"normalize2",
		[]( const glm::vec2& v1, const glm::vec2& v2 ) { return glm::normalize( v2 - v1 ); }
	);
}


void CreateVec3Bind( sol::state& lua )
{
	auto vec3_multiply_overloads = sol::overload( []( const glm::vec3& v1, const glm::vec3& v2 ) { return v1 * v2; },
												  []( const glm::vec3& v1, float value ) { return v1 * value; },
												  []( float value, const glm::vec3& v1 ) { return v1 * value; } );

	auto vec3_divide_overloads = sol::overload( []( const glm::vec3& v1, const glm::vec3& v2 ) { return v1 / v2; },
												[]( const glm::vec3& v1, float value ) { return v1 / value; },
												[]( float value, const glm::vec3& v1 ) { return v1 / value; } );

	auto vec3_addition_overloads = sol::overload( []( const glm::vec3& v1, const glm::vec3& v2 ) { return v1 + v2; },
												  []( const glm::vec3& v1, float value ) { return v1 + value; },
												  []( float value, const glm::vec3& v1 ) { return v1 + value; } );

	auto vec3_subtraction_overloads = sol::overload( []( const glm::vec3& v1, const glm::vec3& v2 ) { return v1 - v2; },
													 []( const glm::vec3& v1, float value ) { return v1 - value; },
													 []( float value, const glm::vec3& v1 ) { return v1 - value; } );

	lua.new_usertype<glm::vec3>(
		"vec3",
		sol::call_constructor,
		sol::constructors<glm::vec3(), glm::vec3( float ), glm::vec3( float, float, float )>(),
		"x",
		&glm::vec3::x,
		"y",
		&glm::vec3::y,
		"z",
		&glm::vec3::z,
		sol::meta_function::multiplication,
		vec3_multiply_overloads,
		sol::meta_function::division,
		vec3_divide_overloads,
		sol::meta_function::addition,
		vec3_addition_overloads,
		sol::meta_function::subtraction,
		vec3_subtraction_overloads,
		sol::meta_function::to_string,
		[]( const glm::vec3& v ) { return std::format("[{}, {}, {}]", v.x, v.y, v.z ); },
		"length",
		[]( const glm::vec3& v ) { return glm::length( v ); },
		"lengthSq",
		[]( const glm::vec3& v ) { return glm::length2( v ); },
		"normalize",
		[]( const glm::vec3& v1 ) { return glm::normalize( v1 ); },
		"normalize2",
		[]( const glm::vec3& v1, const glm::vec3& v2 ) { return glm::normalize( v2 - v1 ); }
	);
}


void CreateVec4Bind( sol::state& lua )
{
	auto vec4_multiply_overloads = sol::overload( []( const glm::vec4& v1, const glm::vec4& v2 ) { return v1 * v2; },
												  []( const glm::vec4& v1, float value ) { return v1 * value; },
												  []( float value, const glm::vec4& v1 ) { return v1 * value; } );

	auto vec4_divide_overloads = sol::overload( []( const glm::vec4& v1, const glm::vec4& v2 ) { return v1 / v2; },
												[]( const glm::vec4& v1, float value ) { return v1 / value; },
												[]( float value, const glm::vec4& v1 ) { return v1 / value; } );

	auto vec4_addition_overloads = sol::overload( []( const glm::vec4& v1, const glm::vec4& v2 ) { return v1 + v2; },
												  []( const glm::vec4& v1, float value ) { return v1 + value; },
												  []( float value, const glm::vec4& v1 ) { return v1 + value; } );

	auto vec4_subtraction_overloads = sol::overload( []( const glm::vec4& v1, const glm::vec4& v2 ) { return v1 - v2; },
													 []( const glm::vec4& v1, float value ) { return v1 - value; },
													 []( float value, const glm::vec4& v1 ) { return v1 - value; } );

	lua.new_usertype<glm::vec4>(
		"vec4",
		sol::call_constructor,
		sol::constructors<glm::vec4( float ), glm::vec4( float, float, float, float )>(),
		"x",
		&glm::vec4::x,
		"y",
		&glm::vec4::y,
		"z",
		&glm::vec4::z,
		"w",
		&glm::vec4::w,
		sol::meta_function::multiplication,
		vec4_multiply_overloads,
		sol::meta_function::division,
		vec4_divide_overloads,
		sol::meta_function::addition,
		vec4_addition_overloads,
		sol::meta_function::subtraction,
		vec4_subtraction_overloads,
        sol::meta_function::to_string,
        []( const glm::vec4& v ) { return std::format( "[{}, {}, {}, {}]", v.x, v.y, v.z, v.w ); },
		"length",
		[]( const glm::vec4& v ) { return glm::length( v ); },
		"lengthSq",
		[]( const glm::vec4& v ) { return glm::length2( v ); },
		"normalize",
		[]( const glm::vec4& v1 ) { return glm::normalize( v1 ); },
		"normalize2",
		[]( const glm::vec4& v1, const glm::vec4& v2 ) { return glm::normalize( v2 - v1 ); }
	);
}

// glm::mat2
void CreateMat2Bind( sol::state& lua )
{
    auto mat2_multiply_overloads = sol::overload( []( const glm::mat2& m1, const glm::mat2& m2 ) { return m1 * m2; },
												  []( const glm::mat2& m, const glm::vec2& v ) { return m * v; },
                                                  []( const glm::mat2& m, float value ) { return m * value; },
                                                  []( float value, const glm::mat2& m ) { return m * value; } );

    auto mat2_addition_overloads = sol::overload( []( const glm::mat2& m1, const glm::mat2& m2 ) { return m1 + m2; } );

	auto mat2_subtraction_overloads = sol::overload( []( const glm::mat2& m1, const glm::mat2& m2 ) { return m1 - m2; } );

	auto mat2_to_string = []( const glm::mat2& m )
	{
        return std::format( "[{}, {},\n"
                            " {}, {}]",
                            m[0][0], m[0][1],
                            m[1][0], m[1][1] );
	};

    lua.new_usertype<glm::mat2>(
        "mat2",
        sol::call_constructor,
        sol::constructors<glm::mat2()>(),
        sol::meta_function::multiplication,
        mat2_multiply_overloads,
        sol::meta_function::addition,
        mat2_addition_overloads,
        sol::meta_function::subtraction,
        mat2_subtraction_overloads,
        sol::meta_function::to_string,
		mat2_to_string
	);
}

// glm::mat3
void CreateMat3Bind( sol::state& lua )
{
    auto mat3_multiply_overloads = sol::overload( []( const glm::mat3& m1, const glm::mat3& m2 ) { return m1 * m2; },
                                                  []( const glm::mat3& m, const glm::vec3& v ) { return m * v; },
                                                  []( const glm::mat3& m, float value ) { return m * value; },
                                                  []( float value, const glm::mat3& m ) { return m * value; } );

    auto mat3_addition_overloads = sol::overload( []( const glm::mat3& m1, const glm::mat3& m2 ) { return m1 + m2; } );

    auto mat3_subtraction_overloads = sol::overload( []( const glm::mat3& m1, const glm::mat3& m2 ) { return m1 - m2; } );

	auto mat3_to_string = []( const glm::mat3& m )
	{
		return std::format( "[{}, {}, {},\n"
							" {}, {}, {},\n"
							" {}, {}, {}]",
							m[0][0], m[0][1], m[0][2],
							m[1][0], m[1][1], m[1][2],
							m[2][0], m[2][1], m[2][2] );
	};

    lua.new_usertype<glm::mat3>(
        "mat3",
        sol::call_constructor,
        sol::constructors<glm::mat3()>(),
        sol::meta_function::multiplication,
        mat3_multiply_overloads,
        sol::meta_function::addition,
        mat3_addition_overloads,
        sol::meta_function::subtraction,
        mat3_subtraction_overloads,
        sol::meta_function::to_string,
		mat3_to_string
    );
}

// glm::mat4
void CreateMat4Bind( sol::state& lua )
{
    auto mat4_multiply_overloads = sol::overload( []( const glm::mat4& m1, const glm::mat4& m2 ) { return m1 * m2; },
                                                  []( const glm::mat4& m, const glm::vec4& v ) { return m * v; },
                                                  []( const glm::mat4& m, float value ) { return m * value; },
                                                  []( float value, const glm::mat4& m ) { return m * value; } );

    auto mat4_addition_overloads = sol::overload( []( const glm::mat4& m1, const glm::mat4& m2 ) { return m1 + m2; } );

    auto mat4_subtraction_overloads = sol::overload( []( const glm::mat4& m1, const glm::mat4& m2 ) { return m1 - m2; } );

    auto mat4_to_string = []( const glm::mat4& m )
    {
        return std::format( "[{}, {}, {}, {},\n"
                            " {}, {}, {}, {},\n"
                            " {}, {}, {}, {},\n"
                            " {}, {}, {}, {}]",
                            m[0][0], m[0][1], m[0][2], m[0][3],
                            m[1][0], m[1][1], m[1][2], m[1][3],
                            m[2][0], m[2][1], m[2][2], m[2][3],
                            m[3][0], m[3][1], m[3][2], m[3][3] );
    };

	lua.new_usertype<glm::mat4>(
		"mat4",
		sol::call_constructor,
		sol::constructors<glm::mat4()>(),
		sol::meta_function::multiplication,
		mat4_multiply_overloads,
		sol::meta_function::addition,
		mat4_addition_overloads,
		sol::meta_function::subtraction,
		mat4_subtraction_overloads,
		sol::meta_function::to_string,
		mat4_to_string
    );
}

/*
 * Some helper math functions
 */
void MathFreeFunctions( sol::state& lua )
{
    lua.set_function( "identity_mat2", glm::identity<glm::mat2> );
	lua.set_function( "identity_mat3", glm::identity<glm::mat3> );
	lua.set_function( "identity_mat4", glm::identity<glm::mat4> );

	lua.set_function( "distance",
		sol::overload( 
			[]( glm::vec2& a, glm::vec2& b ) { return glm::distance( a, b ); },
			[]( glm::vec3& a, glm::vec3& b ) { return glm::distance( a, b ); },
			[]( glm::vec4& a, glm::vec4& b ) { return glm::distance( a, b ); }
		) 
	);

	lua.set_function( "lerp", []( float a, float b, float f ) { return std::lerp( a, b, f ); } );
	
	lua.set_function( "clamp",
		sol::overload( 
			[]( float value, float min, float max ) { return std::clamp( value, min, max ); },
			[]( double value, double min, double max ) { return std::clamp( value, min, max ); },
			[]( int value, int min, int max ) { return std::clamp( value, min, max ); }
		)
	);

	lua.set_function( "distance",
		sol::overload( 
			[]( glm::vec2& a, glm::vec2& b ) { return glm::distance( a, b ); },
			[]( glm::vec3& a, glm::vec3& b ) { return glm::distance( a, b ); },
			[]( glm::vec4& a, glm::vec4& b ) { return glm::distance( a, b ); }
		)
	);

	lua.set_function( "nearly_zero", 
		sol::overload(
			[]( const glm::vec2& v )
			{
				return glm::epsilonEqual( v.x, 0.f, 0.001f ) and
					   glm::epsilonEqual( v.y, 0.f, 0.001f );
			},
			[]( const glm::vec3& v )
			{
				return glm::epsilonEqual( v.x, 0.f, 0.001f ) and
					   glm::epsilonEqual( v.y, 0.f, 0.001f ) and
					   glm::epsilonEqual( v.z, 0.f, 0.001f );
			},
			[]( const glm::vec4& v )
			{
				return glm::epsilonEqual( v.x, 0.f, 0.001f ) and
					   glm::epsilonEqual( v.y, 0.f, 0.001f ) and
					   glm::epsilonEqual( v.z, 0.f, 0.001f ) and
					   glm::epsilonEqual( v.w, 0.f, 0.001f );
			}
		)
	);
}


void CreateGLMBindings( sol::state& lua )
{
	CreateVec2Bind( lua );
	CreateVec3Bind( lua );
	CreateVec4Bind( lua );
	CreateMat2Bind( lua );
	CreateMat3Bind( lua );
	CreateMat4Bind( lua );
	MathFreeFunctions( lua );
}
} // namespace bubble




int main( int, char* [] )
{
    sol::state lua;
    lua.open_libraries( sol::lib::base, sol::lib::io );
	
	bubble::CreateGLMBindings( lua );

	try
	{
        lua.safe_script( R"(
			test_vec = vec2(1,1)
			test_mat2 = identity_mat2()
			io.write( tostring(test_mat2 * test_vec) )
		)" );
	}
    catch ( std::exception& e )
	{
		std::print( "{}", e.what() );
	}
    return 0;
}