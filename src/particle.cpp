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
} // namespace finalproject
