#pragma once
 
#ifndef _PRINTBIN_
#define _PRINTBIN_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintBIN(char* fname)
{
  ifstream fin(fname, ios::binary);
  string s;
  char ch;

  cout << endl;
  while (fin.read((char*)&ch, sizeof(ch)))
  {
    if (ch == '\n') {
      cout << s << endl;
      s = "";
    } else {
      s += ch;
    }
  }
  cout << endl;
}

#endif
