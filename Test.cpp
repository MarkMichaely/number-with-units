/**
 * unit test of board.cpp

 * AUTHORS: <Mark Michaely>
 * 
 * Date: 2021-04
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("0: Testing EQ and NE"){
    CHECK_EQ(NumberWithUnits{1,"km"},NumberWithUnits(1000,"m"));
    CHECK_EQ(NumberWithUnits{1,"kg"},NumberWithUnits(1000,"g"));
    CHECK_EQ(NumberWithUnits{1,"hour"},NumberWithUnits(1*60*60,"sec"));
    CHECK_EQ(NumberWithUnits{1,"USD"},NumberWithUnits(3.33,"ILS"));
    CHECK_EQ(NumberWithUnits{1,"ton"},NumberWithUnits(1000,"kg"));
    CHECK_NE(NumberWithUnits{1,"kg"},NumberWithUnits{2,"kg"});
    CHECK_NE(NumberWithUnits{1,"min"},NumberWithUnits{66,"sec"});
    CHECK_NE(NumberWithUnits{1,"min"},NumberWithUnits{0.5,"hour"});
    CHECK_NE(NumberWithUnits{1,"m"},NumberWithUnits{1000,"cm"});
}
/*testing every lawful case of adding*/
TEST_CASE("1: Testing operator +"){
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};
    CHECK(num_cm + NumberWithUnits {1, "cm"} == NumberWithUnits {3, "cm"});
    CHECK(num_m + NumberWithUnits {1, "m"} == NumberWithUnits {3, "m"});
    CHECK(num_km + NumberWithUnits {1, "km"} == NumberWithUnits {3, "km"});
    CHECK(num_kg + NumberWithUnits {1, "kg"} == NumberWithUnits {3, "kg"});
    CHECK(num_g + NumberWithUnits {1, "g"} == NumberWithUnits {3, "g"});
    CHECK(num_ton + NumberWithUnits {1, "ton"} == NumberWithUnits {3, "ton"});
    CHECK(num_hour + NumberWithUnits {1, "hour"} == NumberWithUnits {3, "hour"});
    CHECK(num_min + NumberWithUnits {1, "min"} == NumberWithUnits {3, "min"});
    CHECK(num_sec + NumberWithUnits {1, "sec"} == NumberWithUnits {3, "sec"});
    CHECK(num_ILS + NumberWithUnits {1, "ILS"} == NumberWithUnits {3, "ILS"});
    CHECK(num_USD + NumberWithUnits {1, "USD"} == NumberWithUnits {3, "USD"});

    CHECK(num_cm + NumberWithUnits {1, "km"} == NumberWithUnits {2 + 1*100*1000, "cm"});
    CHECK(num_cm + NumberWithUnits {1, "m"} == NumberWithUnits {2 + 1*100, "cm"});

    CHECK(num_m + NumberWithUnits {1, "cm"} == NumberWithUnits {2 + 1/100, "m"});
    CHECK(num_m + NumberWithUnits {1, "km"} == NumberWithUnits {2 + 1*1000, "m"});

    CHECK(num_km + NumberWithUnits {1, "m"} == NumberWithUnits {2 + 1/1000, "km"});
    CHECK(num_km + NumberWithUnits {1, "cm"} == NumberWithUnits {2 + 1/100/1000, "km"});

    CHECK(num_kg + NumberWithUnits {1, "ton"} == NumberWithUnits {2 + 1*1000, "kg"});
    CHECK(num_kg + NumberWithUnits {1, "g"} == NumberWithUnits {2 + 1/1000, "kg"});

    CHECK(num_g + NumberWithUnits {1, "km"} == NumberWithUnits {2 + 1*1000, "g"});
    CHECK(num_g + NumberWithUnits {1, "ton"} == NumberWithUnits {2 + 1*1000*1000, "g"});

    CHECK(num_ton + NumberWithUnits {1, "g"} == NumberWithUnits {2 + 1/1000/1000, "ton"});
    CHECK(num_ton + NumberWithUnits {1, "kg"} == NumberWithUnits {2 + 1/1000, "ton"});

    CHECK(num_hour + NumberWithUnits {1, "sec"} == NumberWithUnits {2 + 1/60/60, "hour"});
    CHECK(num_hour + NumberWithUnits {1, "min"} == NumberWithUnits {2 + 1/60, "hour"});

    CHECK(num_min + NumberWithUnits {1, "sec"} == NumberWithUnits {2 + 1/60, "min"});
    CHECK(num_min + NumberWithUnits {1, "hour"} == NumberWithUnits {2 + 1*60, "min"});

    CHECK(num_sec + NumberWithUnits {1, "hour"} == NumberWithUnits {2 + 1*60*60, "sec"});
    CHECK(num_sec + NumberWithUnits {1, "min"} == NumberWithUnits {2 + 1*60, "sec"});

    CHECK(num_ILS + NumberWithUnits {1, "USD"} == NumberWithUnits {2 + 1*3.33, "ILS"});
    CHECK(num_USD + NumberWithUnits {1, "ILS"} == NumberWithUnits {2 + 1/3.33, "USD"});
    
}
/*testing every lawful case of substracting*/
TEST_CASE("2: Testing operator -"){
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};
    CHECK(num_cm - NumberWithUnits {1, "cm"} == NumberWithUnits {1, "cm"});
    CHECK(num_m - NumberWithUnits {1, "m"} == NumberWithUnits {1, "m"});
    CHECK(num_km - NumberWithUnits {1, "km"} == NumberWithUnits {1, "km"});
    CHECK(num_kg - NumberWithUnits {1, "kg"} == NumberWithUnits {1, "kg"});
    CHECK(num_g - NumberWithUnits {1, "g"} == NumberWithUnits {1, "g"});
    CHECK(num_ton - NumberWithUnits {1, "ton"} == NumberWithUnits {1, "ton"});
    CHECK(num_hour - NumberWithUnits {1, "hour"} == NumberWithUnits {1, "hour"});
    CHECK(num_min - NumberWithUnits {1, "min"} == NumberWithUnits {1, "min"});
    CHECK(num_sec - NumberWithUnits {1, "sec"} == NumberWithUnits {1, "sec"});
    CHECK(num_ILS - NumberWithUnits {1, "ILS"} == NumberWithUnits {1, "ILS"});
    CHECK(num_USD - NumberWithUnits {1, "USD"} == NumberWithUnits {1, "USD"});

    CHECK(num_cm - NumberWithUnits {1, "km"} == NumberWithUnits {2 - 1*100*1000, "cm"});
    CHECK(num_cm - NumberWithUnits {1, "m"} == NumberWithUnits {2 - 1*100, "cm"});

    CHECK(num_m - NumberWithUnits {1, "cm"} == NumberWithUnits {2 - 1/100, "m"});
    CHECK(num_m - NumberWithUnits {1, "km"} == NumberWithUnits {2 - 1*1000, "m"});

    CHECK(num_km - NumberWithUnits {1, "m"} == NumberWithUnits {2 - 1/1000, "km"});
    CHECK(num_km - NumberWithUnits {1, "cm"} == NumberWithUnits {2 - 1/100/1000, "km"});

    CHECK(num_kg - NumberWithUnits {1, "ton"} == NumberWithUnits {2 - 1*1000, "kg"});
    CHECK(num_kg - NumberWithUnits {1, "g"} == NumberWithUnits {2 - 1/1000, "kg"});

    CHECK(num_g - NumberWithUnits {1, "km"} == NumberWithUnits {2 - 1*1000, "g"});
    CHECK(num_g - NumberWithUnits {1, "ton"} == NumberWithUnits {2 - 1*1000*1000, "g"});

    CHECK(num_ton - NumberWithUnits {1, "g"} == NumberWithUnits {2 - 1/1000/1000, "ton"});
    CHECK(num_ton - NumberWithUnits {1, "kg"} == NumberWithUnits {2 - 1/1000, "ton"});

    CHECK(num_hour - NumberWithUnits {1, "sec"} == NumberWithUnits {2 - 1/60/60, "hour"});
    CHECK(num_hour - NumberWithUnits {1, "min"} == NumberWithUnits {2 - 1/60, "hour"});

    CHECK(num_min - NumberWithUnits {1, "sec"} == NumberWithUnits {2 - 1/60, "min"});
    CHECK(num_min - NumberWithUnits {1, "hour"} == NumberWithUnits {2 - 1*60, "min"});

    CHECK(num_sec - NumberWithUnits {1, "hour"} == NumberWithUnits {2 - 1*60*60, "sec"});
    CHECK(num_sec - NumberWithUnits {1, "min"} == NumberWithUnits {2 - 1*60, "sec"});

    CHECK(num_ILS - NumberWithUnits {1, "USD"} == NumberWithUnits {2 - 1*3.33, "ILS"});
    CHECK(num_USD - NumberWithUnits {1, "ILS"} == NumberWithUnits {2 - 1/3.33, "USD"});
    

}
/*checking every possible unit with operator unary + and -*/
TEST_CASE("3: Testing unary + and unary -"){
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};
    
    CHECK(+num_km == NumberWithUnits{2,"km"});
    CHECK(+num_m == NumberWithUnits{2,"m"});
    CHECK(+num_cm == NumberWithUnits{2,"cm"});
    CHECK(+num_g == NumberWithUnits{2,"g"});
    CHECK(+num_kg == NumberWithUnits{2,"kg"});
    CHECK(+num_ton == NumberWithUnits{2,"ton"});
    CHECK(+num_hour == NumberWithUnits{2,"hour"});
    CHECK(+num_min == NumberWithUnits{2,"min"});
    CHECK(+num_sec == NumberWithUnits{2,"sec"});
    CHECK(+num_ILS == NumberWithUnits{2,"ILS"});
    CHECK(+num_USD == NumberWithUnits{2,"USD"});

    CHECK(-num_km == NumberWithUnits{-2,"km"});
    CHECK(-num_m == NumberWithUnits{-2,"m"});
    CHECK(-num_cm == NumberWithUnits{-2,"cm"});
    CHECK(-num_g == NumberWithUnits{-2,"g"});
    CHECK(-num_kg == NumberWithUnits{-2,"kg"});
    CHECK(-num_ton == NumberWithUnits{-2,"ton"});
    CHECK(-num_hour == NumberWithUnits{-2,"hour"});
    CHECK(-num_min == NumberWithUnits{-2,"min"});
    CHECK(-num_sec == NumberWithUnits{-2,"sec"});
    CHECK(-num_ILS == NumberWithUnits{-2,"ILS"});
    CHECK(-num_USD == NumberWithUnits{-2,"USD"});
    
}
/*as += and -= I'm checking only once to see if every unit adds or substract correctly and changes object*/
TEST_CASE("4: testing operator += and -="){
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};
    num_km+= 1;
    num_m+= 1;
    num_cm+= 1;
    num_kg+= 1;
    num_g+= 1;
    num_ton+= 1;
    num_hour+= 1;
    num_min+= 1;
    num_sec+= 1;
    num_ILS+= 1;
    num_USD+= 1;
    CHECK(num_cm == NumberWithUnits {3, "cm"});
    CHECK(num_m== NumberWithUnits {3, "m"});
    CHECK(num_km == NumberWithUnits {3, "km"});
    CHECK(num_kg == NumberWithUnits {3, "kg"});
    CHECK(num_g== NumberWithUnits {3, "g"});
    CHECK(num_ton == NumberWithUnits {3, "ton"});
    CHECK(num_hour == NumberWithUnits {3, "hour"});
    CHECK(num_min == NumberWithUnits {3, "min"});
    CHECK(num_sec == NumberWithUnits {3, "sec"});
    CHECK(num_ILS == NumberWithUnits {3, "ILS"});
    CHECK(num_USD == NumberWithUnits {3, "USD"});
    num_km-= 1;
    num_m-= 1;
    num_cm-= 1;
    num_kg-= 1;
    num_g-= 1;
    num_ton-= 1;
    num_hour-= 1;
    num_min-= 1;
    num_sec-= 1;
    num_ILS-= 1;
    num_USD-= 1;
    CHECK(num_cm == NumberWithUnits {2, "cm"});
    CHECK(num_m == NumberWithUnits {2, "m"});
    CHECK(num_km == NumberWithUnits {2, "km"});
    CHECK(num_kg == NumberWithUnits {2, "kg"});
    CHECK(num_g == NumberWithUnits {2, "g"});
    CHECK(num_ton == NumberWithUnits {2, "ton"});
    CHECK(num_hour == NumberWithUnits {2, "hour"});
    CHECK(num_min == NumberWithUnits {2, "min"});
    CHECK(num_sec == NumberWithUnits {2, "sec"});
    CHECK(num_ILS == NumberWithUnits {2, "ILS"});
    CHECK(num_USD == NumberWithUnits {2, "USD"});
}

