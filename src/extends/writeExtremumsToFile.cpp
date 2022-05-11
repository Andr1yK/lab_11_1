#pragma once

#ifndef _WRITEEXTREMUMSTOFILE_
#define _WRITEEXTREMUMSTOFILE_

#include "./extremums.hpp"
#include <iostream>
#include <fstream>
#include <string>

void writeExtremumsToFile(char* fname, Extremums extremums) {
  ofstream fout(fname, ios::binary);
  char ch;
  string s = "max: " + to_string(extremums.max) + "\nmin: " + to_string(extremums.min);

  cout << s;

  for (unsigned i=0; i<s.length(); i++)
    fout.write((char*)&s[i], sizeof(s[i]));

  fout.close();

  cout << endl;
}

#endif
