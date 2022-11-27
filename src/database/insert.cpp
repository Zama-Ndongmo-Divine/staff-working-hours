#include <iostream>
#include <sqlite3.h>
#include <string>
  
using namespace std;
  
static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}
  
int main(int argc, char** argv)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("/home/wakanda/Desktop/Intro To MAD/management/database/staff_management.db", &DB);
    string query = "SELECT * FROM PERSON;";
  
    cout << "STATE OF TABLE BEFORE INSERT" << endl;

    int id;
    string fname;
    string sname;
    string age;
    string address;
    int salary;

    cout << "Enter the users given id" << endl;
    cin >> id;
    cout << "First name" << endl;
    cin >> fname;
    cout << "Second name" << endl;
    cin >> sname;
    cout << "Age" << endl;
    cin >> age;
    cout << "User's Address" << endl;
    cin >> address;
    cout << "User's salary" << endl;
    cin >> salary;
   
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  
    string sql("INSERT INTO PERSON VALUES(?, ?, ?, ?, ?, ?)",(id, fname, sname, age, address, salary));
  
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
        sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
        sqlite3_close(DB);
    return (0);
}