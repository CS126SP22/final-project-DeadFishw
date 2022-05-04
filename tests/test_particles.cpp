#include <catch2/catch.hpp>
#include "background.h"
namespace finalproject {
    TEST_CASE("Test that particles are updated based on velocity") {
        Background container;
        container.GetParticle().SetVelocity(vec2(0, 1));
        container.GetParticle().SetPosition(vec2(3,0));
        container.AdvanceOneFrame();
        REQUIRE(container.GetParticle().GetPosition() == vec2(3, 1));
    }
    TEST_CASE("Test CollideWithBlock") {
        SECTION("Test that particle collide block upward correctly") {
            Background container;
            container.GetParticle().SetVelocity(vec2(0, 5));
            container.GetParticle().SetPosition(vec2(10,0));
            container.GetWalls().push_back(Block(10,10,vec2(5, 5), false));
            container.AdvanceOneFrame();
            container.AdvanceOneFrame();
            REQUIRE((container.GetParticle().GetVelocity().x == 0 && container.GetParticle().GetVelocity().y == -5));
        }
        SECTION("Test that particle collide block downward correctly") {
            Background container;
            container.GetParticle().SetVelocity(vec2(0, -5));
            container.GetParticle().SetPosition(vec2(10,20));
            container.GetWalls().push_back(Block(10,10,vec2(5, 5), false));
            container.AdvanceOneFrame();
            container.AdvanceOneFrame();
            REQUIRE((container.GetParticle().GetVelocity().x == 0 && container.GetParticle().GetVelocity().y == 5));
        }
        SECTION("Test that particle collide block upward correctly") {
            Background container;
            container.GetParticle().SetVelocity(vec2(10, 0));
            container.GetParticle().SetPosition(vec2(10,0));
            container.GetWalls().push_back(Block(10,10,vec2(24, 5), false));
            container.AdvanceOneFrame();
            container.AdvanceOneFrame();
            REQUIRE((container.GetParticle().GetVelocity().x == -10 && container.GetParticle().GetVelocity().y == 0));
        }
        SECTION("Test that particle collide block upward correctly") {
            Background container;
            container.GetParticle().SetVelocity(vec2(-5, 0));
            container.GetParticle().SetPosition(vec2(20,0));
            container.GetWalls().push_back(Block(10,10,vec2(5, 5), false));
            container.AdvanceOneFrame();
            container.AdvanceOneFrame();
            REQUIRE((container.GetParticle().GetVelocity().x == 5 && container.GetParticle().GetVelocity().y == 0));
        }
        SECTION("Test that particle collide corner correctly") {
            Background container;
            container.GetParticle().SetVelocity(vec2(-4, 0));
            container.GetParticle().SetPosition(vec2(25,20));
            container.GetWalls().push_back(Block(20,20,vec2(0, 0), false));
            container.AdvanceOneFrame();
            container.AdvanceOneFrame();
            REQUIRE((container.GetParticle().GetVelocity().x == 0 && container.GetParticle().GetVelocity().y == -4));
        }
    }
}
