#include "FruitUI.h"

FruitUI::FruitUI(FruitController &_controller) {
    controller = &_controller;
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

/**
 * Print a list of strings as a table
 * @param columnHeaders
 * @param lines
 * @param lineWidth
 */
void FruitUI::tableView(const vector<string> &columnHeaders, const vector<vector<string>> &lines, int lineWidth) const{
    if (lines.empty())
        return;

    if (columnHeaders.size() != lines[0].size())
        throw invalid_argument("utils::tableView(): table lines must have the same number of columns as the header");

    // count total number of chars in header
    int charCount = 0;
    for (const string &column: columnHeaders)
        charCount += int(column.size());

    // Compute spacing between column headers
    int spacing = (lineWidth - charCount) / int(columnHeaders.size());

    // Print headers using computed spacing
    for (const string &header: columnHeaders)
        cout << header << string(spacing, ' ');

    cout << endl;

    // Print table lines aligned to the headers start
    for (const vector<string> &columns: lines) {
        for (int i = 0; i < columns.size(); i++) {
            cout << columns[i];

            //Fill the remaining column space with spaces
            if (i != columns.size() - 1) {
                int columnSpace = int(columnHeaders[i].size()) + spacing;
                int spaceFill = columnSpace - int(columns[i].size());
                cout << string(spaceFill, ' ');
            }
        }
        cout << endl;
    }
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

void FruitUI::addProduct() const {
    printTitle("Produkt hinzufugen");
    string name{}, origin{};
    time_t expiryDate;
    int quantity, price;

    cout << "Name: ";
    cin >> name;

    while (name.empty()) {
        cout << "Name kann nicht leer sein!\n";
        cout << "Name: ";
        cin >> name;
    }

    cout << "Herkunft: ";
    cin >> origin;

    while (origin.empty()) {
        cout << "Herkunft, kann nicht leer sein!\n";
        cout << "Herkunft: ";
        cin >> origin;
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
    printTitle("Produkt loschen");
    string name, origin;

    cout << "Name: ";
    cin >> name;

    while (name.empty()) {
        cout << "Name kann nicht leer sein!\n";
        cout << "Name: ";
        cin >> name;
    }

    cout << "Herkunft: ";
    cin >> origin;

    while (origin.empty()) {
        cout << "Herkunft kann nicht leer sein!\n";
        cout << "Herkunft: ";
        cin >> origin;
    }

    bool success = controller->remove(name, origin);

    if (success)
        cout << "Frucht nicht gefunden";
    else
        cout << "Frucht (" << name << ", " << origin << ") wurde geloscht!";
}

void FruitUI::searchProduct() const {
    printTitle("Produkte suchen");
    auto matches = controller->find();

    // Print matches as table
    vector<string> columns = {"Name", "Herkunft", "Haltbarkeitsdatum", "Menge", "preis"};
    vector<vector<string>> lines;
    lines.reserve(matches.size());
    for (const Fruit &fruit: matches)
        lines.emplace_back(fruit.toList());

    tableView(columns, lines, MAX_LINE_WIDTH);
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
