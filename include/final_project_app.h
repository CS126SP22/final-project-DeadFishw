#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "background.h"
#include "character_particle.h"
#include "particle.h"
#include <fstream>
#include <iostream>

namespace finalproject {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class FinalProjectApp : public ci::app::App {
public:
    FinalProjectApp();
    void draw() override;
    void keyDown(ci::app::KeyEvent event) override;

    const int kWindowLength = 1920;
    const int kWindowWidth = 1080;
private:
    Background background_;
    void setup();
    void update();
};


}  // namespace naivebayes
