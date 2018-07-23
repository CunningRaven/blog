I record this piece of code just for self-references. If this makes you uncomfortable, just take it easy :)
```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <list>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <fstream>
#include <functional>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::vector;
using std::string;

template <class iterT, class stringT>
void print_table(iterT begin, iterT end, 
    std::ostream &ostrm, 
    stringT first_prefix, stringT afterward_prefix, stringT suffix)
{
  iterT it = begin;
  stringT prefix = first_prefix;
  if (begin == end) {
    return;
  }
  while (it != end) {
    ostrm << prefix << *it++;
    prefix = afterward_prefix;
  }
  ostrm << suffix;
}

void Getline(std::istream &istrm, string &str)
{
  if (getline(cin, str))
    return;
  else {
    cout << endl;
    exit(0);
  }
}

template <class iterT1, class iterT2, class predT>
iterT2 copy_if(iterT1 beg, iterT1 end, iterT2 dest, predT pred)
{
  while (beg != end) {
    if (pred(*beg)) {
      *dest++ = *beg;
    }
    beg++;
  }
  return dest;
}

template <class iterT1, class iterT2, class iterT3, class predT>
iterT2 copy_if_else(iterT1 beg, iterT1 end, iterT2 dest, iterT3 dest_else, predT pred)
{
  while (beg != end) {
    if (pred(*beg)) {
      *dest++ = *beg;
    } else {
      *dest_else++ = *beg;
    }
    beg++;
  }
  return dest;
}

int main(int argc, char *argv[])
{
  std::fstream oddf("/tmp/oddf", std::iostream::out | std::iostream::in | std::iostream::trunc);
  std::fstream evenf("/tmp/evenf", std::iostream::out | std::iostream::in | std::iostream::trunc);
  std::fstream::pos_type startpos = oddf.tellg(), startpos2 = evenf.tellg();
  std::ostream_iterator<int> oddi(oddf, " "), eveni(evenf, " ");
  string rubbish;
  std::istream_iterator<int> eof;
  while (1) {
    std::istream_iterator<int> ii(cin);
    copy_if_else(ii, eof, oddi, eveni, std::bind2nd(std::bit_and<int>(), 1));
    if (!cin.eof()) {
      cerr << "please input integers" << endl;
      cin.clear();
      cin >> rubbish;
      // cerr << "rubbish: " << rubbish << endl;
    } else {
      break;
    }
  }
  oddf.seekp(startpos);
  evenf.seekp(startpos2);
  std::istream_iterator<int> oddii(oddf), evenii(evenf);
  print_table(oddii, eof, cout, "odd: ", " ", "\n");
  print_table(evenii, eof, cout, "even: ", " ", "\n");

  return 0;
}
```
