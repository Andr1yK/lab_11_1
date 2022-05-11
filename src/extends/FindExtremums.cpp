#pragma once

#ifndef _FINDEXTREMUMS_
#define _FINDEXTREMUMS_

#include <fstream>
#include <string>
#include "./SetMinMaxOfString.cpp"
#include "./extremums.hpp"
#include "./helpers.cpp"

Extremums FindExtremums(char* fname) {
  ifstream fin(fname, ios::binary);

  char ch;
  string s;
  Extremums extremums = {INT_MIN, INT_MAX};

  int number;

  while (fin.read((char*)&ch, sizeof(ch)))
  {
    do {
      if (ch == ' ' || ch == '\n') {
        SetMinMaxOfString(s, extremums.max, extremums.min);

        s = "";
      }

      s += ch;
    } while (fin.read((char*)&ch, sizeof(ch)) && ch != '\n');

    SetMinMaxOfString(s, extremums.max, extremums.min);

    s = "";
  }

  fin.close();

  return extremums;
}

#endif
