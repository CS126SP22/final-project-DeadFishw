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
    position_ = vec2(position_.x + velocity_.x, position_.y + velocity_.y);
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

void Particle::CollideWithBlocks(std::vector<Block> &blocks) {
    for (auto block = blocks.begin(); block != blocks.end(); block++) {
        if ((*block).GetPosition().y - position_.y <= kSize &&
                (*block).GetPosition().y - position_.y >= 0 &&
                position_.x >= (*block).GetPosition().x &&
                position_.x <= (*block).GetPosition().x + (*block).GetSize().x) {//upward
            if (velocity_.y > 0) {
                velocity_.y = - velocity_.y;
                if ((*block).IsBreakable()) {
                    blocks.erase(block);
                    break;
                }
            }
        } else if (position_.y - (*block).GetPosition().y - (*block).GetSize().y <= kSize &&
                    position_.y - (*block).GetPosition().y - (*block).GetSize().y >= 0 &&
                    position_.x >= (*block).GetPosition().x &&
                    position_.x <= (*block).GetPosition().x + (*block).GetSize().x) {//downward
            if (velocity_.y < 0) {
                velocity_.y = - velocity_.y;
                if ((*block).IsBreakable()) {
                    blocks.erase(block);
                    break;
                }
            }
        } else if (position_.x - (*block).GetPosition().x - (*block).GetSize().x <= kSize &&
                   position_.x - (*block).GetPosition().x - (*block).GetSize().x >= 0 &&
                  position_.y >= (*block).GetPosition().y &&
                  position_.y <= (*block).GetPosition().y + (*block).GetSize().y) {//downward
            if (velocity_.x < 0) {
                velocity_.x = - velocity_.x;
                if ((*block).IsBreakable()) {
                    blocks.erase(block);
                    break;
                }
            }
        } else if ((*block).GetPosition().x - position_.x <= kSize &&
                   (*block).GetPosition().x - position_.x >= 0 &&
                   position_.y >= (*block).GetPosition().y &&
                   position_.y <= (*block).GetPosition().y + (*block).GetSize().y) {
            if (velocity_.x > 0) {
                velocity_.x = - velocity_.x;
                if ((*block).IsBreakable()) {
                    blocks.erase(block);
                    break;
                }
            }
        }else if (CanCollideCorner(&*block)) {
                float temp = velocity_.x;
                velocity_.x = velocity_.y;
                velocity_.y = temp;
                if ((*block).IsBreakable()) {
                    blocks.erase(block);
                    break;
                }
            }
        }
    }


    void Particle::CollideWithBoard(Board* board) {
        if (abs(position_.y - board->GetPosition().y) <= kSize &&
            position_.x >= board->GetPosition().x &&
            position_.x <= board->GetPosition().x + board->GetSize().x) {//upward
            if (velocity_.y > 0) {
                velocity_.y = - velocity_.y;
            }
            if (board->GetVelocity().x > 0) {
                double x = velocity_.x;
                velocity_.x ++;
                if (velocity_.y > 0) {
                    velocity_.y = (float) sqrt(velocity_.y * velocity_.y + x * x - velocity_.x * velocity_.x);
                } else {
                    velocity_.y = (float) -sqrt(velocity_.y * velocity_.y + x * x - velocity_.x * velocity_.x);
                }

            } else if (board->GetVelocity().x < 0) {
                double x = velocity_.x;
                velocity_.x--;
                if (velocity_.y > 0) {
                    velocity_.y = (float) sqrt(velocity_.y * velocity_.y + x * x - velocity_.x * velocity_.x);
                } else {
                    velocity_.y = (float) -sqrt(velocity_.y * velocity_.y + x * x - velocity_.x * velocity_.x);
                }
            }
        } else if (abs(position_.y - board->GetPosition().y - board->GetSize().y) <= kSize &&
                   position_.x >= board->GetPosition().x &&
                   position_.x <= board->GetPosition().x + board->GetSize().x) {//downward
            if (velocity_.y < 0) {
                velocity_.y = - velocity_.y;
            }
        } else if (abs(position_.x - board->GetPosition().x) <= kSize &&
                   position_.y >= board->GetPosition().y &&
                   position_.y <= board->GetPosition().y + board->GetSize().y) {//downward
            if (velocity_.x < 0) {
                velocity_.x = - velocity_.x;
            }
        }
    }

    void Particle::SetPosition(vec2 position) {
        position_ = position;
    }

    void Particle::SetVelocity(vec2 velocity) {
        velocity_ = velocity;
    }

    void Particle::Display() const {
        ci::gl::drawSolidCircle(position_, kSize);
    }

    bool Particle::CanCollideCorner(Block *block) {
        vec2 luc = block->GetPosition();
        vec2 ruc = vec2(block->GetPosition().x + block->GetSize().x, block->GetPosition().y);
        vec2 rdc = vec2(block->GetPosition().x + block->GetSize().x, block->GetPosition().y + block->GetSize().y);
        vec2 ldc = vec2(block->GetPosition().x, block->GetPosition().y + block->GetSize().y);
        float x = position_.x;
        float y = position_.y;
        return (luc.x - x) * (luc.x - x) + (luc.y - y) * (luc.y - y) <= kSize * kSize ||
                (ruc.x - x) * (ruc.x - x) + (ruc.y - y) * (ruc.y - y) <= kSize * kSize ||
                (rdc.x - x) * (rdc.x - x) + (rdc.y - y) * (rdc.y - y) <= kSize * kSize ||
                (ldc.x - x) * (ldc.x - x) + (ldc.y - y) * (ldc.y - y) <= kSize * kSize;
    }

    vec2 Particle::GetVelocity() {
        return velocity_;
    }


} // namespace finalproject
