#include <iostream>
#include <ctime>
#include <sstream>
#include <json/json.h>

typedef struct {
    std::string id;
    std::string name;
    std::string bday;
    std::string ageAtNextBirthday;
    std::string nextBirthdayIn;
} Birthday;

std::vector<Birthday> configToBday(const std::vector<Json::Value>& data) {
    std::vector<Birthday> final;

    time_t now = time(nullptr);
    struct tm currentDate = *localtime(&now);

    for (unsigned int i = 0; i < data.size(); i++) {
        Json::Value data_f = data[i];
        Birthday bday{};
        bday.id = data_f["id"].asString();
        bday.bday = data_f["bday"].asString();
        bday.name = data_f["name"].asString();

        struct tm dateStruct;
        std::istringstream ss(bday.bday);
        ss >> dateStruct.tm_mday;
        ss.ignore(1);
        ss >> dateStruct.tm_mon;
        ss.ignore(1);
        ss >> dateStruct.tm_year;

        if (!ss) {
            std::cerr << "Invalid date" << std::endl;
            exit(1);
        }

        dateStruct.tm_mon--; // Adjust for 0-based month
        dateStruct.tm_year -= 1900; // Adjust for years since 1900

        // Calculate the time to next birthday
        dateStruct.tm_year = currentDate.tm_year;
        if (difftime(mktime(&currentDate), mktime(&dateStruct)) > 0) {
            dateStruct.tm_year++;
        }

        time_t timeToNextBirthday = difftime(mktime(&dateStruct), now);

        // Calculate the age at the next birthday
        int age = currentDate.tm_year - dateStruct.tm_year;
        if (currentDate.tm_mon < dateStruct.tm_mon ||
            (currentDate.tm_mon == dateStruct.tm_mon && currentDate.tm_mday < dateStruct.tm_mday)) {
            age--; // Not yet reached the next birthday
        }

        // Calculate days to next birthday
        int daysToNextBirthday = static_cast<int>(timeToNextBirthday / (24 * 60 * 60));

        if (daysToNextBirthday < 0) {
            // If the next birthday has already occurred, adjust both age and days to next birthday
            age++;
            daysToNextBirthday = 365 - (-daysToNextBirthday);
        }

        std::ostringstream dtnb;
        dtnb << daysToNextBirthday;
        dtnb << " days";

        std::ostringstream ageoss;
        ageoss << age;
        ageoss << " years";

        bday.ageAtNextBirthday = ageoss.str();
        bday.nextBirthdayIn = dtnb.str();

        final.push_back(bday);
    }

    return final;
}
