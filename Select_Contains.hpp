#ifndef SELECT_CONTAINS_HPP
#define SELECT_CONTAINS_HPP

#include "select.hpp"

using namespace std;

class Select_Contains : public Select{
        private:
                const Spreadsheet* s;
                string n;
                string t;
        public:
                Select_Contains(const Spreadsheet* sheet, const string& name, string& target){
                        s = sheet;
                        n = name;
                        t = target;
                }

                virtual bool select(const Spreadsheet* sheet, int row) const {
                        int column = sheet->get_column_by_name(n);
                        return (sheet->cell_data(row, column).find(t));

                }
};
#endif 
