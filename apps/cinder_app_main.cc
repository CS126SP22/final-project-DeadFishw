#include "../include/final_project_app.h"
#include "background.h"

using finalproject::FinalProjectApp;
using finalproject::Background;
using finalproject::Particle;

void prepareSettings(FinalProjectApp::Settings* settings) {
    settings->setResizable(false);
}
// This line is a macro that expands into an "int main()" function.
CINDER_APP(FinalProjectApp, ci::app::RendererGl, prepareSettings);
