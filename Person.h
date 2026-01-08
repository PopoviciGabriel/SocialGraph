#pragma once

#include "Types.h"
#include <string>
#include <vector>

class Person {
private:
    PersonId id{};
    std::string name;
    std::vector<PersonId> friends; // friend references by ID (no ownership)

public:
    Person(PersonId pid, const std::string& n);
    ~Person();

    PersonId getId() const;
    const std::string& getName() const;

    bool hasFriend(PersonId other) const;
    bool addFriendOneWay(PersonId other);
    void removeFriendOneWay(PersonId other);

    const std::vector<PersonId>& getFriendIds() const;
    std::size_t getFriendCount() const;
};
