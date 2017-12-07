// cuber_test_suites.cpp  INCOMPLETE
// Glenn G. Chappell
// 2 Dec 2017
//
// For CS 311 Fall 2017
// Tests for class Cuber: test suites
// For Assignment 8, Exercise B
// Uses the "Catch" unit-testing framework
// Requires cuber_test_main.cpp, catch.hpp, cuber.h

// Includes for code to be tested
#include "cuber.h"         // For class Cuber
#include "cuber.h"         // Double inclusion test

#define CATCH_CONFIG_FAST_COMPILE
                           // Disable some features for faster compile
#include "catch.hpp"       // For the "Catch" unit-testing framework
#include <cmath>           // For std::pow
// Additional includes for this test program


// *********************************************************************
// Test Cases
// *********************************************************************

TEST_CASE("Testing input types",
           "[types]" )
{
	Cuber cc;
	SECTION("Taking various const & non-const types") {
		const int num = 5;
		const double dnum = 5.5;
		const char constinputchar = 'b';
		int regnum = 6;
		double regdnum = 4.5;
		char inputchar = 'a';
		cc(num);
		cc(dnum);
		cc(regnum);
		cc(regdnum);
		cc(constinputchar);
		cc(inputchar);

		INFO("Program failed to compile because it can't handle const types.")
			REQUIRE(0 == 0); // section passes if it compiles
	}

}
TEST_CASE("Cuber: Calculating Answers",
	"[answers]")
{
	Cuber cc;
	SECTION("Taking positive numbers") {
		INFO ("Answers for both small and large positive numbers should be correct")
		REQUIRE(cc(2) == pow(2, 3));
		REQUIRE(cc(50) == pow(50, 3));
		REQUIRE(cc(2.4) == 13.824);
		REQUIRE(cc(50.4) == pow(50.4, 3));
	}
	SECTION("Taking negative numbers") {
		INFO("Answers for both small and large negative numbers should be correct")
		REQUIRE(cc(-2) == pow(-2, 3));
		REQUIRE(cc(-50) == pow(-50, 3));
		REQUIRE(cc(-2.5) == -15.625);
		REQUIRE(cc(-50.3) == pow(-50.3, 3));
	}
	SECTION("Special cases (1,-1,0)") {
		{
			INFO("Handling -1");
			REQUIRE(cc(-1) == -1);
		}
		{
			INFO("Handling 1");
			REQUIRE(cc(1) == 1);
		}
		{
			INFO("Handling 0");
			REQUIRE(cc(0) == 0);
		}
	}}