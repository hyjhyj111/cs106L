#pragma once
#include <iostream>
#include <vector>
class BigInt : public std::vector<int>{
 public:
  BigInt(int) ;
  BigInt();
  BigInt(std::string s) {for (int i = s.size() - 1;i >= 0;i --) push_back(s[i] - '0'); process_digit();}


  BigInt& operator+=(const BigInt&);
  BigInt operator+(const BigInt&);
  BigInt& operator*=(const BigInt&);
  BigInt operator*(const BigInt&);

  BigInt& operator+=(int);
  BigInt& operator*=(int);
  BigInt& operator/=(int);
  BigInt& operator%=(int);

  BigInt operator+(int);
  BigInt operator*(int);
  BigInt operator/(int);
  BigInt operator%(int);

  bool operator <(const BigInt&)const;
  bool operator >(const BigInt&)const;
  bool operator <=(const BigInt&)const;
  bool operator >=(const BigInt&)const;
  bool operator ==(const BigInt&)const;
  bool operator !=(const BigInt&)const;

  friend BigInt operator+(int, const BigInt&);
  friend BigInt operator*(int, const BigInt&);
  friend std::istream &operator >>(std::istream &, BigInt &);
  friend std::ostream &operator <<(std::ostream &, const BigInt &);
  void setY(int y) ;
  int getY() const;
 private:
  void process_digit();
  int y = 0;
};