#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

int main()
{
    std::ifstream in("ships.json");
    nlohmann::json data;

    in >> data;

    for (const auto& ship : data) {
        std::cout << ship["category"].get<std::string>() << ", "
                  << ship["ship_class"].get<std::string>() << ", "
                  << ship["affiliation"].get<std::string>() << ", "
                  << ship["manufacturer"].get<std::string>() << ", "
                  << ship["model"].get<std::string>() << ", "
                  << ship["length"].get<int>() << ", "
                  << ship["crew"].get<int>() << '\n';
    }
}
