/*
    Create classes to represent cars with registered owners, for records kept by the Road Transport Administration
    Agency. Each car registration should have a manufacturer name, a model name, an owner (a pointer to a Person
    object), horsepower (a number) and a registration number (a string). A Person has a name, age, and a unique
    numerical id starting from 0 (the first Person has an id of 0, the second – an id of 1 and so on). A single Person can
    have multiple cars registered to them. A car’s owner and registration number can be changed, but they always
    change together (i.e. when you change a car’s owner, you also change its registration number). A person’s name and
    age can change, but their id always stays the same. Write a program which can create Person objects and create car
    registrations by reading input from the console, and can print out information about a car registration (and the
    owner it is registered to) – the input and output format is up to you, just make sure it is easy to enter the input and
    read the output.
    Make sure you create the proper classes, constructors, access modifiers and methods for the above task. You should
    submit your program in a single .cpp file.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Car;
class Person;
void printCommands();
void listPeople();
void listCars();
void createPerson();
void createCar();
void registerCar();
void endProgram();

string indent(int lvl);
void endCommand();

typedef void (*command)();
map<string, command> commands{
    {"help", &printCommands},
    {"list people", &listPeople},
    {"list cars", &listCars},
    {"new car", &createCar},
    {"new person", &createPerson},
    {"register car", &registerCar},
    {"end", &endProgram}
};
vector<Person> people;
vector<Car> cars;
bool runProgram = true;

int main()
{
    string command;
    while (runProgram)
    {
        getline(cin, command);
        if (commands.find(command) == commands.end())
        {
            cout << "Error: Unknown command " << command << endl;
            printCommands();
            continue;
        }
        commands[command]();
    }
    printCommands();
    system("pause");
    return 0;
}

class Person {
public:
    string name;
    int age;
    vector<Car*> cars;
    static int personsCount;
private:
    int id;
public:
    Person()
    {

    }

    Person(string name, int age) : name(name), age(age)
    {
        this->id = personsCount++;
    }

    void changeName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void changeAge(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return this->age;
    }

    int get_id()
    {
        return this->id;
    }
};
int Person::personsCount = 0;

class Car {
    static int carsCount;
private:
    bool registered = false;
    int id;
    string man_name;
    string model;
    double hp;
    Person * owner;
    string reg_number;
public:
    Car()
    {

    }

    Car(string man_name, string model, double hp) : man_name(man_name), model(model), hp(hp)
    {
        this->id = carsCount++;
    }

    void registerCar(string reg_number, Person * owner)
    {
        this->registered = true;
        this->reg_number = reg_number;
        this->owner = owner;
    }

    int get_id()
    {
        return this->id;
    }

    string get_man_name()
    {
        return this->man_name;
    }
    
    string get_model()
    {
        return this->model;
    }

    double get_hp()
    {
        return this->hp;
    }

    Person * get_owner()
    {
        return this->owner;
    }

    string get_reg_number()
    {
        return this->reg_number;
    }

    bool is_registered()
    {
        return this->registered;
    }
};
int Car::carsCount = 0;

void printCommands()
{
    cout << "Avaliable commands: " << endl;
    for (auto i = commands.begin(); i != commands.end(); i++)
    {
        cout << i->first << endl;
    }
    endCommand();
    
}

void listPeople()
{
    for (auto i = people.begin(); i != people.end(); i++)
    {
        cout << "Name: " << i->name << endl;
        cout << indent(1) << "ID: " << i->get_id() << endl;
        cout << indent(1) << "Age: " << i->age << endl;
        cout << indent(1) << "Cars: " << endl;
        for (auto c = i->cars.begin(); c != i->cars.end(); c++)
        {
            cout << indent(2) << (*c)->get_model() << " -> " << (*c)->get_reg_number() << endl;
        }
    }
    endCommand();
}

void listCars()
{
    for (auto i = cars.begin(); i != cars.end(); i++)
    {
        cout << i->get_id() << indent(1);
        cout << ((i->is_registered()) ? i->get_reg_number() : "Unregistered");
        if (i->is_registered())
        {
            cout << indent(1) << "Owner: " << (*i).get_owner()->name << " ID: " << (*i).get_owner()->get_id();
        }
        cout << indent(1) << "Model: " << i->get_model() << endl;
        cout << indent(1) << "Man. name: " << i->get_man_name() << endl;
    }
    endCommand();
}

void createPerson()
{
    string name;
    int age;
    cout << "Person name: ";
    cin >> name;
    cout << "Person age: ";
    cin >> age;
    cin.ignore();
    Person person(name, age);
    people.push_back(person);
    endCommand();
}

void createCar()
{
    string man_name, model;
    double hp;
    cout << "Man. name: ";
    cin >> man_name;
    cout << "Model: ";
    cin >> model;
    cout << "Hp: ";
    cin >> hp;
    cin.ignore();
    cars.push_back(Car(man_name, model, hp));
    endCommand();
}

void registerCar()
{
    Car * selectedCar = &cars[0];
    bool found = false;
    while (!found)
    {
        int carId;
        cout << "Choose a car. Enter car id: ";
        cin >> carId;
        for (int i = 0; i < cars.size(); i++)
        {
            if (cars[i].get_id() == carId) {
                selectedCar = &cars[i];
                found = true;
                break;
            }
        }
        if (!found) cout << "Car not found" << endl;
    }
    found = false;
    Person * selectedOwner = &people[0];
    while (!found)
    {
        int ownerId;
        cout << "Choose owner. Enter owner id: ";
        cin >> ownerId;
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i].get_id() == ownerId) {
                selectedOwner = &people[i];
                found = true;
                break;
            }
        }
        if (!found) cout << "Person not found" << endl;
    }
    string reg_number;
    cout << "Reg. number: ";
    cin >> reg_number;
    cin.ignore();
    if (selectedCar->is_registered())
    {
        for (auto p = people.begin(); p != people.end(); p++)
        {
            if (selectedCar->get_owner()->get_id() == p->get_id())
            {
                for (auto c = p->cars.begin(); c != p->cars.end(); c++)
                {
                    if ((*c)->get_id() == selectedCar->get_id())
                    {
                        p->cars.erase(c);
                        break;
                    }
                }
                break;
            }
        }
    }
    selectedOwner->cars.push_back(selectedCar);
    selectedCar->registerCar(reg_number, selectedOwner);
    endCommand();
}

void endProgram()
{
    runProgram = false;
}


//prints a footer marking a command end on the console
void endCommand()
{
    cout << endl << "=============END=============" << endl;
    
}

string indent(int lvl = 0)
{
    string res;
    for (int i = 0; i < lvl; i++)
    {
        res +=  "    ";
    }
    return res;
}