#pragma once

#include <iostream>
#include "Bday.h"

typedef struct Birthday {
    std::string id;
    std::string name;
    std::string nextBirthdayIn;
    std::string ageAtNextBirthday;
};

std::string getCellValue(const Birthday& bday, int col);
void printTable(const std::vector<Birthday>& birthdays);