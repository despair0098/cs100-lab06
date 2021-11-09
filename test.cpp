#include "spreadsheet.hpp"
#include "select.hpp"
#include "Select_Contains.hpp"
#include "Select_Not.hpp"

#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

using namespace std;

TEST(Select_Contains, test)
{
	Spreadsheet sheet;
	stringstream s;
	std::stringstream s;
	
	sheet.set_column_names({"First", "Last", "Age", "Major"});
	sheet.add_row({"Amanda","Andrews","22","business"});
    	sheet.add_row({"Brian","Becker","21","computer science"});
    	sheet.add_row({"Carol","Conners","21","computer science"});
	sheet.set_selection(new Select_Contains(&sheet, "Last", "Connors"));
	sheet.print_selection(s);
	EXPECT_EQ(s.str(), "Carol Connors 21 computer science");
	sheet.set_selection(new Select_Contains(&sheet, "Last", "Conners"));
	sheet.print_selection(s);
	EXPECT_EQ("Carol Conners 21 computer science \n", s.str());
}

TEST(Select_Contains, test1)
{
        Spreadsheet sheet;
        std::stringstream s;

        sheet.set_column_names({"First", "Last", "Age", "Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
        sheet.add_row({"Brian","Becker","21","computer science"});
        sheet.add_row({"Carol","Conners","21","computer science"});
        sheet.set_selection(new Select_Contains(&sheet, "Last", ""));
        sheet.print_selection(s);
        EXPECT_EQ("Amanda Andrews 22 business \nBrian Becker 21 computer science \nCarol Conners 21 computer science \n", s.str());
}

TEST(Select_Contains, test2)
{
	Spreadsheet sheet;
        std::stringstream s;

        sheet.set_column_names({"First", "Last", "Age", "Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
        sheet.add_row({"Brian","Becker","21","computer science"});
        sheet.add_row({"Carol","Conners","21","computer science"});
        sheet.set_selection(new Select_Contains(&sheet, "First", "an"));
        sheet.print_selection(s);
	EXPECT_EQ("Amanda Andrews 22 business \nBrian Becker 21 computer science \n", s.str());
}

TEST(Select_Contains, test3)
{
        Spreadsheet sheet;
        std::stringstream s;

        sheet.set_column_names({"First", "Last", "Age", "Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
        sheet.add_row({"Brian","Becker","21","computer science"});
        sheet.add_row({"Carol","Conners","21","computer science"});
        sheet.set_selection(new Select_Contains(&sheet, "First", "carol"));
        sheet.print_selection(s);
	
	EXPECT_EQ("", s.str());
}
	
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
