#ifndef SELECT_NOT_HPP
#define SELECT_NOT_HPP

#include "select.hpp"
#include "spreadsheet.hpp"

using namespace std;

class Select_Not : public Select{
	private:
		Select* s1;
	public:
		Select_Not(Select* s){
			s1 = s;
		}
		
		~Select_Not(){
			delete s1;
		}
		virtual bool select(const Spreadsheet* sheet, int row) const {
			return !(s1->select(sheet, row));
			
		}
};

#endif
