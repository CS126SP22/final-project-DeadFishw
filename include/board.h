//
// Created by 58217 on 2022/4/12.
//

#ifndef FINAL_PROJECT_DEADFISHW_BOARD_H
#define FINAL_PROJECT_DEADFISHW_BOARD_H
#include "cinder/gl/gl.h"
using glm::vec2;
namespace finalproject {

/**
 * The particle inside the containers.
 */
    class Board {
    public:
        Board();
        Board(size_t length, size_t width, vec2 position, bool isBreakable);
        vec2 GetPosition() const;
        char* GetColor() const;
        void Display() const;
        void AdvanceOneFrame();



    private:
        size_t length_;
        size_t width_;
        bool is_breakable_;
        glm::vec2 position_;
        char* color_;
        size_t speed_;
    };

}
#endif //FINAL_PROJECT_DEADFISHW_BOARD_H
