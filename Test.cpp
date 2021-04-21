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

    CHECK(num_g + NumberWithUnits {1, "km"} == NumberWithUnits {2 + 1*100*1000, "cm"});
    CHECK(num_g + NumberWithUnits {1, "km"} == NumberWithUnits {2 + 1*100*1000, "cm"});

    CHECK(num_ton + NumberWithUnits {1, "km"} == NumberWithUnits {2 + 1*100*1000, "cm"});
    CHECK(num_ton + NumberWithUnits {1, "km"} == NumberWithUnits {2 + 1*100*1000, "cm"});
    
}