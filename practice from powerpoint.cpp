#include <iostream>
#include <string>
using namespace std;

class Authors{
protected:
	string name;
	string email;
	char gender;

public:
	Authors(){
	}
	
	Authors(string name, string email, char gender){
		this -> name = name;
		this -> email = email;
		this -> gender = gender;
	}
	string getName(){
		return name;
	}
	string getEmail(){
		return email;
	}
	char getGender(){
		return gender;
	}
	void setEmail(string email){
	
		this -> email = email;
	}
	string toString(){
		return name + "\n" + email + to_string(gender);
	} 
};

class Book:public Authors{
private:
	string bookname;
	Authors *author = new Authors[0];
	double price;
	int qty;
public:
	Book(string bookname, Authors *author, double price){
		this -> bookname = bookname;
		this -> author = author;
		this -> price = price;
	}
	Book(string bookname, Authors *author, double price, int qty){
		this -> bookname = bookname;
		this -> author = author;
		this -> price = price;
		this -> qty = 0;
	}
	string getBookname(){
		return bookname;
	}
	Authors getAuthors(){
		return *author;
	}
	double getPrice(){
		return price;
	}
	void setPrice(double price){
		this -> price = price;
	}
	int getQty(){
		return qty;
	} 
	void setQty(int qty){
		this -> qty = qty;
	}
	string getAuthornames(){
		return (*author).getName();
	}
	string toString(){
		return bookname + "\n" + (*author).toString() + "\n" + to_string(price) + to_string(qty) + "\n" + getAuthornames();	 
	}
};

int main(){
	Authors thisauthor("Budi", "budi(a)ymail(dot)com", 'M');
	Authors thisauthor2("Joko", "joko(a)gmail(dot)com", 'M');
	Book thisbook("NGAKAK", &thisauthor2, 1.99, 10);
	cout << thisbook.toString();
	
}
