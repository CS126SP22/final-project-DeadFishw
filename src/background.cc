#include <particle.h>
#include "background.h"

namespace finalproject {
Background::Background() {
    player_ = Board(100, 40, vec2(350,600));
    Block block = Block(10,10,vec2(500, 5), true);
    //blocks_.push_back(block);
    particle.SetPosition(vec2(100,10));
    particle.SetVelocity(vec2(-5, 0));
    particle.SetVelocity(vec2(-4, 0));
    particle.SetPosition(vec2(25,21));
    blocks_.emplace_back(20,20,vec2(0, 0), false);
}

void Background::Display() const {
    // This function has a lot of magic numbers; be sure to design your code in a way that avoids this.
    //ci::gl::color(ci::Color(particle.GetColor()));
    //ci::gl::drawSolidCircle(particle.GetPosition(), particle.GetSize());
    ci::gl::drawStrokedRect(ci::Rectf(vec2(0, 0), vec2(kLength, kWidth)));
    player_.Display();
    particle.Display();
    for(auto& block: blocks_) {
        block.Display();
    }
    ci::gl::drawString(
            std::to_string(current_frame_),
            glm::vec2(0, GetSize().y + 50), ci::Color("white"), ci::Font("Arial", 30.0f));
}

void Background::AdvanceOneFrame() {
    particle.AdvanceOneFrame();
    particle.CollideWithBlocks(blocks_);
    particle.CollideWithWall(kLength, kWidth);
    particle.CollideWithBoard(&player_);
    player_.AdvanceOneFrame();
}


vec2 Background::GetSize() const {
    return glm::vec2(kLength, kWidth);
}

void Background::CharacterMove(char command) {
    switch (command) {
        case 'a':
            player_.SetVelocity(vec2(-kVelocity, 0));
            break;
        case 'd':
            player_.SetVelocity(vec2(kVelocity, 0));
            break;
    }
}

bool Background::Ended() {
    for (auto& block: blocks_) {
        if (block.IsBreakable()) {
            return false;
        }
    }
    return true;
}

void Background::Restart() {

}

Particle Background::GetParticle() {
    return particle;
}

std::vector<Block> Background::GetWalls() {
    return blocks_;
}
}  // namespace idealgas
