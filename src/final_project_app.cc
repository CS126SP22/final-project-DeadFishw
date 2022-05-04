#include "final_project_app.h"

namespace finalproject {
FinalProjectApp::FinalProjectApp() {
  ci::app::setWindowSize(kWindowLength, kWindowWidth);
}

void FinalProjectApp::draw() {
  ci::Color background_color(0,0,0);
  ci::gl::clear(background_color);
  if (!background_.Ended()) {
      ci::gl::drawString(
              "Press W/D to control the board. Press del to restart",
              glm::vec2(0, 0), ci::Color("white"), ci::Font("Arial", 30.0f));
  } else {
      ci::gl::drawString(
              "The game has ended.",
              glm::vec2(0, 0), ci::Color("white"), ci::Font("Arial", 30.0f));
      return;
  }
  background_.Display();
}

void FinalProjectApp::update() {
    if (background_.Ended()) {
        return;
    }
    background_.AdvanceOneFrame();
}

void FinalProjectApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_DELETE:
            setup();
            break;
        case ci::app::KeyEvent::KEY_a:
            background_.CharacterMove('a');
            break;
        case ci::app::KeyEvent::KEY_d:
            background_.CharacterMove('d');
            break;
  }
}

    void FinalProjectApp::setup() {
        background_.Restart();
    }

}  // namespace idealgas
