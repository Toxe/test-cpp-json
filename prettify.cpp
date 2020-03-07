#include <fstream>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>

int main()
{
    std::ifstream in("ships.json");
    nlohmann::json data;

    in >> data;

    std::cout << std::setw(2) << data << std::endl;
}
