#include "app.h"

namespace vsite::oop::v9
{
    void fill_vector(std::vector<int>& v, int n) {
        for (int i = 0; i < n; ++i) {
            v.push_back(i * i);
        }
    }

    void remove_element(std::vector<int>& v, int index) {
        if (index >= 0 && static_cast<size_t>(index) < v.size()) {
            for (size_t i = index; i < v.size() - 1; ++i) {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }

    void input_element(std::vector<std::string>& v, size_t pos, const std::string& value) {
        v.resize(v.size() + 1);
        for (size_t i = v.size() - 1; i > pos; --i) {
            v[i] = v[i - 1];
        }
        v[pos] = value;
    }

    int list_nth_element(const std::list<int>& lst, size_t n) {
        auto it = lst.begin();
        for (size_t i = 0; i < n; ++i) {
            ++it;
        }
        return *it;
    }

    void list_sort_desc(std::list<int>& lst) {
        for (auto it1 = lst.begin(); it1 != lst.end(); ++it1) {
            for (auto it2 = std::next(it1); it2 != lst.end(); ++it2) {
                if (*it1 < *it2) {
                    int temp = *it1;
                    *it1 = *it2;
                    *it2 = temp;
                }
            }
        }
    }

    unsigned unique_numbers(std::istream& input) {
        int numbers[1000]; 
        size_t size = 0;

        int number;
        while (input >> number) {
            bool found = false;
            for (size_t i = 0; i < size; ++i) {
                if (numbers[i] == number) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                numbers[size] = number;
                ++size;
            }
        }
        return size;
    }

    word_frequency::word_frequency(std::istream& input) {
        std::string word;
        while (input >> word) {
            std::string clean_word;
            for (char c : word) {
                if (std::isalpha(static_cast<unsigned char>(c))) {
                    if (std::isupper(static_cast<unsigned char>(c))) {
                        clean_word += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
                    }
                    else {
                        clean_word += c;
                    }
                }
            }
            bool found = false;
            for (auto& pair : freq) {
                if (pair.first == clean_word) {
                    ++pair.second;
                    found = true;
                    break;
                }
            }
            if (!found) {
                freq.push_back(std::make_pair(clean_word, 1));
            }
        }
    }

    unsigned word_frequency::count() const {
        return freq.size();
    }

    unsigned word_frequency::frequency(const std::string& word) const {
        for (const auto& pair : freq) {
            if (pair.first == word) {
                return pair.second;
            }
        }
        return 0;
    }
}

//workflow