# include <iostream>

class Person {
    public:
        int aye;
        std::string name;
        void welcom();
        int year(int idade);

    void full_date() {
        std::cout << "Nome: " << name << " Idade: " << aye << '\n';
    }
};
/* Herança - 'Daughter' está herdando da classe 'Person' */
class Daughter: public Person {
    public:
        int year;
};
/* herança de varios níveis */
class Bot: public Daughter {
    public:
        std::string bot_name_pc;
};

int Person::year(int idade) {
    return idade;
}

void Person::welcom() {
    std::cout << "Hello, World\n";
}

class Car {

    public:
        std::string name_car;
        std::string model_car;
        int year;
        void print_car();
};

void Car::print_car() {
    std::cout << name_car << " " << model_car << " " << year << '\n';
}

class Salary {
    private:
        double salary;
    public:
        double setsalary(double new_salary) {
            return salary = new_salary;
        }
        double getsalary() {
            return salary;
        }
};

/* Herança Múltipla */
class Shop: public Bot, public Salary {

};

class Name {
    protected:
        std::string first_name;
};

/* Acessar elementos protegidos de classes herdadas */
class UserName: public Name {
    public:
        std::string last_name;

    void name_full() {
        first_name = "Oscar";
        std::cout << first_name << " " << last_name << '\n';
    }
};

/* polimorfismo */
class Animal {
    public:
        void sound_animal() {
            std::cout << "Som de um Animal" << '\n';
        }
};

class Dog: public Animal {
    public:
        std::string dog_name;
        int aye_dog;
    
    void sound_animal() {
        std::cout << "Au Au Au AU" << '\n';
    }
    void status_animal() {
        std::cout << "Nome do Cachorro: " << dog_name << " Idade: " << aye_dog << " Som: ";
        sound_animal();
    }
};

int main() {
    Person pessoa;
    Person pessoa1;
    pessoa.aye = 15;
    pessoa.name = "Oscar";
    pessoa1.aye = 21;
    pessoa1.name = "Wenderson";
    std::cout << "Nome: " << pessoa.name << '\n';
    std::cout << "Idade: " << pessoa.aye << '\n';
    std::cout << "Nome: " << pessoa1.name << '\n';
    std::cout << "Idade: " << pessoa1.aye << '\n';
    pessoa.full_date();
    pessoa.welcom();
    std::cout << pessoa1.year(2002) << '\n';
    Car carro;
    carro.name_car = "Maverick";
    carro.model_car = "Sport";
    carro.year = 1976;
    carro.print_car();
    Salary salario;
    salario.setsalary(1000);
    std::cout << salario.getsalary() << '\n';
    Daughter filha;
    filha.aye = 12;
    filha.year = 2002;
    std::cout << "Idade: " << filha.aye << " Ano: "<< filha.year << '\n';
    Bot bot;
    bot.bot_name_pc = "Bot_name";
    bot.year = 1002;
    std::cout << "Nome do Bot: " << bot.bot_name_pc << " Ano do Bot: " << bot.year << '\n';
    Shop tests;
    tests.aye = 200; // Class Person
    tests.bot_name_pc = "Name"; // Class Bot
    tests.setsalary(2000); // Class Salary
    std::cout << tests.getsalary() << '\n'; // Méthod - Class Salary
    UserName full_name;
    full_name.last_name = "Santos";
    full_name.name_full();
    Dog cachorro;
    Animal generic;
    cachorro.dog_name = "Elio";
    cachorro.aye_dog = 2;
    generic.sound_animal(); // classe animal
    cachorro.sound_animal(); // classe dog subscrever método
    cachorro.status_animal();
    return 0;
}