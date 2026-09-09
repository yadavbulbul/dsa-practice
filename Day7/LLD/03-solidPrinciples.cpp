/*
SOLID

S = Single Responsibility Principle
O = Open/Closed Principle
L = Liskov Substitution Principle
I = Interface Segregation Principle
D = Dependency Inversion Principle

The Five Principles
S — Single-Responsibility Principle (SRP): A class should have only one reason to change, meaning it should perform just one job.
O — Open/Closed Principle (OCP): Software parts should be open for adding new features, but closed for changing existing code.
L — Liskov Substitution Principle (LSP): Child classes must be able to stand in for their parent classes without breaking the program.
I — Interface Segregation Principle (ISP): Do not force a class to use methods or interfaces it does not need.
D — Dependency Inversion Principle (DIP): Depend on abstract interfaces or classes rather than concrete, low-level details.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n, double p) : name(n), price(p) {}
};

// Only responsible for cart-related logic: Single Responsibility Principle (SRP)
class ShoppingCart {
public:
    vector<Product*> products;

    void addProduct(Product* p) {
        products.push_back(p);
    }

    vector<Product*> getProducts() {
        for (Product* p : products) {
            cout << p->name << endl;
        }
        return products;
    }

    double totalPrice(const vector<Product*>& items) {
        double total = 0;
        for (Product* p : items) {
            total += p->price;
        }
        return total;
    }
};

// Abstract class for payment processing: Open/Closed Principle (OCP)
// This class can be extended for different payment methods without modifying existing code.
class PaymentProcessor{
public:
    virtual void pay(double amount) = 0; // Pure virtual function
    virtual ~PaymentProcessor() {}
};

//we can create multiple payment methods by extending the PaymentProcessor class without changing its code.
class CreditCardPayment : public PaymentProcessor {
private:
    void pay(double amount) override {
        cout << "Paid " << amount << " using Credit Card." << endl;
    }
};
class PayPalPayment : public PaymentProcessor {
private:
    void pay(double amount) override {
        cout << "Paid " << amount << " using PayPal." << endl;
    }
};
class BankTransferPayment : public PaymentProcessor {
private:
    void pay(double amount) override {
        cout << "Paid " << amount << " using Bank Transfer." << endl;
    }
};

//liskov Substitution Principle (LSP) is demonstrated here as we can use any derived class of PaymentProcessor in place of the base class without affecting the correctness of the program.

// Interface Segregation Principle (ISP) is demonstrated here as we have a separate interface for payment processing, which can be implemented by different classes without forcing them to implement methods they don't need.

// Dependency Inversion Principle (DIP) is demonstrated here as the ShoppingCart class depends on the PaymentProcessor interface rather than concrete implementations, allowing for flexibility and easier maintenance.

int main() {
    Product* p1 = new Product("bag", 2000);
    Product* p2 = new Product("makeup", 5000);

    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(p1);
    cart->addProduct(p2);

    cout << "Available products:" << endl;
    vector<Product*> productss = cart->getProducts();

    cout << "Total Cost:" << endl;
    cout << cart->totalPrice(productss) << endl;

    // Payment processing using credit card
    PaymentProcessor* paymentMethod = new CreditCardPayment();
    paymentMethod->pay(cart->totalPrice(productss));
    
    // Payment processing using PayPal
    PaymentProcessor* paymentMethod2 = new PayPalPayment();
    paymentMethod2->pay(cart->totalPrice(productss));

    // Payment processing using bank transfer
    PaymentProcessor* paymentMethod3 = new BankTransferPayment();
    paymentMethod3->pay(cart->totalPrice(productss));

    // Clean up memory
    delete p1;
    delete p2;
    delete cart;
    delete paymentMethod;
    delete paymentMethod2;
    delete paymentMethod3;

    return 0;
}