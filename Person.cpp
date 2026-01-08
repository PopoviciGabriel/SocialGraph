#include "Person.h"

#include <algorithm>

Person::Person(PersonId pid, const std::string& n)
    : id(pid), name(n) {}

Person::~Person() = default;

PersonId Person::getId() const { return id; }

const std::string& Person::getName() const { return name; }

bool Person::hasFriend(PersonId other) const {
    return std::find(friends.begin(), friends.end(), other) != friends.end();
}

bool Person::addFriendOneWay(PersonId other) {
    if (other == id) return false;
    if (hasFriend(other)) return false;
    friends.push_back(other);
    return true;
}

void Person::removeFriendOneWay(PersonId other) {
    friends.erase(std::remove(friends.begin(), friends.end(), other), friends.end());
}

const std::vector<PersonId>& Person::getFriendIds() const { return friends; }

std::size_t Person::getFriendCount() const { return friends.size(); }
