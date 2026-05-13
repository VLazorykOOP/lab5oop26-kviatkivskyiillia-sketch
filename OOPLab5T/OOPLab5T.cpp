#include <iostream>
#include <string>
using namespace std;

class Liquid {
protected:
    string name;
    double density;
public:
    Liquid() : name("Unknown liquid"), density(1000.0) {}
    Liquid(const string& n, double d) : name(n), density(d) {}
    Liquid(const Liquid& other) : name(other.name), density(other.density) {}
    virtual ~Liquid() {}

    void setDensity(double d) {
        if (d > 0) density = d;
        else cout << "  Error: density must be > 0\n";
    }

    virtual void print() const {
        cout << "  -- Liquid -------------------------\n";
        cout << "  | Name    : " << name << "\n";
        cout << "  | Density : " << density << " kg/m3\n";
        cout << "  -----------------------------------\n";
    }
};

class AlcoholicDrink : public Liquid {
private:
    double strength;
public:
    AlcoholicDrink() : Liquid("Unknown drink", 900.0), strength(0.0) {}
    AlcoholicDrink(const string& n) : Liquid(n, 900.0), strength(0.0) {}
    AlcoholicDrink(const string& n, double str) : Liquid(n, 900.0), strength(str) {}
    AlcoholicDrink(const string& n, double d, double str) : Liquid(n, d), strength(str) {}
    AlcoholicDrink(const AlcoholicDrink& other) : Liquid(other), strength(other.strength) {}
    ~AlcoholicDrink() override {}

    void setStrength(double s) {
        if (s >= 0.0 && s <= 100.0) strength = s;
        else cout << "  Error: strength must be in [0, 100]\n";
    }

    void print() const override {
        cout << "  --         Alcoholic Drink -------\n";
        cout << "  | Name     : " << name << "\n";
        cout << "  | Density  : " << density << " kg/m3\n";
        cout << "  | Strength : " << strength << " %\n";
        cout << "  -----------------------------------\n";
    }
};

void runTask1() {
    cout << "\n Task 1: Liquids & Alcoholic Drinks\n";

    cout << "\n  Class Liquid\n";
    Liquid l1;                           l1.print();
    Liquid l2("Water", 1000.0);          l2.print();
    Liquid l3(l2);
    l3.setDensity(998.0);               l3.print();
    l2.setDensity(-5);

    cout << "\n  AlcoholicDrink constructors\n";
    AlcoholicDrink d1;                                   d1.print();
    AlcoholicDrink d2("Beer");                           d2.print();
    AlcoholicDrink d3("Wine", 12.5);                     d3.print();
    AlcoholicDrink d4("Vodka", 953.0, 40.0);             d4.print();

    cout << "\n  Field reassignment \n";
    AlcoholicDrink whiskey("Whiskey", 923.0, 40.0);
    whiskey.setDensity(930.0);
    whiskey.setStrength(43.0);
    whiskey.print();
    whiskey.setStrength(150.0);
    whiskey.setDensity(-1.0);

    cout << "\n Copy constructor\n";
    AlcoholicDrink original("Cognac", 940.0, 42.0);
    AlcoholicDrink copy(original);
    copy.setStrength(45.0);
    cout << "  Original:\n"; original.print();
    cout << "  Copy:\n";     copy.print();

    cout << "\n  Polymorphism\n";
    Liquid* items[] = {
        new Liquid("Oil", 910.0),
        new AlcoholicDrink("Rum", 935.0, 37.5),
        new AlcoholicDrink("Champagne", 998.0, 11.0)
    };
    for (auto* item : items) { item->print(); delete item; }
}

class Wheel {
protected:
    double radius;
    string material;
public:
    Wheel() : radius(30.0), material("rubber") {}
    Wheel(double r, const string& m) : radius(r), material(m) {}
    virtual ~Wheel() {}

    virtual void print() const {
        cout << "  --                Wheel-----------\n";
        cout << "  | Radius   : " << radius << " cm\n";
        cout << "  | Material : " << material << "\n";
        cout << "  -----------------------------------\n";
    }
};

class Bicycle : public Wheel {
protected:
    string brand;
    int    gears;
public:
    Bicycle() : Wheel(35.0, "rubber"), brand("Unknown"), gears(1) {}
    Bicycle(const string& b, int g, double r, const string& m)
        : Wheel(r, m), brand(b), gears(g) {
    }
    virtual ~Bicycle() {}

    void print() const override {
        cout << "  --        Bicycle         --------\n";
        cout << "  | Brand    : " << brand << "\n";
        cout << "  | Gears    : " << gears << "\n";
        cout << "  | Radius   : " << radius << " cm\n";
        cout << "  | Material : " << material << "\n";
        cout << "  -----------------------------------\n";
    }
};

class Car : public Bicycle {
private:
    int    wheelCount;
    double engineCC;
public:
    Car() : Bicycle("Unknown", 0, 40.0, "rubber"), wheelCount(4), engineCC(1600.0) {}
    Car(const string& b, double eng, int wc, double r, const string& m)
        : Bicycle(b, 0, r, m), wheelCount(wc), engineCC(eng) {
    }
    ~Car() override {}

