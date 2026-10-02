#pragma once

#include <string>

namespace spidey::representation {

class Entity {
public:
    explicit Entity(std::string name);

    const std::string& name() const;

private:
    std::string name_;
};

} // namespace spidey::representation