#include <particle.h>
#include "background.h"

namespace finalproject {
Background::Background() {

}

void Background::Display() const {
    // This function has a lot of magic numbers; be sure to design your code in a way that avoids this.
    ci::gl::color(ci::Color(particle.GetColor()));
    ci::gl::drawSolidCircle(particle.GetPosition(), particle.GetSize());
`
    ci::gl::drawStrokedRect(ci::Rectf(vec2(0, 0), vec2(kLength, kWidth)));
    ci::gl::drawString(
            std::to_string(current_frame_),
            glm::vec2(0, GetSize().y + 50), ci::Color("white"), ci::Font("Arial", 30.0f));
}

void Background::AdvanceOneFrame() {
    particle.AdvanceOneFrame();
    particle.CollideWithBlocks(blocks_);
    particle.CollideWithWall(kLength, kWidth);
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
        if (block->IsBreakable()) {
            return false;
        }
    }
    return true;
}

void Background::Restart() {

}
}  // namespace idealgas
