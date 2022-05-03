//
// Created by 58217 on 2021/4/29.
//

#ifndef FINAL_PROJECT_DEADFISHW_PARTICLE_H
#define FINAL_PROJECT_DEADFISHW_PARTICLE_H
#pragma once

#include "cinder/gl/gl.h"
#include "board.h"
#include "block.h"

using glm::vec2;

namespace finalproject {
/**
 * The particle inside the containers.
 */
    class Particle {
    public:
        Particle();
        Particle(float, float);
        vec2 GetPosition() const;
        float GetSize() const;
        char* GetColor() const;
        void AdvanceOneFrame();
        void CollideWithBoard(Board* board);
        void CollideWithWall(float length, float width);
        void CollideWithBlocks(std::vector<Block> &blocks);
        void SetPosition(vec2 position);
        void SetVelocity(vec2 velocity);

        void Display() const;

    private:
        glm::vec2 position_;
        glm::vec2 velocity_;
        char* color_;
        const float kSize = 5;

        size_t speed_;


        bool CanCollideCorner(Block *block);
    };
}  // namespace finalproject
#endif //FINAL_PROJECT_DEADFISHW_PARTICLE_H