TEST_CASE("5: Testing increments ++ and --"){
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};
    /*post increment adds 1 after the check*/
    CHECK(num_cm++ == NumberWithUnits {2, "cm"});
    CHECK(num_m++ == NumberWithUnits {2, "m"});
    CHECK(num_km++ == NumberWithUnits {2, "km"});
    CHECK(num_kg++ == NumberWithUnits {2, "kg"});
    CHECK(num_g++ == NumberWithUnits {2, "g"});
    CHECK(num_ton++ == NumberWithUnits {2, "ton"});
    CHECK(num_hour++ == NumberWithUnits {2, "hour"});
    CHECK(num_min++ == NumberWithUnits {2, "min"});
    CHECK(num_sec++ == NumberWithUnits {2, "sec"});
    CHECK(num_ILS++ == NumberWithUnits {2, "ILS"});
    CHECK(num_USD++ == NumberWithUnits {2, "USD"});
    /*pre increment adds 1 before the check*/
    CHECK(++num_cm == NumberWithUnits {4, "cm"});
    CHECK(++num_m == NumberWithUnits {4, "m"});
    CHECK(++num_km == NumberWithUnits {4, "km"});
    CHECK(++num_kg == NumberWithUnits {4, "kg"});
    CHECK(++num_g == NumberWithUnits {4, "g"});
    CHECK(++num_ton == NumberWithUnits {4, "ton"});
    CHECK(++num_hour == NumberWithUnits {4, "hour"});
    CHECK(++num_min == NumberWithUnits {4, "min"});
    CHECK(++num_sec == NumberWithUnits {4, "sec"});
    CHECK(++num_ILS == NumberWithUnits {4, "ILS"});
    CHECK(++num_USD == NumberWithUnits {4, "USD"});

    CHECK(num_cm-- == NumberWithUnits {4, "cm"});
    CHECK(num_m-- == NumberWithUnits {4, "m"});
    CHECK(num_km-- == NumberWithUnits {4, "km"});
    CHECK(num_kg-- == NumberWithUnits {4, "kg"});
    CHECK(num_g-- == NumberWithUnits {4, "g"});
    CHECK(num_ton-- == NumberWithUnits {4, "ton"});
    CHECK(num_hour-- == NumberWithUnits {4, "hour"});
    CHECK(num_min-- == NumberWithUnits {4, "min"});
    CHECK(num_sec-- == NumberWithUnits {4, "sec"});
    CHECK(num_ILS-- == NumberWithUnits {4, "ILS"});
    CHECK(num_USD-- == NumberWithUnits {4, "USD"});
    
    CHECK(--num_cm == NumberWithUnits {2, "cm"});
    CHECK(--num_m == NumberWithUnits {2, "m"});
    CHECK(--num_km == NumberWithUnits {2, "km"});
    CHECK(--num_kg == NumberWithUnits {2, "kg"});
    CHECK(--num_g == NumberWithUnits {2, "g"});
    CHECK(--num_ton == NumberWithUnits {2, "ton"});
    CHECK(--num_hour == NumberWithUnits {2, "hour"});
    CHECK(--num_min == NumberWithUnits {2, "min"});
    CHECK(--num_sec == NumberWithUnits {2, "sec"});
    CHECK(--num_ILS == NumberWithUnits {2, "ILS"});
    CHECK(--num_USD == NumberWithUnits {2, "USD"});
}
TEST_CASE("6:Testing operator *"){
    double scalar = 5;
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};
    CHECK(num_km*scalar == NumberWithUnits{scalar*2,"km"});
    CHECK(num_m*scalar == NumberWithUnits{scalar*2,"m"});
    CHECK(num_cm*scalar == NumberWithUnits{scalar*2,"cm"});
    CHECK(num_kg*scalar == NumberWithUnits{scalar*2,"kg"});
    CHECK(num_g*scalar == NumberWithUnits{scalar*2,"g"});
    CHECK(num_ton*scalar == NumberWithUnits{scalar*2,"ton"});
    CHECK(num_hour*scalar == NumberWithUnits{scalar*2,"hour"});
    CHECK(num_min*scalar == NumberWithUnits{scalar*2,"min"});
    CHECK(num_sec*scalar == NumberWithUnits{scalar*2,"sec"});
    CHECK(num_ILS*scalar == NumberWithUnits{scalar*2,"ILS"});
    CHECK(num_USD*scalar == NumberWithUnits{scalar*2,"USD"});
    CHECK(scalar*num_km == NumberWithUnits{scalar*2,"km"});
    CHECK(scalar*num_m == NumberWithUnits{scalar*2,"m"});
    CHECK(scalar*num_cm == NumberWithUnits{scalar*2,"cm"});
    CHECK(scalar*num_kg == NumberWithUnits{scalar*2,"kg"});
    CHECK(scalar*num_g == NumberWithUnits{scalar*2,"g"});
    CHECK(scalar*num_ton == NumberWithUnits{scalar*2,"ton"});
    CHECK(scalar*num_hour == NumberWithUnits{scalar*2,"hour"});
    CHECK(scalar*num_min == NumberWithUnits{scalar*2,"min"});
    CHECK(scalar*num_sec == NumberWithUnits{scalar*2,"sec"});
    CHECK(scalar*num_ILS == NumberWithUnits{scalar*2,"ILS"});
    CHECK(scalar*num_USD == NumberWithUnits{scalar*2,"USD"});
}

