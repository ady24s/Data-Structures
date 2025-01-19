#include<iostream>
using namespace std;

class item {
public:
    char name[20];
    int price;
};

class sales {
public:
    int sales_three_months;
    int totalsales;
};

class hwitem : public item, public sales {
public:
    void getdata();
    void displaydata();
};

class switem : public item, public sales {
public:
    void getdata();
    void displaydata();
};

void hwitem::getdata() {
    cout << "Enter the name of the item:";
    cin >> name;

    cout << "Enter price for per piece: ";
    cin >> price;

    cout << "Enter the sales figure:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Enter sales figure for month " << i + 1 << ": ";
        cin >> sales_three_months;
        totalsales += sales_three_months;
    }

    cout << "Total sales: " << totalsales << endl;
}

void hwitem::displaydata() {
    cout << "Item name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Sales for three months: " << totalsales << endl;
}

void switem::getdata() {
    cout << "Enter the name of the item:";
    cin >> name;

    cout << "Enter price for per piece: ";
    cin >> price;

    cout << "Enter the sales figure:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Enter sales figure for month " << i + 1 << ": ";
        cin >> sales_three_months;
        totalsales += sales_three_months;
    }

    cout << "Total sales: " << totalsales << endl;
}

void switem::displaydata() {
    cout << "Item name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Sales for three months: " << totalsales << endl;
}

int main() {
    hwitem hw;
    switem sw;

    hw.getdata();
    sw.getdata();
    hw.displaydata();
    sw.displaydata();

    return 0;
}
