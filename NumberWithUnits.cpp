/**
 * cpp file for NumberWithUnits exercise.
 * the NumberWithUnits class represents a real number with a type of measureable unit associated with.
 * for example: kg, or sec.
 * this class is used for measurment and arithmetic purposes between different number of same or different
 * units when those units are compareable, and gives us the ability to add them correctly.
 * 
 * sources used:
 * https://en.cppreference.com/w/cpp/language/operators * Author: Mark Michaely
 * Since : 2021-04
 */

#include <string>
#include <iostream>
#include <fstream>
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;

namespace ariel{

  NumberWithUnits::NumberWithUnits (double amount, const std::string& unit_type)
  {
    this->amount = amount;
    this->unit_type = unit_type;
  }
  void NumberWithUnits::read_units(std::ifstream& file){

  }
  std::string NumberWithUnits::get_unit(){
    return unit_type;
  }
  double NumberWithUnits::get_amount(){
    return amount;
  }

  NumberWithUnits NumberWithUnits::operator+(){
    return *this;
  }
  NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& other_num){
    return *this;
  }
  NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other_num){
    return *this;
  }
  NumberWithUnits NumberWithUnits::operator-(){
    return *this;
  }
  NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& other_num){
    return *this;
  }
  NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other_num){
    return *this;
  }
      
  bool operator>(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return false;
  }
  bool operator>=(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return false;
  }
  
  bool operator<(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return false;
  }
  
  bool operator<=(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return false;
  }
  
  bool operator==(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return false;
  }
  
  bool operator!=(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return false;
  }
  
      
  NumberWithUnits& NumberWithUnits::operator++(){
    return *this;
  }
  NumberWithUnits& NumberWithUnits::operator--(){
    return *this;
  }
  NumberWithUnits NumberWithUnits::operator++(int){
    return *this;
  }
  NumberWithUnits NumberWithUnits::operator--(int){
      return *this;
  } 

  NumberWithUnits operator*(NumberWithUnits& obj, double num){
      return obj;
  }
  NumberWithUnits operator*(double num, NumberWithUnits& obj){
      return obj;
  }

  ostream& operator<<(std::ostream& os, const NumberWithUnits& num){
   // os << num.get_amount() << "[" << num.get_unit() << "]";
    return os;
  }
  istream& operator>>(std::istream& is, NumberWithUnits& num){
     // std:string str;
     // is >> num.get_amount() >> str >> num.get_unit();
      return is;
  }
}

