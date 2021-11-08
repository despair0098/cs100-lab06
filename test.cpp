#include "spreadsheet.hpp"
#include "select.hpp"
#include "Select_Contains.hpp"
#include "Select_Not.hpp"

#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

TEST(Select_Contains, test)
{
	Spreadsheet sheet;
	std::stringstream s;
	sheet.set_selction(new Select_Contains(&sheet, "Last", "Connors"));
	sheet.set_column_names({"First", "Last", "Age", "Major"});
	sheet.add_row({"Amanda","Andrews","22","business"});
    	sheet.add_row({"Brian","Becker","21","computer science"});
    	sheet.add_row({"Carol","Conners","21","computer science"});
	sheet.print_selection(std::cout);
	EXPECT_EQ(sheet.print_selection(s.str()), "Carol Connors 21 computer science");
}
	
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
