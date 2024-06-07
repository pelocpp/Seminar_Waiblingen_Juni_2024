#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <optional>
#include <functional>


// Vorname     "Hans"
// Nachname    "Meier"
// Telefonnummer

// Strategie:  Mehreren Informationen: Schlüssel

// A) "Hans Meier" // size_t


class IPhonebook
{
    virtual bool insert(const std::string& first, const std::string& last, size_t number) = 0;

    virtual bool search(const std::string& first, const std::string& last, size_t& number) = 0;

    virtual std::optional<size_t> searchEx(const std::string& first, const std::string& last) = 0;

    virtual void print() = 0;
    virtual void printEx() = 0;
    virtual void printExEx() = 0;
    virtual void printExExEx() = 0;
    virtual void printExExExEx() = 0;
};


// ============================================

using PhonebookDataType = std::unordered_map<std::string, size_t>;

using PhonebookIteratorDataType = PhonebookDataType::iterator;

template <typename T, typename U>
using PhonebookDataTypeEx = std::unordered_map<T, U>;

class Phonebook : public IPhonebook
{
private:
    // std::unordered_map<std::string, size_t> m_data;
    PhonebookDataType m_data;
    size_t            m_count;

    // PhonebookDataTypeEx<std::string, size_t> m_data2;

public:
    virtual bool insert(const std::string& first, const std::string& last, size_t number) override
    {
        // create key from first and last
        std::string key = first + " " + last;

        std::pair<std::string, size_t> entry(key, number);

        std::pair< std::unordered_map<std::string, size_t>::iterator, bool > result 
            = m_data.insert(entry);

        //std::pair< PhonebookIteratorDataType, bool > result
        //    = m_data.insert(entry);

        // auto result = m_data.insert(entry);  // Type Deduction // Typableitung

        return result.second;
    }

    virtual bool search(const std::string& first, const std::string& last, size_t& number) override
    {
        std::string key = first + " " + last;

        std::unordered_map<std::string, size_t>::iterator pos 
            = m_data.find(key);

        if (pos == m_data.end()) {

            std::cout << first << " " << last << " not found!" << std::endl;
            return false;
        }
        else {

            std::pair<std::string, size_t> entry = *pos;

            size_t n = entry.second;

            number = n;

            return true;
        }
    }

    virtual std::optional<size_t> searchEx(const std::string& first, const std::string& last) override
    {
        std::optional<size_t> number = std::nullopt;

        std::string key = first + " " + last;

        std::unordered_map<std::string, size_t>::iterator pos
            = m_data.find(key);

        if (pos == m_data.end()) {

            std::cout << first << " " << last << " not found!" << std::endl;
            return number;
        }
        else {

            std::pair<std::string, size_t> entry = *pos;

            size_t n = entry.second;

            number = n;

            return number;
        }
    }

private:
    static void printEntry(const std::pair<std::string, size_t>& entry) {

        std::cout 
            << "Key: " << entry.first 
            << ", Value: " << entry.second << std::endl;
    }

public:
    virtual void print() override
    {
        // Das PhoneBook durchlaufen // Traversieren

        std::for_each(
            m_data.begin(),
            m_data.end(),
            printEntry
        );
    }

    virtual void printEx() override
    {
        // Das PhoneBook durchlaufen // Traversieren

        int i = 1;   // Closure

        std::for_each(
            m_data.begin(),
            m_data.end(),
            [=] (const std::pair<std::string, size_t>& entry) mutable {

              //  int i = 1;

                std::cout
                    << i << ": "
                    << "Key: " << entry.first
                    << ", Value: " << entry.second << std::endl;

                ++i;
            }
        );
    }

    virtual void printExEx() override
    {
        // Das PhoneBook durchlaufen // Traversieren

        int i = 1;   // Closure

        std::function<void(const std::pair<std::string, size_t>&)> lambda 
            = [=](const std::pair<std::string, size_t>& entry) mutable -> void {

            //  int i = 1;

            std::cout
                << i << ": "
                << "Key: " << entry.first
                << ", Value: " << entry.second << std::endl;

            ++i;
        };

        std::for_each(
            m_data.begin(),
            m_data.end(),
            lambda
        );
    }

    virtual void printExExEx() override
    {
        // Das PhoneBook durchlaufen // Traversieren

        std::function<void(const std::pair<std::string, size_t>&)> lambda
            = [ i = 0 ] (const std::pair<std::string, size_t>& entry) mutable -> void {

          //  int i = 0;

            std::cout
                << i << ": "
                << "Key: " << entry.first
                << ", Value: " << entry.second << std::endl;

            ++i;
        };

        std::for_each(
            m_data.begin(),
            m_data.end(),
            lambda
        );
    }

    virtual void printExExExEx() override
    {
        // Das PhoneBook durchlaufen // Traversieren

        std::for_each(
            m_data.begin(),
            m_data.end(),
            [this, i = 0] (const auto& entry) mutable {
                std::cout
                    << i << ": "
                    << "Key: " << entry.first
                    << ", Value: " << entry.second << std::endl;

                ++i;

                std::cout << m_count;
            }
        );
    }
};





void test_Phonebook_01()
{
    Phonebook book;

    bool succeeded;

    succeeded = book.insert("Hans", "Meier", 12345);
    succeeded = book.insert("Susi", "Wagner", 12345);
    succeeded = book.insert("Sepp", "Mueller", 12345);

    // succeeded = book.insert("Hans", "Meier", 12345);

    size_t numberHans = 0;
    succeeded = book.search("Hans", "Wagner", numberHans);

    // Variante
    std::optional<size_t> number = book.searchEx("Hans", "Wagner");

    if (number.has_value()) {

        std::cout << "Hans Meier has number " << number.value() << std::endl;
    }
    else {
        std::cout << "Hans Meier not found" << std::endl;
    }

    book.print();

    std::cout << std::endl;

    book.printExExEx();
}

void test_Phonebook()
{
    std::cout << "bin hier\n";

    []() {};

    [] {};

    [](int x, int y) { return x + y; };

    std::cout 
        << "Bin hier: " << [](int x, int y) { return x + y; }(10, 11);

    // constexpr ...

}