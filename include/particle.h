//
// Created by 58217 on 2021/4/29.
//

#ifndef FINAL_PROJECT_DEADFISHW_PARTICLE_H
#define FINAL_PROJECT_DEADFISHW_PARTICLE_H
#pragma once

#include "cinder/gl/gl.h"
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

    private:
        glm::vec2 position_;
        char* color_;
        const float kSize = 5;
        size_t speed_;
    };
}  // namespace finalproject
#endif //FINAL_PROJECT_DEADFISHW_PARTICLE_H
