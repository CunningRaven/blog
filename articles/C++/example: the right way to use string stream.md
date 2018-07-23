I record this piece of code just for self-references. If this makes you uncomfortable, just take it easy :)
```C++
/* replace_ss.cc: Generate a sequence of random nubers and then do a substitution. Leave the user to point out the position  where the replacement would start, the number to be replaced, the one by which the former is replaced. */
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

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::vector;
using std::string;

#define RDNBR_RANGE 10

void Getline(std::istream &istrm, string &str)
{
  if (getline(cin, str))
    return;
  else {
    cout << endl;
    exit(0);
  }
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  std::list<int> vi;
  for (int i = 0; i < 20; i++)
    vi.push_back(rand() % RDNBR_RANGE);
  std::ostream_iterator<int> oi(cout, " ");
  std::copy(vi.begin(), vi.end(), oi);
  cout << endl;
  std::list<int>::iterator viter;
  int to_rp, rp_by;
  int i;
  string str;
  std::stringstream ss;
  while (1) {
    cout << "Enter one of the above numbers from which the replacements will start: " << std::flush;
    Getline(cin, str);
    ss.seekg(0, std::stringstream::beg);
    ss.str(str);
    if (ss >> i) {
      viter = find(vi.begin(), vi.end(), i);
      if (viter != vi.end())
        break;
      else {
        cerr << i << " not in the number sequence" << endl;
      }
    } else {
        cerr << "please enter an integer included in the previous number sequence" << endl;
        ss.clear();
    }
  }
  while (1) {
    cout << "Input the number to be replaced: " << std::flush;
    Getline(cin, str);
    ss.seekg(0, std::stringstream::beg);
    ss.str(str);
    if (ss >> i) {
      to_rp = i;
      break;
    } else {
      cerr << "please enter an integer" << endl;
      ss.clear();
    }
  }
  while(1) {
    cout << "Input the number by which " << to_rp << " is replaced: " << std::flush;
    Getline(cin, str);
    ss.seekg(0, std::stringstream::beg);
    ss.str(str);
    if (ss >> i) {
      rp_by = i;
      break;
    } else {
      cerr << "please enter an integer" << endl;
      ss.clear();
    }
  }
  replace(viter, vi.end(), to_rp, rp_by);
  copy(vi.begin(), vi.end(), oi);
  cout << endl;

  return 0;
}
```

