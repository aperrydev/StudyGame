#include "SetLoader.h"
#include <fstream>
#include <sstream>

bool loadSet(const std::string &path, StudySet &set) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    std::getline(file, line);
    set.setName(line);
    std::string category;


    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[0] == '#') {
            category = line.substr(1);
            continue;
        }


        std::stringstream ss(line);
        std::string term;
        std::getline(ss,term,'|');
        std::string definition;
        std::getline(ss,definition,'|');
        std::string explanation;
        std::getline(ss,explanation,'|');
        set.addCard({term, definition, explanation, category});
    }
    return true;

}
