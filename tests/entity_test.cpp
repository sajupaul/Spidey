#include <gtest/gtest.h>

#include "spidey/representation/entity.h"

using spidey::representation::Entity;

TEST(EntityTest, StoresAndReturnsName) {
    Entity api("API");

    EXPECT_EQ(api.name(), "API");
}