TEST_CASE("7:Testing comparison operators"){
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};   
    CHECK_GE(num_km,num_m);
    CHECK_GT(num_m,num_cm);
    CHECK_LE(num_cm,num_km);
    CHECK_GE(num_kg,num_g);
    CHECK_GT(num_ton,num_km);
    CHECK_LE(num_g,num_ton);
    CHECK_LT(num_ILS,num_USD);
    CHECK_GE(num_hour,num_min);
    CHECK_GT(num_min,num_sec);
    CHECK_LE(num_sec,num_hour);
    CHECK_LT(num_sec,num_min);
    CHECK_LT(num_ILS,num_ILS);
    CHECK_LT(num_g,num_g);
    
}
TEST_CASE("Tests for unlawful operations"){
    NumberWithUnits num_km{2, "km"};
    NumberWithUnits num_m{2, "m"};
    NumberWithUnits num_cm{2, "cm"};
    NumberWithUnits num_kg{2, "kg"};
    NumberWithUnits num_g{2, "g"};
    NumberWithUnits num_ton{2, "ton"};
    NumberWithUnits num_hour{2, "hour"};
    NumberWithUnits num_min{2, "min"};
    NumberWithUnits num_sec{2, "sec"};
    NumberWithUnits num_ILS{2, "ILS"};
    NumberWithUnits num_USD{2, "USD"};
    CHECK_THROWS(num_km+num_USD);
    CHECK_THROWS(num_m>num_g);
    CHECK_THROWS(num_cm-num_sec);
    CHECK_THROWS(num_kg+num_ILS);
    CHECK_THROWS(num_g!=num_cm);
    CHECK_THROWS(num_ton<=num_hour);

}