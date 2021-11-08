#ifndef SELECT_OR_HPP
#define SELECT_OR_HPP

#include "select.hpp"
#include "spreadsheet.hpp"

using namespace std;

class Select_Or: public Select
{
private:
    Select* s1;
    Select* s2;
public:
    Select_Or(Select* select1, Select* select2)
    {
        s1 = select1;
	s2 = select2;
    }
    ~Select_Or(){
	delete s1;
	delete s2;
    }
    
    virtual bool select(const Spreadsheet* sheet, int row) const
    {    
	return (s1->select(sheet, row) || s2->select(sheet, row));
    }
};

#endif 
