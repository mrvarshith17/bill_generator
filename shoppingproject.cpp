#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

map<string, map<string, double>> items;
map<pair<int, int>, string> names;

void fillItems()
{
    items["Mobile"]["Samsung"] = 15000;
    items["Mobile"]["Redmi"] = 12000;
    items["Mobile"]["Apple"] = 100000;
    items["Laptop"]["HP"] = 40000;
    items["Laptop"]["Lenovo"] = 35000;
    items["Laptop"]["Macbook"] = 250000;
    items["Course"]["C"] = 1000;
    items["Course"]["C++"] = 3000;
    items["Course"]["Java"] = 4000;
    items["Course"]["Python"] = 3500;

    names[{1, 1}] = "Apple";
    names[{1, 2}] = "Redmi";
    names[{1, 3}] = "Samsung";

    names[{2, 1}] = "HP";
    names[{2, 2}] = "Lenovo";
    names[{2, 3}] = "Macbook";

    names[{3, 1}] = "C";
    names[{3, 2}] = "C++";
    names[{3, 3}] = "Java";
    names[{3, 4}] = "Python";
}

class customer {
    map<string, map<string, int>> selected_items;
    string name;

public:
    customer()
    {
        cout << "Enter your name: ";
        string customer_name;
        getline(cin, customer_name);
        name = customer_name;
        cout << "HI ";
        for (int i = 0; i < customer_name.length(); i++) {
            cout << char(toupper(customer_name[i]));
        }
        cout << "\n\n\n";
    }

    void addToCart(string a, string b)
    {
        selected_items[a][b]++;
    }

    void displayCart()
    {
        cout << "Items in Cart:\n";
        for (const auto& category : selected_items) {
            for (const auto& item : category.second) {
                string item_name = item.first;
                int quantity = item.second;
                double cost = items[category.first][item_name];
                cout << item_name << " - Quantity: " << quantity << " - Total: Rs." << (cost * quantity) << endl;
            }
        }
        cout << endl;
    }

    void printBill()
    {
        int total_amount = 0;
        cout << "Category\t"
             << "Item\t"
             << "Quantity\t"
             << "Cost\n";

        for (const auto& category : selected_items) {
            for (const auto& item : category.second) {
                string category_name = category.first;
                string item_name = item.first;
                int quantity = item.second;
                double cost = items[category_name][item_name];
                int temp = quantity * cost;
                cout << category_name << "\t\t" << item_name << "\t" << quantity << "\t\t" << temp << endl;
                total_amount += temp;
            }
        }

        cout << "-------------------------------"
             << "-------------\n";
        cout << "Total amount:             \t\t" << total_amount << endl;
        cout << "-------------------------------"
             << "-------------\n";
        cout << "*****THANK YOU && HAPPY"
             << " ONLINE SHOPPING*****";
    }
};

class shop {

public:
    shop() {}

    virtual void show()
    {
    }
    virtual void select(customer& obj)
    {
    }

    void showMenu()
    {
        cout << "                 Menu\n";
        cout << " -----------------------------------------"
                "\n";
        cout << "1.Mobile\n2.Laptop\n3"
            << ".Programming Courses\n4.Checkout\n5.Display Cart\n6.Exit\n\n";
        cout << " -----------------------------------------"
                "\n";
    }
};

class mobile : public shop {
public:
    void show()
    {
        cout << "- - - - - - - - - - -"
            << " - -\nItem Cost\n";
        int cnt = 1;
        for (auto& it : items["Mobile"]) {
            cout << cnt++ << ". " << it.first << " --- Rs."
                << it.second << "/-\n";
        }

        cout << "- - - - - - - - - - - - -\n\n";
    }

