//
// Created by 58217 on 2022/4/12.
//

#ifndef FINAL_PROJECT_DEADFISHW_BLOCK_H
#define FINAL_PROJECT_DEADFISHW_BLOCK_H
#pragma once

#include "cinder/gl/gl.h"
using glm::vec2;

namespace finalproject {

/**
 * The particle inside the containers.
 */
    class Block {
    public:
        Block();
        Block(size_t length, size_t width, vec2 position, bool isBreakable);
        vec2 GetPosition() const;
        char* GetColor() const;
        void Display() const;
        bool IsBreakable() const;
    private:
        size_t length_;
        size_t width_;
        bool is_breakable_;
        glm::vec2 position_;
        char* color_;
    };

}
#endif //FINAL_PROJECT_DEADFISHW_BLOCK_H
