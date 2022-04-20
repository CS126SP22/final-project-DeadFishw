//
// Created by 58217 on 2022/4/12.
//

#include "block.h"

finalproject::Block::Block() {

}

finalproject::Block::Block(size_t length, size_t width, vec2 position, bool isBreakable) {
    length_ = length;
    width_ = width;
    position_ = position;
    is_breakable_ = isBreakable;
}

vec2 finalproject::Block::GetPosition() const {
    return position_;
}

char *finalproject::Block::GetColor() const {
    return nullptr;
}

void finalproject::Block::Display() const {
    ci::gl::drawStrokedRect(ci::Rectf(position_, vec2(length_, width_)));
}

bool finalproject::Block::IsBreakable() const {
    return is_breakable_;
}
