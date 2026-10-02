#include "spidey/representation/entity.h"

#include <utility>

namespace spidey::representation {

Entity::Entity(std::string name)
    : name_(std::move(name)) {
}

const std::string& Entity::name() const {
    return name_;
}

} // namespace spidey::representation