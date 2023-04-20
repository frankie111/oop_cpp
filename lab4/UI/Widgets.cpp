#ifndef LAB4_WIDGETS_CPP
#define LAB4_WIDGETS_CPP

#include <iostream>
#include <string>
#include <vector>
#include "FruitUI.h"

using namespace std;

class Widgets {
    friend class FruitUI;

private:
    enum TitleStyle {
        TITLE_CHAR = '=',
        SUBTITLE_CHAR = '-'
    };

    static vector<vector<string>> listToTableLines(const vector<Fruit> &list) {
        vector<vector<string>> lines;
        lines.reserve(list.size());
        for (const Fruit &fruit: list)
            lines.emplace_back(fruit.toList());

        return lines;
    }

public:

    /**
    * Print a printTitle on one line with TITLE_CHAR as highlighting
    * @param title printTitle to display in the centre of the line
    */
    static void printTitle(const string &title, TitleStyle tStyle = TITLE_CHAR) {
        int half = (FruitUI::MAX_LINE_WIDTH - int(title.size()) - 2) / 2;
        string str(half, tStyle);
        str += ' ' + title + ' ';
        str += string(half, (tStyle));

        while (str.size() < FruitUI::MAX_LINE_WIDTH)
            str += char(tStyle);

        cout << str << endl;
    }

    /**
    * Print a menu as a numbered list of options
    * @returns the selected option as int
    * @param title
    * @param options
    */
    static int menu(const string &title, const vector<string> &options) {
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
    * @param maxLineWidth
    */
    static void tableView(vector<Fruit> &list) {
        vector<vector<string>> lines = listToTableLines(list);

        if (lines.empty())
            return;

        vector<string> columnHeaders = {"Name", "Herkunft", "Haltbarkeitsdatum", "Menge", "preis"};

        if (columnHeaders.size() != lines[0].size())
            throw invalid_argument(
                    "utils::tableView(): table lines must have the same number of columns as the header");

        columnHeaders[0].insert(0, "   ");

        // Add numbering to table lines
        for (int i = 0; i < lines.size(); i++) {
            lines[i][0].insert(0, to_string(i + 1) + ". ");
        }

        // count total number of chars in header
        int charCount = 0;
        for (const string &column: columnHeaders)
            charCount += int(column.size());

        // Compute spacing between column headers
        int spacing = (FruitUI::MAX_LINE_WIDTH - charCount) / int(columnHeaders.size());

        // Print headers using computed spacing
        for (const string &header: columnHeaders)
            cout << header << string(spacing, ' ');

        cout << endl;

        // Print table lines aligned to the headers start
        for (const vector<string> &columns: lines) {
            for (int i = 0; i < columns.size(); i++) {
                int columnSpace = int(columnHeaders[i].size()) + spacing;

                // If word overflows clip it
                if (columns[i].size() >= columnSpace)
                    cout << columns[i].substr(0, columnSpace - 3) << ".. ";
                else
                    cout << columns[i];

                //Fill the remaining column space with spaces
                if (i != columns.size() - 1) {
                    int spaceFill = columnSpace - int(columns[i].size());
                    if (spaceFill > 0)
                        cout << string(spaceFill, ' ');
                }
            }
            cout << endl;
        }
    }
};

#endif //LAB4_WIDGETS_CPP