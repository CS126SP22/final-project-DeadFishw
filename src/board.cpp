//
// Created by 58217 on 2022/4/12.
//

#include "board.h"

void finalproject::Board::Display() const {

}

finalproject::Board::Board(size_t length, size_t width, vec2 position, bool isBreakable) {

}

vec2 finalproject::Board::GetPosition() const {
    return position_;
}

char *finalproject::Board::GetColor() const {
    return "white";
}

void finalproject::Board::AdvanceOneFrame() {
    position_ = vec2(position_.x + speed_, position_.y);
}

void finalproject::Board::SetVelocity(vec2 velocity) {
    velocity_ = velocity;
}

