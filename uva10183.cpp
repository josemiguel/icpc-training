#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct BigInt
{
  BigInt(int v = 0) : start(max_digits)
  {
    bzero(digits, max_digits);
    assign(v);
  }
  BigInt(char const *v) : start(max_digits)
  {
    bzero(digits, max_digits);
    assign(v);
  }
  void assign(int v)
  {
    start = max_digits;
    for (; v != 0; v /= 10) digits[--start] = v % 10; 
  }
  void assign(char const *v)
  {
    start = max_digits - strlen(v);
    for (int i = start; i < max_digits; ++i)
      digits[i] = *v++ - '0';
    remove_leading_zero();
  }
  void convert(int& v) const
  {
    v = 0;
    for (int i = start; i < max_digits; ++i, v *= 10) v += digits[i]; 
  }
  void convert(char *v) const
  {
    for (int i = start; i < max_digits; ++i)
      *v++ = digits[i] + '0';
    *v = '\0';
  }
  BigInt& operator+=(BigInt const& other)
  {
    start = min(start, other.start) - 1;
    for (int i = max_digits - 1, carry = 0; i >= start; --i) {
      int s = digits[i] + other.digits[i] + carry;
      digits[i] = s % 10;
      carry = s / 10;
    }
    remove_leading_zero();
    return *this;
  }
  BigInt operator+(BigInt const& other) const
  {
    BigInt tmp(*this);
    tmp += other;
    return tmp;
  }
  bool operator<(BigInt const& other) const
  {
    if (start > other.start) return true;
    else if (start < other.start) return false; 
    return memcmp(digits + start, other.digits + start, max_digits - start) < 0;
  }
  static int const max_digits = 500;
  char digits[max_digits];
  int start;
private:
  void remove_leading_zero()
  {
    for (; digits[start] == 0 && start < max_digits; ++start) {}
  } 
};
    
inline istream& operator>>(istream& is, BigInt& n)
{
	char buf[BigInt::max_digits+1];
	is >> buf;
	n.assign(buf);
	return is;
}
inline ostream& operator<<(ostream& os, BigInt const& n)
{
	char buf[BigInt::max_digits+1];
	n.convert(buf);
	os << buf;
	return os;
}




BigInt F[510];


int main(){
	F[0] = F[1] =1;
	for(int i = 2; i <= 500; i++) F[i] = F[i-1] + F[i-2];
	BigInt X,Y;
	while(cin>>X>>Y){
		
		BigInt *lo = lower_bound(F,F+500,X);
		BigInt *hi = upper_bound(F,F+500,Y);
		cout<<(hi - lo)<<endl;
	}	
	return 0;
}
