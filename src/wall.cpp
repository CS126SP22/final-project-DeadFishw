//
// Created by 58217 on 2022/4/12.
//

#include "wall.h"

finalproject::Wall::Wall() {

}

finalproject::Wall::Wall(size_t length, size_t width, vec2 position, bool isBreakable) {
    length_ = length;
    width_ = width;
    position_ = position;
    is_breakable_ = isBreakable;
}

vec2 finalproject::Wall::GetPosition() const {
    return position_;
}

char *finalproject::Wall::GetColor() const {
    return nullptr;
}

void finalproject::Wall::Display() const {
    ci::gl::drawStrokedRect(ci::Rectf(position_, vec2(length_, width_)));
}