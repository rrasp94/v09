#pragma once

#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <map>
#include <set>

namespace vsite::oop::v9
{
    void fill_vector(std::vector<int>& v, int n);
    void remove_element(std::vector<int>& v, int index);
    void input_element(std::vector<std::string>& v, size_t pos, const std::string& value);
    int list_nth_element(const std::list<int>& lst, size_t n);
    void list_sort_desc(std::list<int>& lst);
    unsigned unique_numbers(std::istream& input);

    class word_frequency {
        std::map<std::string, unsigned> word_count; 
    public:
        word_frequency(std::istream& input);
        unsigned count() const;
        unsigned frequency(const std::string& word) const;
    };
}


