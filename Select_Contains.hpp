#ifndef SELECT_CONTAINS_HPP
#define SELECT_CONTAINS_HPP

#include "select.hpp"
#include "spreadsheet.hpp"
#include <iostream>

using namespace std;

class Select_Contains: public Select
{
private:
    const Spreadsheet* s;
    string n; 
    string w;
public:
    Select_Contains(const Spreadsheet* sheet, const string& name, string word)
    {
        s = sheet;
	n = name;
	w = word;
    }
    
    virtual bool select(const Spreadsheet* sheet, int row) const
    {    
	int column = sheet->get_column_by_name(n);
	if(column == -1){
		cout << "Could not find the column" << endl;
		return false;		
	}
	return (sheet->cell_data(row, column).find(w) != string::npos);
    }
};

#endif 
