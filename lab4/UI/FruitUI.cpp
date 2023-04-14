#include "FruitUI.h"

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
}

void FruitUI::deleteProduct() const {
    printTitle("Produkt loschen");
}

void FruitUI::searchProduct() const {
    printTitle("Produkte suchen");
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
