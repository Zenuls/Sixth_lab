#include <iostream>
#include <vector>

using namespace std;

class Pizza {
public:
    string name;
    string description;
    unsigned short int size;
    unsigned short int prise;
    unsigned short int salt;
    unsigned short int cheese;

    Pizza (string n, string d, unsigned short int s, unsigned short int p): name(n), description(d), prise(p), size(s), salt(0), cheese(0) {}

    void Salt() {
        unsigned short int count;
        cout << "Введите количество соли: ";
        cin >> count;
        add_salt(count);
    }    
    
    void add_salt(int count) {
        salt = count;
        this->prise += 5*count;
    }

    void Cheese() {
        unsigned short int count;
        cout << "Введите количество сыра: ";
        cin >> count;
        add_cheese(count);
    } 

    void add_cheese(int count) {
        cheese = count;
        this->prise  += 10*count;
    }

    virtual unsigned short int Size_prise() {
        switch (size) {
        case 25:
            this->prise += 0;
            break;
        case 30:
            this->prise += 50;
            break;
        case 35:
            this->prise += 100;
            break;
        case 40:
            this->prise += 200;
            break;
        }
        return this->prise;
    }
    
    void Print_Pizza() {
        cout << "Название: " << name << endl;
        cout << "Описание: " << description << endl;
        cout << "Размер: " << size << " см" << endl;
        cout << "Соль: " << salt << endl;
        cout << "Сыр: " << cheese << endl;
        cout << "Цена: " << Size_prise() << " руб." << endl;
    }

};

class Margaret_pizza: public Pizza {
public:
    Margaret_pizza(unsigned short int size): Pizza("Пицца Маргарита", "Нежное тесто, томатный соус, сыр моцарелла и ароматные прованские травы", size, 389) {}
};
class Hawaiian_pizza: public Pizza {
public:
    Hawaiian_pizza(unsigned short int size): Pizza("Пицца Гавайская", "Сочетание нежной ветчины с кусочками ананаса и сыром моцарелла на томатном соусе", size, 489) {}
};
class Pepperoni_pizza: public Pizza {
public:
    Pepperoni_pizza(unsigned short int size): Pizza("Пицца Пепперони", "Салями пепперони, томаты, сыр моцарелла", size, 539) {}
};
class Four_cheeses_pizza: public Pizza {
public:
    Four_cheeses_pizza(unsigned short int size): Pizza("Пицца Четыре сыра", "Оригинальное сочетание сыров на томатном соусе: моцарелла, пармезан, горгонзола, маасдам и ароматные специи", size, 539) {}
};
class Seafood_pizza: public Pizza {
public:
    Seafood_pizza(unsigned short int size): Pizza("Пицца с Морепродуктами", "Креветки, кальмар, моцарелла, помидоры черри, томатный соус, соус песто ", size, 749) {}
};

class Order {
public:
    vector<Pizza> pizzas;

    void Add(Pizza pizza) {
        pizzas.push_back(pizza);
    }

    void Print_order() {
        cout << "Ваш заказа:"<< endl;
        unsigned short int price = 0;
        for (Pizza pizza : pizzas) {
            pizza.Print_Pizza();
            price += pizza.prise;
        }
        cout << "Итого: " << price << " руб." << endl;
    }

    void Menu() {
        cout<< "Вот Ваше меню:" << endl;
        cout<< "1 - Пицца Маргарита" << endl;
        cout<< "2 - Пицца Гавайская" << endl;
        cout<< "3 - Пицца Пепперони" << endl;
        cout<< "4 - Пицца Четыре сыра" << endl;
        cout<< "5 - Пицца с Морепродуктами" << endl;
        cout << endl;
    }
};

void Continue () {}



int main() {
    setlocale(0, "");
    Order order;
    unsigned short int pizza;
    bool n;
    bool m;
    unsigned short int size;
    bool continuation = 1;
    Pizza* selection;
    cout << "Рады приветствовать Вас в нашей пиццерии"<< endl;
    do
    {  
        order.Menu(); 
        cout<< "Введите номер пиццы:  "<< endl;
        cin >> pizza;
        cout << "Введите размер пиццы (25, 30, 35, 40): ";
        cin >> size;
        switch (pizza) {
        case 1:
            selection = new Margaret_pizza(size);
            break;
        case 2:
            selection = new Hawaiian_pizza(size);
            break;
        case 3:
            selection = new Pepperoni_pizza(size);
            break;
        case 4:
            selection = new Four_cheeses_pizza(size);
            break;
        case 5:
            selection = new Seafood_pizza(size);
            break;
        default:
            cout << "Вы неправильно ввели номер. Попробуйте снова" << endl;
            cout << endl;
            continue;
        }
        n=false;
        m=false;
        cout << "Хотите посолить (0,1)? " << endl;
        cin >> n;
        n ? selection->Salt() : Continue();
        cout << "Хотите добавить сыра (0,1)? " << endl;
        cin >> m;
        m ? selection->Cheese() : Continue();
        order.Add(*selection);
        delete selection;
        cout<<"Введите 1, если хотите продожить заказ, иначе 0" << endl;
        cin>> continuation;
    } while (continuation);
    order.Print_order();
    return 0;
}