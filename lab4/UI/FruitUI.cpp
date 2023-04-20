#include "FruitUI.h"
#include "Widgets.cpp"

FruitUI::FruitUI(unique_ptr<FruitController> _controller) {
    controller = std::move(_controller);
}

/**
 * Entry point of FruitUI
 */
void FruitUI::mainMenu() const {
    Widgets::printTitle("Fruchteladen App");
    vector<string> options = {"hinzufugen", "loschen", "suchen", "knappe Produkte auslisten",
                              "Sortiere nach Haltbarkeitsdatum", "Beenden"};
    int option = Widgets::menu("Main Menu", options);

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

void FruitUI::addProduct() const {
    Widgets::printTitle("Produkt hinzufugen");
    string name{}, origin{};
    time_t expiryDate;
    int quantity, price;

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    while (name.empty()) {
        cout << "Name kann nicht leer sein!\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
    }

    cout << "Herkunft: ";
    getline(cin, origin);

    while (origin.empty()) {
        cout << "Herkunft, kann nicht leer sein!\n";
        cout << "Herkunft: ";
        cin.ignore();
        getline(cin, origin);
    }

    string expiry{};

    cout << "Haltbarkeitsdatum (D-M-Y): ";
    cin >> expiry;

    while (expiry.empty()) {
        cout << "Haltbarkeitsdatum kann nicht leer sein!\n";
        cout << "Haltbarkeitsdatum (D-M-Y): ";
        cin >> expiry;
    }

    expiryDate = strToTime(expiry);

    cout << "Menge: ";
    cin >> quantity;

    while (quantity == 0) {
        cout << "Die Menge kann nicht null sein!\n";
        cout << "Menge: ";
        cin >> quantity;
    }

    cout << "Preis: ";
    cin >> price;

    while (price == 0) {
        cout << "Preis kann nicht null sein!\n";
        cout << "Preis: ";
        cin >> price;
    }

    controller->add(name, origin, expiryDate, quantity, price);
}

void FruitUI::deleteProduct() const {
    Widgets::printTitle("Produkt loschen");
    string name, origin;

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    while (name.empty()) {
        cout << "Name kann nicht leer sein!\n";
        cout << "Name: ";
        getline(cin, name);
    }

    cout << "Herkunft: ";
    getline(cin, origin);

    while (origin.empty()) {
        cout << "Herkunft kann nicht leer sein!\n";
        cout << "Herkunft: ";
        cin.ignore();
        getline(cin, origin);
    }

    bool success = controller->remove(name, origin);

    cout << name << ' ' << origin << endl;

    if (success)
        cout << "Frucht (" << name << ", " << origin << ") wurde geloscht!";
    else
        cout << "Frucht nicht gefunden";
    cout << endl;
}

void FruitUI::searchProduct() const {
    Widgets::printTitle("Produkte suchen");
    cout << "Schlusselwort eingeben ->";
    string searchKey;
    cin.ignore();
    getline(cin, searchKey);
    cout << endl;

    auto matches = controller->find(searchKey);
    if (matches.empty()) {
        cout << "Keine Treffer gefunden" << endl;
        return;
    }

    // Print matches as table
    Widgets::tableView(matches);
}

void FruitUI::printScarceProducts() const {
    Widgets::printTitle("Knappe Produkte");

    int threshold;
    cout << "Grenzwert eingeben ->";
    cin >> threshold;

    auto matches = controller->findScarce(threshold);
    if (matches.empty()) {
        cout << "Keine Treffer gefunden" << endl;
        return;
    }

    // Print matches as table
    Widgets::tableView(matches);
}

void FruitUI::sortByExpiryDate() const {
    Widgets::printTitle("produkte nach Haltbarkeitsdatum");
    vector<Fruit> list = controller->sortByExpiryDate();

    // Print list as table
    Widgets::tableView(list);
}
