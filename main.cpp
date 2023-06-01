#include <iostream>

using namespace std;

class User {
 public:
  string name;
  string gender;
  string address;
  string phone;

  User(string name, string gender, string phone, string address) {
    User::name = name;
    User::gender = gender;
    User::phone = phone;
    User::address = address;
  }

  string getName() {
    return User::name;
  }

  string getPhone() {
    return User::phone;
  }

  string getGender() {
    return User::gender;
  }

  string getAddress() {
    return User::address;
  }
};

class Buyer : public User {
 public:
  int balance;
  Buyer(string name, string gender, string phone, string address, int balance) : User(name, gender, phone, address) {
    Buyer::balance = balance;
  }

  int getBalance() {
    return Buyer::balance;
  }

  void setBalance(int newBalance) {
    balance = newBalance;
  }

  void getDetailBuyer() {
    cout << "Nama: " << Buyer::getName() << endl;
    cout << "Gender: " << Buyer::getGender() << endl;
    cout << "Phone: " << Buyer::getPhone() << endl;
    cout << "Balance: " << Buyer::getBalance() << endl;
    cout << "Address: " << Buyer::getAddress() << endl;
  }
};

class Book {
 public:
  string title;
  string author;
  Book(string title, string author) {
    Book::title = title;
    Book::author = author;
  }

  string getTitle() {
    return Book::title;
  }

  string getAuthor() {
    return Book::author;
  }
};

class Novel : public Book {
 public:
  int price;
  int year;
  Novel(string title, string author, int year, int price) : Book(title, author) {
    Novel::price = price;
    Novel::year = year;
  }

  int getPrice() {
    return Novel::price;
  }
};

class Transaction {
 public:
  Transaction(Buyer buyer, Novel novel) {
    if (buyer.balance < novel.price) {
      cout << "cannot buy" << endl;
    } else {
      cout << "Succes Buy Book " << novel.getTitle() << endl;
      cout << "Enjoy reading: " << novel.getTitle() << endl;
      buyer.setBalance(buyer.getBalance() - novel.getPrice());
      cout << "Your balance: Rp. " << buyer.getBalance() << endl;
    }
  }
};

int main() {
  Buyer buyer1("Denny", "Male", "081xxx", "Surabaya", 100000);
  Novel novel1("Hujan", "Tere Liye", 2020, 20000);
  Transaction transaction1(buyer1, novel1);

  return 0;
}
