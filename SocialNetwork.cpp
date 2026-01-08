#include "SocialNetwork.h"

bool SocialNetwork::exists(PersonId id) const {
    return id < people.size() && people[id] != nullptr;
}

PersonId SocialNetwork::addPerson(const std::string& name) {
    auto it = nameToId.find(name);
    if (it != nameToId.end()) return it->second;

    const PersonId id = nextId++;
    people.push_back(std::make_unique<Person>(id, name));
    nameToId[name] = id;
    return id;
}

std::optional<PersonId> SocialNetwork::findPersonId(const std::string& name) const {
    auto it = nameToId.find(name);
    if (it == nameToId.end()) return std::nullopt;
    if (!exists(it->second)) return std::nullopt;
    return it->second;
}

Person* SocialNetwork::getPerson(PersonId id) {
    if (!exists(id)) return nullptr;
    return people[id].get();
}

const Person* SocialNetwork::getPerson(PersonId id) const {
    if (!exists(id)) return nullptr;
    return people[id].get();
}

bool SocialNetwork::makeFriends(const std::string& aName, const std::string& bName) {
    auto aOpt = findPersonId(aName);
    auto bOpt = findPersonId(bName);
    if (!aOpt || !bOpt) return false;

    const PersonId a = *aOpt;
    const PersonId b = *bOpt;
    if (a == b) return false;

    Person* pa = getPerson(a);
    Person* pb = getPerson(b);
    if (!pa || !pb) return false;

    const bool addedA = pa->addFriendOneWay(b);
    const bool addedB = pb->addFriendOneWay(a);
    return addedA || addedB;
}

bool SocialNetwork::removePerson(const std::string& name) {
    auto idOpt = findPersonId(name);
    if (!idOpt) return false;

    const PersonId id = *idOpt;

    // remove this id from everyone else's friend lists
    for (auto& up : people) {
        if (!up) continue;
        up->removeFriendOneWay(id);
    }

    people[id].reset();
    nameToId.erase(name);
    return true;
}

std::vector<std::string> SocialNetwork::getFriendNames(PersonId id) const {
    std::vector<std::string> result;

    const Person* p = getPerson(id);
    if (!p) return result;

    for (PersonId fid : p->getFriendIds()) {
        const Person* f = getPerson(fid);
        if (f) result.push_back(f->getName());
    }
    return result;
}

std::vector<PersonId> SocialNetwork::listPeopleIds() const {
    std::vector<PersonId> ids;
    ids.reserve(people.size());

    for (PersonId i = 0; i < people.size(); ++i) {
        if (people[i]) ids.push_back(i);
    }
    return ids;
}
