#include "SocialNetwork.h"
#include <iostream>

int main() {
    std::cout << "=== SOCIAL GRAPH (SOLE OWNER) ===\n";
    SocialNetwork net;

    PersonId alice   = net.addPerson("Alice");
    PersonId bob     = net.addPerson("Bob");
    PersonId charlie = net.addPerson("Charlie");
    PersonId diana   = net.addPerson("Diana");

    net.makeFriends("Alice", "Bob");
    net.makeFriends("Alice", "Charlie");
    net.makeFriends("Bob", "Diana");
    net.makeFriends("Charlie", "Diana");

    std::cout << "\n=== NETWORK ===\n";
    for (PersonId id : net.listPeopleIds()) {
        const Person* p = net.getPerson(id);
        if (!p) continue;

        auto names = net.getFriendNames(id);
        std::cout << p->getName() << " are prietenii:\n";
        if (names.empty()) std::cout << " (niciun prieten)\n";
        for (const auto& n : names) std::cout << " - " << n << "\n";
    }

    std::cout << "\n--- Remove Charlie ---\n";
    net.removePerson("Charlie");

    std::cout << "\n=== NETWORK AFTER REMOVE ===\n";
    for (PersonId id : net.listPeopleIds()) {
        const Person* p = net.getPerson(id);
        if (!p) continue;

        auto names = net.getFriendNames(id);
        std::cout << p->getName() << " are prietenii:\n";
        if (names.empty()) std::cout << " (niciun prieten)\n";
        for (const auto& n : names) std::cout << " - " << n << "\n";
    }

    std::cout << "\nAlice friend count: " << net.getFriendNames(alice).size() << "\n";
    std::cout << "Diana friend count: " << net.getFriendNames(diana).size() << "\n";
}
