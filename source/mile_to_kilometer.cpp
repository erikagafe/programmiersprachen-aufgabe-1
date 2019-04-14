//
// Created by Erika on 4/11/19.
//
#define CATCH_CONFIG_RUNNER

#include "mile_to_kilometer.h"
#include "catch.hpp"
#include <iostream>

double mile_to_kilometer(double mile)
{
    double km{0};

    if(mile <= 0)
    {
        throw std::runtime_error("Prohibited input");
    }

    km = (mile / 0.62137);

    return km;
}

TEST_CASE("describe_mile_to_kilometer", "[mile_to_kilometer]")
{
    REQUIRE(mile_to_kilometer(60) == Approx(95.5608).epsilon(0.01));
}

int main()
{
    double mile{0};

    std::cout << "Bitte geben Sie die Nummer zu konvertierenden Meilen ein : ";
    std::cin >> mile;
    std::cout << "Sie sind " << mile_to_kilometer(mile) << " Kilometer" << '\n';

    return 0;
}
