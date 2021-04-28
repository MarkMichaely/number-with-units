/**
 * cpp file for NumberWithUnits exercise.
 * the NumberWithUnits class represents a real number with a type of measureable unit associated with.
 * for example: kg, or sec.
 * this class is used for measurment and arithmetic purposes between different number of same or different
 * units when those units are compareable, and gives us the ability to add them correctly.
 * 
 * sources used:
 * https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
 * https://en.cppreference.com/w/cpp/language/operators
 * https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/ 
 * Author: Mark Michaely
 * Since : 2021-04
 */

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;
const double EPS = 0.0001;

namespace ariel{

  static map<string, map<string, double>> unit_table;

  NumberWithUnits::NumberWithUnits (double amount, const std::string& unit_type)
  {
    if(unit_table.count(unit_type)==0){
        throw invalid_argument {"No such unit in units table"};
    }
    this->amount = amount;
    this->unit_type = unit_type;
  }

  NumberWithUnits::~NumberWithUnits(){

  }
  double convert_unit(double val, const string& from, const string& to){
    if (from == to){
      return val;
    }
    try {
      val *= unit_table.at(from).at(to);
    }
    catch (std::out_of_range& e){
      throw invalid_argument{"Units do not match - ["+from+"] cannot be converted to ["+to+"]"};  
    }
    return val;
  }

  void NumberWithUnits::read_units(std::ifstream& file){
    string buff;
    string unit1;
    string unit2;
    double num1 = 0;
    double num2 = 0;
    while (file >> num1 >> unit1 >> buff >> num2 >> unit2){
      unit_table[unit1][unit2] = num2;
      unit_table[unit2][unit1] = 1/num2;

      for (auto &pair : unit_table[unit2]){
        double w = unit_table[unit1][unit2] * pair.second;
        unit_table[unit1][pair.first] = w;
        unit_table[pair.first][unit1] = 1/w;
      }
      for (auto &pair : unit_table[unit1]){
        double w = unit_table[unit2][unit1] * pair.second;
        unit_table[unit2][pair.first] = w;
        unit_table[pair.first][unit2] = 1/w;
      }

    }
  }
  std::string NumberWithUnits::get_unit() const{
    return unit_type;
  }
  double NumberWithUnits::get_amount() const{
    return amount;
  }

  NumberWithUnits NumberWithUnits::operator+(){
    NumberWithUnits num_wu(this->amount, this->unit_type);
    return num_wu;
  }
  NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& other_num){
    double converted_amount = convert_unit(other_num.amount, other_num.unit_type, this->unit_type);
    NumberWithUnits num_wu(this->amount + converted_amount, this->unit_type);
    return num_wu;
  }
  
  NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other_num){
    *this = *this + other_num;
    return *this;
  }
  NumberWithUnits NumberWithUnits::operator-(){
    NumberWithUnits num_wu(-this->amount, this->unit_type);
    return num_wu;
  }
  
  NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& other_num){
    double converted_amount = convert_unit(other_num.amount, other_num.unit_type, this->unit_type);
    NumberWithUnits num_wu(this->amount - converted_amount, this->unit_type);
    return num_wu;
  }
  NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other_num){
    *this = *this - other_num;
    return *this;
  }
      
  bool operator>(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    double delta = left_num.get_amount() - convert_unit(right_num.get_amount(), right_num.get_unit(), left_num.get_unit());
    return (delta> EPS);
  }
  bool operator>=(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return !(left_num < right_num);
  }
  
  bool operator<(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return (right_num > left_num);
  }
  
  bool operator<=(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return !(left_num>right_num);
  }
  
  bool operator==(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    double delta = left_num.get_amount() - convert_unit(right_num.get_amount(), right_num.get_unit(), left_num.get_unit());
    return (delta<=EPS && delta>=-EPS);
  }
  
  bool operator!=(const NumberWithUnits& left_num, const NumberWithUnits& right_num){
    return !(left_num==right_num);
  }
  
      
  NumberWithUnits& NumberWithUnits::operator++(){
    ++(this->amount);
    return *this;
  }
  NumberWithUnits& NumberWithUnits::operator--(){
    --(this->amount);
    return *this;
  }
  NumberWithUnits NumberWithUnits::operator++(int){
    NumberWithUnits old(this->amount,this->unit_type);
    operator++();
    return old;
  }
  NumberWithUnits NumberWithUnits::operator--(int){
    NumberWithUnits old(this->amount,this->unit_type);
    operator--();
    return old;
  } 

  NumberWithUnits operator*(const NumberWithUnits& obj, const double num){
      return NumberWithUnits(obj.get_amount()*num, obj.get_unit());
  }
  NumberWithUnits operator*(const double num, const NumberWithUnits& obj){
      return NumberWithUnits(obj.get_amount()*num, obj.get_unit());
  }

  ostream& operator<<(std::ostream& os, const NumberWithUnits& num){
    os << num.get_amount() << "[" << num.get_unit() << "]";
    return os;
  }
  istream& operator>>(std::istream& is, NumberWithUnits& num){
      double val =0;
      string buff;
      cout << "enter amount";
      is >> val;
      cout << "enter unit type";
      getline(is,buff,']');
      buff.erase(remove(buff.begin(),buff.end(), ' '), buff.end());
      buff = buff.substr(1,buff.size()-1);
      num = NumberWithUnits{val,buff};
      return is;
  }
}

