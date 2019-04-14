#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <cmath>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a == 0 && b == 0)
    {
        throw std::runtime_error("Prohibited input");
    }
    if(a == 0 || b == 0)
    {
        return 1;
    }

    int gcd = 1;
    a = std::abs(a);
    b = std::abs(b);

    // iterate till a and b
    for(int i = 1; i <= a && i <= b; i++)
    {
        // check is the a and b are divisible by i
        if(a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

TEST_CASE("describe_gcd", "[gcd]")
{
    REQUIRE(gcd(2, 4) == 2);
    REQUIRE(gcd(9, 6) == 3);
    REQUIRE(gcd(3, 7) == 1);
    REQUIRE(gcd(0, 3) == 1);
    REQUIRE_THROWS(gcd(0, 0));
}

int checksum(int num)
{
    // the digit sum of a given integer is the sum of all its digits (e.g. the digit sum of 84001 is calculated as
    // 8+4+0+0+1 = 13). https://en.wikipedia.org/wiki/Digit_sum

    num = std::abs(num);

    std::vector<int> myvector;
    int rem = 0, i = 0, quersumme = 0;

    while(num)
    {
        rem = num % 10;
        myvector.push_back(rem);
        num = num / 10;
        i = i + 1;
    }

    for(int j = 0; j < i; j++)
    {
        quersumme = quersumme + myvector[j];
    }

    return quersumme;
}

TEST_CASE("describe_checksum", "[checksum]") { REQUIRE(checksum(118047) == 21); }

int sum_multiples()
{
    int a{1};
    int b{1000};
    int sum{0};

    for(int i = a; i < b + 1; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

TEST_CASE("describe_sum_multiples", "[sum_multiples]") { REQUIRE(sum_multiples() == 234168); }

float fract(float num) { return num - ((int)num); }

TEST_CASE("describe_fract", "[fract]") { REQUIRE(fract(14.395) == Approx(0.395f).epsilon(0.01)); }

struct Zylinder
{
    double volume{0};
    double oberflaeche{0};
};

Zylinder computeZylinder(double radius, double height)
{
    if(height <= 0 || radius <= 0)
    {
        throw std::runtime_error("Prohibited input");
    }

    Zylinder answer;

    answer.volume = ((pow(radius, 2) * height) * M_PI);
    answer.oberflaeche = (2 * M_PI * (pow(radius, 2)));

    return answer;
};

TEST_CASE("describe_computeZylinder", "[computeZylinder]")
{
    REQUIRE(computeZylinder(1.3, 12.2).volume == Approx(64.77).epsilon(0.1));
    REQUIRE(computeZylinder(1.3, 12.2).oberflaeche == Approx(10.61).epsilon(0.1));
    REQUIRE_THROWS(computeZylinder(4.5, 0));
}

int factorial(int number)
{
    if(number <= 0)
    {
        throw std::runtime_error("Prohibited input");
    }

    int answer = 1;

    for(int i = number; i > 0; i--)
        answer = answer * i;

    return answer;
};

TEST_CASE("describe_factorial", "[factorial]")
{
    REQUIRE(factorial(5) == 120);
    REQUIRE_THROWS(factorial(-2));
}

bool isPrime(int number)
{
    if(number <= 0)
    {
        throw std::runtime_error("Prohibited input");
    }

    bool isPrime = true;

    for(int i = 2; i < number; i++)
    {
        if(number % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
};

TEST_CASE("describe_isPrime", "[isPrime]")
{
    REQUIRE(isPrime(5) == true);
    REQUIRE(isPrime(30) == false);
    REQUIRE_THROWS(isPrime(-2));
}

int main(int argc, char* argv[]) { return Catch::Session().run(argc, argv); }
