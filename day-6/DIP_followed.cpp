#include <iostream>
using namespace std;

// Abstraction (Interface)
class Database {
public:
    virtual void save(string data) = 0; // Pure virtual function
};

// MySQL implementation (Low-level module)
class MySQLDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

// MongoDB implementation (Low-level module)
class MongoDBDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};
class PostGresDBDatabase : public Database {
public:
    void save(string data) override {
        cout << "INSERT INTO users (name) VALUES ('"<<data<<"');" << endl;
    }
};

// High-level module (Now loosely coupled)
class UserService {
private:
    Database* db;  // Dependency Injection

public:
    UserService(Database* database) {  
        db = database;
    }
    
    void storeUser(string user) {
        db->save(user);
    }
};

int main() {
    MySQLDatabase mysql;
    UserService service1(&mysql);
    service1.storeUser("Aditya");
    
    MongoDBDatabase mongodb;
    UserService service2(&mongodb);
    service2.storeUser("Rohit");

    PostGresDBDatabase postgresdb;
    UserService service3(&postgresdb);
    service3.storeUser("BD");
}