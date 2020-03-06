#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace Example {
    struct Ship {
        std::string affiliation;
        std::string category;
        std::string manufacturer;
        std::string model;
        std::string ship_class;
        std::vector<std::string> roles;
        int length;
    };

    void to_json(nlohmann::json& j, const Ship& ship)
    {
        j = nlohmann::json{
            {"affiliation", ship.affiliation},
            {"category", ship.category},
            {"manufacturer", ship.manufacturer},
            {"model", ship.model},
            {"ship_class", ship.ship_class},
            {"roles", ship.roles},
            {"length", ship.length}};
    }

    void from_json(const nlohmann::json& j, Ship& ship)
    {
        j.at("affiliation").get_to(ship.affiliation);
        j.at("category").get_to(ship.category);
        j.at("manufacturer").get_to(ship.manufacturer);
        j.at("model").get_to(ship.model);
        j.at("ship_class").get_to(ship.ship_class);
        j.at("roles").get_to(ship.roles);
        j.at("length").get_to(ship.length);
    }
} // namespace Example

int main()
{
    std::ifstream in("ships.json");
    nlohmann::json j;

    in >> j;

    for (const auto& entry : j) {
        const auto ship = entry.get<Example::Ship>();

        std::cout << ship.category << ", "
                  << ship.ship_class << ", "
                  << ship.affiliation << ", "
                  << ship.manufacturer << ", "
                  << ship.model << ", "
                  << ship.length << '\n';
    }
}
