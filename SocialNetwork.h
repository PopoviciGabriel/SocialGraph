#pragma once

#include "Person.h"
#include "Types.h"

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

class SocialNetwork {
private:
    std::vector<std::unique_ptr<Person>> people;            // sole owner
    std::unordered_map<std::string, PersonId> nameToId;     // name -> id
    PersonId nextId{0};

    bool exists(PersonId id) const;

public:
    PersonId addPerson(const std::string& name);

    std::optional<PersonId> findPersonId(const std::string& name) const;

    Person* getPerson(PersonId id);
    const Person* getPerson(PersonId id) const;

    bool makeFriends(const std::string& aName, const std::string& bName);
    bool removePerson(const std::string& name);

    std::vector<std::string> getFriendNames(PersonId id) const;
    std::vector<PersonId> listPeopleIds() const;
};
