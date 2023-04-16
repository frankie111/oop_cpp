#include "FruitUI.h"
#include <sstream>
#include <ctime>
#include <iomanip>

FruitUI::FruitUI(FruitController &_controller) {
    controller = &_controller;
}

/**
 * Entry point of FruitUI
 */
void FruitUI::mainMenu() const {
    printTitle("Fruchteladen App");
    vector<string> options = {"hinzufugen", "loschen", "suchen", "knappe Produkte auslisten",
                              "Sortiere nach Haltbarkeitsdatum", "Beenden"};
    int option = menu("Main Menu", options);

    switch (option) {
        case 1:
            addProduct();
            break;
        case 2:
            deleteProduct();
            break;
        case 3:
            searchProduct();
            break;
        case 4:
            printScarceProducts();
            break;
        case 5:
            sortByExpiryDate();
            break;
        case 6:
            cout << "App beendet!\n";
            return;
        default:
            mainMenu();
    }

    mainMenu();
}

/**
 * Print a printTitle on one line with TITLE_CHAR as highlighting
 * @param title printTitle to display in the centre of the line
 */
void FruitUI::printTitle(const string &title, TitleStyle tStyle) const {
    int half = (MAX_LINE_WIDTH - int(title.size()) - 2) / 2;
    string str(half, tStyle);
    str += ' ' + title + ' ';
    str += string(half, (tStyle));

    while (str.size() < MAX_LINE_WIDTH)
        str += char(tStyle);

    cout << str << endl;
}

/**
 * Print a menu as a numbered list of options
 * @returns the selected option as int
 * @param title
 * @param options
 */
int FruitUI::menu(const string &title, const vector<string> &options) const {
    printTitle(title, SUBTITLE_CHAR);

    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ". " + options[i] << endl;
    }

    printTitle(string(title.size(), '~'), SUBTITLE_CHAR);
    cout << "->";

    int option;
    cin >> option;

    if (option < 1 || option > options.size()) {
        cout << "Invalid option\n";
        option = menu(title, options);
    }

    return option;
}

void FruitUI::addProduct() const {
    printTitle("Produkt hinzufugen");
    string name{}, origin{};
    time_t expiryDate;
    int quantity, price;

    cout << "Name: ";
    cin >> name;
//    getline(cin, name);

    while (name.empty()) {
        cout << "Name kann nicht leer sein!\n";
        cout << "Name: ";
//        getline(cin, name);
        cin >> name;
    }

    cout << "Herkunft,: ";
//    getline(cin, origin);
    cin >> origin;

    while (origin.empty()) {
        cout << "Herkunft, kann nicht leer sein!\n";
        cout << "Herkunft: ";
//        getline(cin, origin);
        cin >> origin;
    }

    string expiry{};

    cout << "Haltbarkeitsdatum, (D-M-Y): ";
//    getline(cin, expiry);
    cin >> expiry;

    while (expiry.empty()) {
        cout << "Haltbarkeitsdatum kann nicht leer sein!\n";
        cout << "Haltbarkeitsdatum, (D-M-Y): ";
//        getline(cin, expiry);
        cin >> expiry;
    }

    tm time{};
    stringstream ss(expiry);
    ss >> get_time(&time, "%d-%m-%Y");
    expiryDate = mktime(&time);

    cout << "Menge: ";
    cin >> quantity;

    while (quantity == 0) {
        cout << "Die Menge kann nicht null sein!";
        cout << "Menge: ";
        cin >> quantity;
    }

    cout << "Preis: ";
    cin >> price;

    while (price == 0) {
        cout << "Preis kann nicht null sein!";
        cout << "Preis: ";
        cin >> price;
    }

    controller->add(name, origin, expiryDate, quantity, price);
}

void FruitUI::deleteProduct() const {
    printTitle("Produkt loschen");
}

void FruitUI::searchProduct() const {
    printTitle("Produkte suchen");
    auto matches = controller->find();
    for (Fruit fruit: matches) {
        fruit.print();
        cout << endl;
    }
}

void FruitUI::printScarceProducts() const {
    printTitle("Knappe Produkte");

    int threshold;
    cout << "Grenzwert eingeben ->";
    cin >> threshold;


}

void FruitUI::sortByExpiryDate() const {
    printTitle("produkte nach Haltbarkeitsdatum");
}
