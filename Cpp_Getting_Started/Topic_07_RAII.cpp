#include <iostream> // printf


class Database
{
public:
    void Open() { std::cout << "Open\n"; };
    bool DoRiskyOperation() { return false; };
    void DoNormalOperation() {};
    void DoAnyOperation() {};
    void Close() { std::cout << "Close\n"; };
};

// RAII: Resource Acquisition is Initialization
class DatabaseWrapper
{
private:
    Database m_db;

public:
    DatabaseWrapper() { 
        std::cout << "Wrapper c'tor" << std::endl;
        m_db.Open();
    }

    ~DatabaseWrapper() {
        std::cout << "Wrapper d'tor" << std::endl;
        m_db.Close();
    }

    void DoRiskyOperation() { 

        bool success = m_db.DoRiskyOperation();

        if (!success) {
            // std::cout << "habe ein Problem mit der Datenbank\n";
            throw std::exception("habe ein Problem mit der Datenbank");
        }
    };


};


void test_database_BAD_USAGE ()
{
    Database db;

    db.Open();

    // try ... okay 
    bool success = db.DoRiskyOperation();
    if (! success) {
        return;
    }

    db.Close();
}

void test_database_GOOD_USAGE()
{
    // viele Anweisungen

    {
        DatabaseWrapper dbWrapper;

        try
        {
            dbWrapper.DoRiskyOperation();
        }
        catch (std::exception ex)
        {
            std::cout << "Problem mit der Datenbank\n";
        }
        
        // Close der Datenbank im Destruktor !!!!!!!!!!!!!!!!!!!!
    }

    std::cout << "bin hier .........\n";

    // viele Anweisungen
}

void test_raii()
{
    test_database_GOOD_USAGE();
}
