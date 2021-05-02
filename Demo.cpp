/**
 * Demo file for the exercise on numbers with units
 *
 * @author Mark Michaely
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

int main() {
  ifstream units_file{"units.txt"};
  NumberWithUnits::read_units(units_file);

  NumberWithUnits Hyundai_I30{1.495, "ton"};   // 1.495 ton
  NumberWithUnits Yoni{65,"kg"};
  NumberWithUnits Avi{88,"kg"};
  NumberWithUnits bag_of_chips{50,"g"};
  cout << "Yoni weighs " << Yoni << " and " << Yoni+Avi << " if he holds avi on his shoulders" <<endl;
  if ((Avi+Yoni) == (Yoni+Avi)){
    cout << "it's the same weight if Avi holds Yoni"<<endl;
  } 
  else {
    cout << "somehow it's not the same weight and it's wierd" <<endl;
  }
  cout <<"Hyundai_I30 weighs " << Hyundai_I30 << endl;
  Hyundai_I30+=Yoni;
  Hyundai_I30+=Avi;
  cout <<"If Avi and Yoni sit in the car it weighs " << Hyundai_I30 << endl;
  Hyundai_I30-=Avi;
  NumberWithUnits grocey_bag = 5*bag_of_chips;
  Hyundai_I30+=grocey_bag;
  cout <<"Avi left but brought some chips and the car weighs " << Hyundai_I30 << endl;
  if (bag_of_chips*5 != grocey_bag){
    cout << "something went wrong here" <<endl;
  }
  cout << "the price of I30 is " << NumberWithUnits{45000, "USD"}
   << "and if one has 90,000 ils in the bank he only needs " 
   << NumberWithUnits{45000, "USD"}-NumberWithUnits{90000, "ILS"} << endl;

   istringstream yoni_height{"1.88[m]"};
   istringstream avi_height{"170[cm]"};
   yoni_height >> Yoni;
   avi_height >> Avi;
   cout << "Yoni is " <<Yoni<< " and Avi is " << Avi << endl;
   cout << "Avi on Yoni shoulders is " << Yoni + Avi 
   << " which is the same as Yoni on Avi's shoulders " 
   << Avi+Yoni<<endl;
   if (Avi > Yoni){
     cout << " Avi is taller" << endl;
   }

   else {
     cout << " Yoni is taller" << endl;
   }

   return 0;
}
