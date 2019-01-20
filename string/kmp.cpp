#include <iostream>
#include <string>
#include <vector>
using namespace std;

// To save key stroke p -> pattern
vector<int> computeLPS(string p) {
  cout<<"In compute"<<endl;
  int i = 1, len = 0;

  vector<int> lps;
  lps.push_back(0);
  while (i < p.length()) {
    cout<<i<<endl;
    if(p[i] == p[len]) {
      len++;
      lps.push_back(len);
      i++;
    } else {
      if(len == 0) {
        lps.push_back(0);
        i++;
      } else {
        len = lps[len-1];
      }
    }
  }

  return lps;
}

bool KMPSearch(string s, string p) {
  vector<int> lps = computeLPS(p);
  cout<<"after lps"<<endl;
  int i = 0, j = 0;
  while (i < s.length()) {
    if(s[i] == p[j]) {
      j++;
      i++;
    } else if (j > 0){
      j = lps[j-1];
    } else if (i < s.length()) {
      i++;
    }
    if(j == p.length()) {
      cout<<"Found pattern at index "<<i - j<<endl;
      return true;
    }
  }
  return false;
}

int main() {
  string s = "ABCDEFADFWGDSG";
  string p = "AD";
  cout<<KMPSearch(s, p)<<endl;
}
