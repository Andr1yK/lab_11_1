#include <iostream>
#include "./extends/CreateBIN.cpp"
#include "./extends/PrintBIN.cpp"
#include "./extends/FindExtremums.cpp"
#include "./extends/writeExtremumsToFile.cpp"

using namespace std;

int main()
{
  char fname[100] = "test";
  cout << "enter file name 1: "; cin >> fname;

  CreateBIN(fname);
  PrintBIN(fname);

  char res_fname[100] = "test_res";
  cout << "enter file name 2: "; cin >> res_fname;

  writeExtremumsToFile(res_fname, FindExtremums(fname));

  return 0;
}