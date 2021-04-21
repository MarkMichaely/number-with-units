#pragma once
/**
 * hpp file for NumberWithUnits exercise.
 * 
 * sources used:
 * https://en.cppreference.com/w/cpp/language/operators * Author: Mark Michaely
 * Since : 2021-04
 */
#include <string>

namespace ariel {
  /*class representing a number with a unit type ie kg, ton, sec and etc.*/

  class NumberWithUnits{

    private:
      double amount;
      std::string unit_type;

    public:
      NumberWithUnits(double amount, const std::string& unit_type);
      static void read_units(std::ifstream& file);
      std::string get_unit();
      double get_amount();
      NumberWithUnits operator+();
      NumberWithUnits operator+(const NumberWithUnits& other_num);
      NumberWithUnits& operator+=(const NumberWithUnits& other_num);
      NumberWithUnits operator-();
      NumberWithUnits operator-(const NumberWithUnits& other_num);
      NumberWithUnits& operator-=(const NumberWithUnits& other_num);
      
      NumberWithUnits& operator++();
      NumberWithUnits& operator--();
      NumberWithUnits operator++(int);
      NumberWithUnits operator--(int);

  };
  NumberWithUnits operator*(NumberWithUnits& obj, double num);
  NumberWithUnits operator*(double num, NumberWithUnits& obj);

  bool operator>(const NumberWithUnits& left_num, const NumberWithUnits& right_num);
  bool operator>=(const NumberWithUnits& left_num, const NumberWithUnits& right_num);
  bool operator<(const NumberWithUnits& left_num, const NumberWithUnits& right_num);
  bool operator<=(const NumberWithUnits& left_num, const NumberWithUnits& right_num);
  bool operator==(const NumberWithUnits& left_num, const NumberWithUnits& right_num);
  bool operator!=(const NumberWithUnits& left_num, const NumberWithUnits& right_num);
  
  std::ostream& operator<<(std::ostream& os, const NumberWithUnits& num);
  std::istream& operator>>(std::istream& is, NumberWithUnits& num);
}
