#include <gtest/gtest.h>

#include "../src/extends/SetMinMaxOfString.cpp"
#include "../src/extends/FindExtremums.cpp"
#include "../src/extends/writeExtremumsToFile.cpp"

#include "../src/extends/extremums.hpp"

struct WorkWithFile : public testing::Test
{
  char input_fname[30] = "unittests.temp.txt";
  char result_fname[30] = "unittests_result.temp.txt";

  ofstream fout;
  Extremums expectedExtremums;

  string rawData = "\
1 20 -1 432  423 4             533\n\
\n\
\n\
\n\
                  -61\n\
423 4 4 4 4 4  4 4 4 3  3      3   3   3\n\
65  5 5 5 5 0\n\
0\n\
";

  string resultLines[2] = {
    "max: 533",
    "min: -61",
  };

  void SetUp() override {
    expectedExtremums.max = 533;
    expectedExtremums.min = -61;

    fout.open(input_fname);

    fout << rawData;

    fout.close();
  }

  void TearDown() override {
    remove(input_fname);
    remove(result_fname);
  }
};

TEST_F(WorkWithFile, FindExtremums) {
  Extremums result = FindExtremums(input_fname);

  EXPECT_EQ(result.min, expectedExtremums.min);
  EXPECT_EQ(result.max, expectedExtremums.max);
}

TEST(WorkWithoutFile, SetMinMaxOfString) {
  int min = 0;
  int max = 0;

  SetMinMaxOfString("1", max, min);
  ASSERT_EQ(max, 1);
  ASSERT_EQ(min, 0);

  SetMinMaxOfString("100", max, min);
  ASSERT_EQ(max, 100);
  ASSERT_EQ(min, 0);
  
  SetMinMaxOfString("-100", max, min);

  ASSERT_EQ(max, 100);
  ASSERT_EQ(min, -100);
}

TEST_F(WorkWithFile, WriteResult) {
  ifstream fin;
  string s;

  writeExtremumsToFile(result_fname, expectedExtremums);

  fin.open(result_fname);

  for (int i = 0; getline(fin, s); i++) {
    EXPECT_EQ(s, resultLines[i]);
  }
}
