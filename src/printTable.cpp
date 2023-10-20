#include <iostream>
#include <iomanip>
#include <vector>

typedef struct Birthday {
    std::string id;
    std::string name;
    std::string nextBirthdayIn;
    std::string ageAtNextBirthday;
};

std::string getCellValue(const Birthday& bday, int col) {
    switch (col) {
    case 0: return bday.id;
    case 1: return bday.name;
    case 2: return bday.nextBirthdayIn;
    case 3: return bday.ageAtNextBirthday;
    default: return "";
    }
}

void printTable(const std::vector<Birthday>& birthdays) {
    int rows = birthdays.size();
    int columns = 4;

    std::cout << std::endl;

    std::string cols[4]{ "ID", "Name", "Next birthday in", "Age at next birthday" };

    // Calculate maximum column widths based on column headers
    std::vector<int> maxColWidths(columns, 0);
    for (int col = 0; col < columns; col++) {
        maxColWidths[col] = cols[col].length();
    }

    // Iterate through the data to find the maximum width for each column
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            const std::string& cellValue = getCellValue(birthdays[row], col);
            if (cellValue.length() > maxColWidths[col]) {
                maxColWidths[col] = cellValue.length();
            }
        }
    }

    // Print the top border
    for (int col = 0; col < columns; col++) {
        std::cout << "+";
        for (int i = 0; i < maxColWidths[col] + 2; i++) {
            std::cout << "-";
        }
    }
    std::cout << "+\n";

    // Print the column headers
    std::cout << "| ";
    for (int col = 0; col < columns; col++) {
        std::cout << std::left << std::setw(maxColWidths[col]) << cols[col] << " | ";
    }
    std::cout << "\n";

    // Print the horizontal border under the headers
    for (int col = 0; col < columns; col++) {
        std::cout << "+";
        for (int i = 0; i < maxColWidths[col] + 2; i++) {
            std::cout << "-";
        }
    }
    std::cout << "+\n";

    // Print the table rows
    for (int row = 0; row < rows; row++) {
        std::cout << "| ";
        for (int col = 0; col < columns; col++) {
            std::cout << std::left << std::setw(maxColWidths[col]) << getCellValue(birthdays[row], col) << " | ";
        }
        std::cout << "\n";

        // Print the horizontal border after each row
        for (int col = 0; col < columns; col++) {
            std::cout << "+";
            for (int i = 0; i < maxColWidths[col] + 2; i++) {
                std::cout << "-";
            }
        }
        std::cout << "+\n";
    }
}