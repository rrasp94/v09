#include "app.h"
#include <algorithm>
#include <map>
#include <cctype>

namespace vsite::oop::v9
{
    void fill_vector(std::vector<int>& v, int n) {
        for (int i = 0; i < n; ++i) {
            v.push_back(i * i);
        }
    }

    void remove_element(std::vector<int>& v, int index) {
        if (index >= 0 && static_cast<size_t>(index) < v.size()) {
            v.erase(v.begin() + index);
        }
    }

    void input_element(std::vector<std::string>& v, size_t pos, const std::string& value) {
        if (pos <= v.size()) {
            v.insert(v.begin() + pos, value);
        }
    }

    int list_nth_element(const std::list<int>& lst, size_t n) {
        if (n >= lst.size()) {
            throw std::out_of_range("Index out of range");
        }
        auto it = std::next(lst.begin(), n);
        return *it;
    }

    void list_sort_desc(std::list<int>& lst) {
        lst.sort(std::greater<int>());
    }

    unsigned unique_numbers(std::istream& input) {
        std::set<int> numbers;  
        int number;

        while (input >> number) {
            numbers.insert(number);  
        }
        return numbers.size();
    }

    word_frequency::word_frequency(std::istream& input) {
        std::string word;

        while (input >> word) {
            for (char& c : word) {
                c = std::tolower(c);
            }
            word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
                return !std::isalpha(static_cast<unsigned char>(c));
                }), word.end());

            if (!word.empty()) {
                ++word_count[word];  
            }
        }
    }

    unsigned word_frequency::count() const {
        return word_count.size();  
    }

    unsigned word_frequency::frequency(const std::string& word) const {
        auto it = word_count.find(word);
        return (it != word_count.end()) ? it->second : 0;  
    }
}

