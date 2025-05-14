#include "class.h"
// begin of BigInt func
BigInt::BigInt(int x) {while (x) {push_back(x % 10); x /= 10;} process_digit(); }
BigInt::BigInt() { *this = BigInt(0);}
void BigInt::setY(int y) {
  this->y = y;
}
int BigInt::getY() const{
  return y;
}
void BigInt::process_digit() {
  long long carry = 0;
  for (int i = 0;i < size();i ++){
    carry += at(i);
    at(i) = carry % 10;
    carry /= 10;
  }
  while (carry) push_back(carry % 10), carry /= 10;
  while (size() > 1 && back() == 0) pop_back();
}

BigInt &BigInt::operator*=(const BigInt& W) {
  BigInt t = *this, ans = 0;
  for (int i = 0;i < W.size();i ++, t *= 10) {
    ans += t * W[i];
  }
  return *this = ans;
}

BigInt BigInt::operator*(const BigInt& W) {
  auto t = *this;
  return t *= W;
}

BigInt &BigInt::operator+=(const BigInt& W) {
  for (int i = 0;i < size() || i < W.size();i ++){
    if (i == size()) push_back(0);
    if (i < W.size()) at(i) += W[i];
  }
  process_digit();
  return *this;
}

BigInt BigInt::operator+(const BigInt &W) {
  BigInt ans(*this);
  ans += W;
  return ans;
}

BigInt &BigInt::operator+=(int x) {
  *this += BigInt(x);
  return *this;
}

BigInt &BigInt::operator*=(int x) {
  for (int i = 0;i < size();i ++){
    at(i) *= x;
  }
  process_digit();
  return *this;
}

BigInt &BigInt::operator/=(int x) {
  int carry = 0;
  for (int i = size() - 1;i >= 0;i --){
    carry = carry * 10 + at(i);
    at(i) = carry / x;
    carry %= x;
  }
  process_digit();
  return *this;
}

BigInt &BigInt::operator%=(int x) {
  int carry = 0;
  for (int i = size() - 1;i >= 0;i --){
    carry = carry * 10 + at(i);
    at(i) = carry / x;
    carry %= x;
  }
  *this = BigInt(carry);
  return *this;
}

BigInt BigInt::operator+(int x) {
  BigInt ans(*this);
  ans += x;
  return ans;
}

BigInt BigInt::operator*(int x) {
  BigInt ans(*this);
  ans *= x;
  return ans;
}

BigInt BigInt::operator/(int x) {
  BigInt ans(*this);
  ans /= x;
  return ans;
}

BigInt BigInt::operator%(int x) {
  BigInt ans(*this);
  ans %= x;
  return ans;
}

bool BigInt::operator<(const BigInt &W) const{
  if (size() != W.size()) return size() < W.size();
  for (int i = size() - 1; i >= 0; --i) {
    if (at(i) != W[i]) return at(i) < W[i];
  }
  return false; // They are equal
}

bool BigInt::operator>(const BigInt &W)  const{
  return W < (*this);
}

bool BigInt::operator<=(const BigInt &W) const{
  return !(*this > W);
}

bool BigInt::operator>=(const BigInt &W) const{
  return !(*this < W);
}

bool BigInt::operator==(const BigInt &W) const{
  return !(*this != W);
}

bool BigInt::operator!=(const BigInt &W) const{
  return *this < W || *this > W;
}

BigInt operator+(int x, const BigInt &W) {
  BigInt ans(W);
  ans += x;
  return ans;
}

BigInt operator*(int x, const BigInt &W) {
  BigInt ans(W);
  ans *= x;
  return ans;
}

std::istream &operator>>(std::istream &is, BigInt &W) {
  std::string s;
  is >> s;
  W = s;
  return is;
}

std::ostream &operator<<(std::ostream &os, const BigInt &W) {
  for (int i = W.size() - 1;i >= 0;i --) os << W[i];
  return os;
}

// end of BigInt func