    void print() const override {
        cout << "  --          Car      -------------\n";
        cout << "  | Brand    : " << brand << "\n";
        cout << "  | Engine   : " << engineCC << " cc\n";
        cout << "  | Wheels   : " << wheelCount << "\n";
        cout << "  | Radius   : " << radius << " cm\n";
        cout << "  | Material : " << material << "\n";
        cout << "  -----------------------------------\n";
    }
};

void runTask2() {
    cout << "\n Task 2: Wheel -> Bicycle -> Car\n";

    cout << "\n  Class Wheel\n";
    Wheel w1;                                    w1.print();
    Wheel w2(38.0, "tubeless");                  w2.print();

    cout << "\n  Class Bicycle\n";
    Bicycle b1;                                  b1.print();
    Bicycle b2("Trek", 21, 34.0, "rubber");      b2.print();

    cout << "\n  Class Car \n";
    Car c1;                                      c1.print();
    Car c2("Toyota Camry", 2500.0, 4, 40.0, "tubeless"); c2.print();

    cout << "\nPolymorphism\n";
    Wheel* items[] = {
        new Wheel(28.0, "rubber"),
        new Bicycle("Giant", 18, 33.0, "rubber"),
        new Car("BMW X5", 3000.0, 4, 42.0, "all-season")
    };
    for (auto* item : items) { item->print(); delete item; }
}

class Person {
protected:
    string name;
    int    age;
public:
    Person() : name("Unknown"), age(0) {}
    Person(const string& n, int a) : name(n), age(a) {}
    Person(const Person& other) : name(other.name), age(other.age) {}
    virtual ~Person() {}

    Person& operator=(const Person& other) {
        if (this != &other) { name = other.name; age = other.age; }
        return *this;
    }

    virtual void writeTo(ostream& os) const {
        os << "Name: " << name << ", Age: " << age;
    }
    virtual void readFrom(istream& is) {
        cout << "  Enter name: "; is >> name;
        cout << "  Enter age : "; is >> age;
    }

    friend ostream& operator<<(ostream& os, const Person& p) {
        p.writeTo(os); return os;
    }
    friend istream& operator>>(istream& is, Person& p) {
        p.readFrom(is); return is;
    }
};

class Teacher : public Person {
private:
    string subject;
    int    experience;
public:
    Teacher() : Person(), subject("Unknown"), experience(0) {}
    Teacher(const string& n, int a, const string& s, int exp)
        : Person(n, a), subject(s), experience(exp) {
    }
    Teacher(const Teacher& other)
        : Person(other), subject(other.subject), experience(other.experience) {
    }
    ~Teacher() override {}

    Teacher& operator=(const Teacher& other) {
        if (this != &other) {
            Person::operator=(other);
            subject = other.subject;
            experience = other.experience;
        }
        return *this;
    }

    void writeTo(ostream& os) const override {
        Person::writeTo(os);
        os << ", Subject: " << subject << ", Experience: " << experience << " yr.";
    }
    void readFrom(istream& is) override {
        Person::readFrom(is);
        cout << "  Enter subject    : "; is >> subject;
        cout << "  Enter experience : "; is >> experience;
    }
};

void runTask3() {
    cout << "\n  Task 3: Person -> Teacher \n";

    cout << "\n  Constructors & output\n";
    Person  p1("Ivan Franko", 45);
    Teacher t1("Maria Koval", 38, "Mathematics", 12);
    cout << "  " << p1 << "\n";
    cout << "  " << t1 << "\n";

    cout << "\n  Copy constructor\n";
    Teacher original("Oleg Bondar", 50, "Physics", 20);
    Teacher copy(original);
    cout << "  Original : " << original << "\n";
    cout << "  Copy     : " << copy << "\n";

    cout << "\n  Assignment operator\n";
    Teacher t2("Svitlana Moroz", 42, "Chemistry", 15);
    Teacher t3;
    t3 = t2;
    cout << "  t2: " << t2 << "\n";
    cout << "  t3: " << t3 << "\n";
    t2 = t2;
    cout << "  After t2=t2: " << t2 << "\n";

    cout << "\n Polymorphism \n";
    Person* items[] = {
        new Person("Taras Shevchenko", 47),
        new Teacher("Lesia Ivanova", 35, "Ukrainian language", 8)
    };
    for (auto* item : items) {
        cout << "  " << *item << "\n";
        delete item;
    }

    cout << "\n Input from stream\n";
    Teacher t;
    cout << "  Enter teacher data:\n";
    cin >> t;
    cout << "  Result: " << t << "\n";
}

void printMenu() {
    cout << "\n";
    cout << "  ----------------------------------------\n";
    cout << "  |  1 - Task 1                          |\n";
    cout << "  |  2 - Task 2                          |\n";
    cout << "  |  3 - Task 3                          |\n";
    cout << "  |  0 - Poka                            |\n";
    cout << "  ----------------------------------------\n";
    cout << "  Choice: ";
}

int main() {
    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: runTask1(); break;
        case 2: runTask2(); break;
        case 3: runTask3(); break;
        case 0: cout << "\n  Goodbye!\n\n"; break;
        default: cout << "\n  Unknown option. Try again.\n"; break;
        }
    } while (choice != 0);

    return 0;
}