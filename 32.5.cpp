#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "nlohmann/json.hpp"


int main() {
    //load data base
    nlohmann::json filmDB;
    std::ifstream myStream ("..\\filmdb.json");
    myStream >> filmDB;
    myStream.close();

    //find actor
    std::string findActor = "Jack";

    for (auto& [title, film] : filmDB.items())
    {
        for (auto & actor : film.at("actorList")) {
            auto fullName = nlohmann::to_string(actor.at("name"));
            if (fullName.find(findActor) != std::string::npos) {
                std::string actorStr = "Actor: " + fullName;
                std::cout << actorStr << std::endl;

                std::string filmStr = "Film: ";
                filmStr += title;
                std::cout << filmStr << std::endl;;

                std::string characterStr = "Character: " + nlohmann::to_string(actor.at("asCharacter"));
                std::cout << characterStr << std::endl;

                std::cout << std::endl;
            }
        }
    }

    return 0;
}
