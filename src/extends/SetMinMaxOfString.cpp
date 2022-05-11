#pragma once

#ifndef _SETMINMAXOFSTRING_
#define _SETMINMAXOFSTRING_

#include <iostream>
#include <string>
#include "./helpers.cpp"

void SetMinMaxOfString(string numberToSet, int& max, int& min) {
  string trimedString = Helpers::trim(numberToSet);

  if (trimedString == "")
    return;

  int number = stoi(trimedString);

  max = number > max ? number : max;
  min = number < min ? number : min;
}

#endif
