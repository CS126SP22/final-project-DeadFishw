//
// Created by 58217 on 2022/4/12.
//

#include "board.h"

void finalproject::Board::Display() const {
    ci::gl::drawSolidRect(ci::Rectf(position_, vec2(position_.x+ length_, position_.y + width_)));
}

finalproject::Board::Board(size_t length, size_t width, vec2 position) {
    length_ = length;
    width_ = width;
    position_ = position;
}

vec2 finalproject::Board::GetPosition() const {
    return position_;
}

char *finalproject::Board::GetColor() const {
    return "white";
}

void finalproject::Board::AdvanceOneFrame() {
    position_ = vec2(position_.x + velocity_.x, position_.y);
    if (position_.x < 0) {
        position_.x = 0;
    }
}

void finalproject::Board::SetVelocity(vec2 velocity) {
    velocity_ = velocity;
}

finalproject::Board::Board() {

}

vec2 finalproject::Board::GetSize() const {
    return glm::vec2(length_, width_);
}

vec2 finalproject::Board::GetVelocity() const {
    return velocity_;
}

