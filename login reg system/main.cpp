#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using std::string; using std::cin; using std::cout; using std::endl;
std::ofstream out("login_data.txt",std::ios::app);
std::ifstream in("login_data.txt");
class Person {
private:
	string nume;
	string parola;
public:
	void setNume(string nume) {
		this->nume = nume;
	}
	void setParola(string parola) {
		this->parola = parola;
	}
	Person(string nume, string parola) {
		this->nume = nume;
		this->parola = parola;
	}
	Person() {
		nume = "";
		parola = "";
	}
	string getNume() { return nume; }
	string getParola() { return parola; }
	bool equalTo(Person p) {
		if (this->nume == p.nume && this->parola == p.parola) {
			return true;
		}
		else return false;
	}
};

std::vector<Person> persoane;
void printPers() {
	for (int i = 0; i < persoane.size(); i++) {
		cout << persoane.at(i).getNume() << " " << persoane.at(i).getParola();
	}
}
void registerPerson()
{
	string n;
	string p;
	cout << "Enter name:"; cin >> n;
	cout << "Enter password:"; cin >> p;
	out <<endl<< n << " " << p<<",";
}
void savePerson()
{
	string line;
	char delim =',';
	while (std::getline(in, line, delim)) {
		Person pers;
		string delimiter = " ";
		size_t pos = 0;
		string token;
		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			pers.setNume(token);
			line.erase(0, pos + delimiter.length());
		}
		pers.setParola(line);
		persoane.push_back(pers);
	}
}
bool checkLogin() {
	savePerson();
	string username;
	string userPassword;
	Person user;
	cout << "Specify the name:"; cin >> username;
	cout << "Specify password:"; cin >> userPassword;
	user.setNume(username);
	user.setParola(userPassword);
	for (int i = 0; i < persoane.size() - 1; i++) {
		if (user.equalTo(persoane.at(i)))
		{
			return true;
		}
		else
		{
			return user.equalTo(persoane.at(i));
		}
	}
	
}
int main()
{
	
	int choice;
	cout << "Enter option\n1.Register\n2.Login\nYour choice:";
	cin >> choice;
	if (choice == 1) {
		registerPerson();
	}
	else if (choice == 2) {
		if (!checkLogin()) {
			cout << "Login failed";
		}
		else {
			cout << "Login succesful";
		}
	}
	else {
		cout << "Error please select a valid option.";
			exit(0);
	}
	return 0;
}