    void select(customer& obj)
    {
        cout << "These are the smartphone categories we have....\n";
        int num;
        cout << "Enter your selection: ";
        cin >> num;
        if (num < 1 || num > 3) {
            cout << "Wrong Input\n";
            return;
        }
        int quantity;
        cout << "Enter the quantity: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Invalid quantity\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! ";
        cout << names[{1, num}] << " (" << quantity << "x) is ADDED TO THE CART\n\n";
        for (int i = 0; i < quantity; ++i) {
            obj.addToCart("Mobile", names[{1, num}]);
        }
    }
};

class laptop : public shop {
public:
    void show()
    {
        cout << "- - - - - - - - - - -"
            << " - -\nItem Cost\n";
        int cnt = 1;
        for (auto& it : items["Laptop"]) {
            cout << cnt++ << ". " << it.first << " --- Rs."
                << it.second << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n";
    }
    void select(customer& obj)
    {
        cout << "These are the laptop categories we have....\n";
        int num;
        cout << "Enter your selection: ";
        cin >> num;
        if (num < 1 || num > 3) {
            cout << "Wrong Input\n";
            return;
        }
        int quantity;
        cout << "Enter the quantity: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Invalid quantity\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! ";
        cout << names[{2, num}] << " (" << quantity << "x) is ADDED TO THE CART\n\n";
        for (int i = 0; i < quantity; ++i) {
            obj.addToCart("Laptop", names[{2, num}]);
        }
    }
};

class courses : public shop {
public:
    void show()
    {
        cout << "- - - - - - - - - - "
            << " - -\nItem     Cost\n";
        int cnt = 1;
        for (auto& it : items["Course"]) {
            cout << cnt++ << ". " << it.first << " --- Rs."
                << it.second << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n";
    }
    void select(customer& obj)
    {
        cout << "These are the courses categories we have....\n";
        int num;
        cout << "Enter your selection: ";
        cin >> num;
        if (num < 1 || num > 4) {
            cout << "Wrong Input\n";
            return;
        }
        int quantity;
        cout << "Enter the quantity: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Invalid quantity\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! ";
        cout << names[{3, num}] << " (" << quantity << "x) is ADDED TO THE CART\n\n";
        for (int i = 0; i < quantity; ++i) {
            obj.addToCart("Course", names[{3, num}]);
        }
    }
};

int main()
{
    fillItems();
    cout << "WELCOME TO OUR SHOP. WE ARE DELIGHTED THAT \n"
            "YOU ARE HERE. HOW CAN WE HELP YOU? WE DEAL IN \n"
            "ELECTRONIC GADGETS AND COURSES.\n";
    customer c;
    shop* s = nullptr;

    while (true) {
        if (s != nullptr) {
            delete s; // Delete previously allocated object
        }
        
        s = new shop(); // Allocate a new object
        s->showMenu();
        cout
            << "Please select an option to proceed "
            "further. If you choose to checkout, "
            "shopping will end and bill will be "
            "generated for the items bought so far...\n";
        int val;
        cin >> val;

        if (val == 1) {
            mobile* mb = new mobile(); // Allocate a new object
            s = mb;
            s->show();
            s->select(c);
            delete mb; // Delete previously allocated object
        }
        else if (val == 2) {
            laptop* lp = new laptop(); // Allocate a new object
            s = lp;
            s->show();
            s->select(c);
            delete lp; // Delete previously allocated object
        }
        else if (val == 3) {
            courses* cs = new courses(); // Allocate a new object
            s = cs;
            s->show();
            s->select(c);
            delete cs; // Delete previously allocated object
        }
        else if (val == 4) {
            c.printBill();
            break;
        }
        else if (val == 5) {
            cout << "Displaying cart...\n";
            c.displayCart();
        }
        else if (val == 6) {
            break;
        }
        else {
            cout << "Wrong Input. If you want to checkout, "
                    "you can press 4\n\n";
        }
        cout << "REDIRECTING TO THE MAIN MENU.....\n\n";
        sleep_until(system_clock::now() + seconds(3));
        system("clear");
    }

    return 0;
}
