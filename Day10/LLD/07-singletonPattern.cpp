/*
A Singleton class allows only one object of that class to exist throughout the application.

Lazy Singleton
→ create when needed

Thread-safe Singleton
→ protect creation from multiple threads

Double-checked locking
→ check → lock → check → create

Eager Singleton
→ create immediately
*/

// #include<iostream>
// using namespace std;

// class Logger{
// private:
//     Logger(){};
//     static Logger* instance;
// public:
//     static Logger* getInstance(){
//         if(instance == nullptr){
//             instance = new Logger();
//         }

//         return instance;
//     }
//     void log(){
//         cout<<"Log created."<<endl;
//     }

// };
// //DataType ClassName::staticVariable = value;
// Logger* Logger::instance = nullptr;

// int main(){
//     Logger* l1 = Logger::getInstance();

//     l1->log();

//     Logger* l2 = Logger::getInstance();
//     l2->log();

//     if(l1==l2){
//         cout<<"Both are the same logger object";
//     }
//     return 0;
// }

// //thread safe version
// #include<iostream>
// #include<mutex>
// using namespace std;

// class Logger{
// private:
//     Logger(){};
//     static Logger* instance;
//     static mutex mtx;
// public:
//     static Logger* getInstance(){
//         // Lock
//         lock_guard<mutex> lock(mtx);
//         if(instance==nullptr){
//             instance = new Logger();
//         }
//         return instance;
//     }
//     void log(string message){
//         cout<<message<<endl;
//     }
// };

// Logger* Logger::instance = nullptr;
// mutex Logger::mtx;

// int main() {

//     Logger* l1 = Logger::getInstance();
//     Logger* l2 = Logger::getInstance();

//     l1->log("Hello");
//     l2->log("Hello again");

//     cout << (l1 == l2) << endl;

//     return 0;
// }


//double-check locking
#include<iostream>
#include<mutex>
using namespace std;

class Logger{
private:
    Logger(){};
    static Logger* instance;
    static mutex mtx;
public:
    static Logger* getInstance(){
        if(instance==nullptr){
            // Lock
            lock_guard<mutex> lock(mtx);
            if(instance==nullptr){
                instance = new Logger();
            }
        }
        
        return instance;
    }
    void log(string message){
        cout<<message<<endl;
    }
};

Logger* Logger::instance = nullptr;
mutex Logger::mtx;

int main() {

    Logger* l1 = Logger::getInstance();
    Logger* l2 = Logger::getInstance();

    l1->log("Hello");
    l2->log("Hello again");

    cout << (l1 == l2) << endl;

    return 0;
}