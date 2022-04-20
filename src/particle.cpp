#include <particle.h>


namespace finalproject {

using glm::vec2;

Particle::Particle() {
    position_ = vec2(0, 0);
}

Particle::Particle(float x, float y) {
  position_ = vec2(x, y);
}

vec2 Particle::GetPosition() const {
  return position_;
}

float Particle::GetSize() const {
  return kSize;
}

char* Particle::GetColor() const {
  return color_;
}

void Particle::AdvanceOneFrame() {
    position_ = vec2(position_.x + speed_, position_.y);
}

void Particle::CollideWithWall(float length, float width) {
    if (position_.x - kSize > 0 && position_.x + kSize < length) {
        if (position_.y - kSize > 0 && position_.y + kSize < width) {
            return;
        }
        if ((velocity_.y < 0 && position_.y - kSize < 0) ||
            (velocity_.y > 0 && position_.y + kSize > width)) {
            velocity_ = vec2(velocity_.x, -velocity_.y);
        }
    }
    if ((velocity_.x < 0 && position_.x - kSize < 0) ||
        (velocity_.x > 0 && position_.x + kSize > length)) {
        velocity_ = vec2(-velocity_.x, velocity_.y);
    }
}

void Particle::CollideWithBlocks(std::vector<Block*> &blocks) {
    for (auto block = blocks.begin(); block != blocks.end(); block++) {
        if (canCollide(*block)) {
            if ((*block)->IsBreakable()) {
                blocks.erase(block);
            }
        }
    }
}

    bool Particle::canCollide(Block * block) {

        return true;
    }


} // namespace finalproject
