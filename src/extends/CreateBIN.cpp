#pragma once

#ifndef _CREATEBIN_
#define _CREATEBIN_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateBIN(char* fname)
{
  ofstream fout(fname, ios::binary);
  char ch;
  string s;

  do {
    cin.get();
    cin.sync();

    cout << "enter line: "; getline(cin, s);

    s += '\n';

    for (unsigned i=0; i<s.length(); i++)
      fout.write((char*)&s[i], sizeof(s[i]));

    cout << "continue? (y/n): "; cin >> ch;
  } while (ch == 'y' || ch == 'Y');

  fout.close();

  cout << endl;
}

#endif
