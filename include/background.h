#pragma once

#include "cinder/gl/gl.h"
#include "particle.h"
#include "board.h"
#include "block.h"

#pragma warning( disable: 4819 )
using glm::vec2;

namespace finalproject {

/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
class Background {
 public:
  Background();

  /**
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  vec2 GetSize() const;
  /**
   * Remove all particles from particle.
   */
  void RemoveParticles();

  /**
   * Adding a particle to the vector.
   */
  std::vector<Block> GetWalls();
  void CharacterMove(char command);
  /**
   * Updates the positions and velocities of all particles (based on the rules
   * described in the assignment documentation).
   */
  void AdvanceOneFrame();

  Board GetBoard();

  bool Ended();

    void Restart();

private:
  size_t current_frame_;
  const float kLength = 600.0;
  const float kWidth = 800.0;
  const float kVelocity = 5.0;
  Particle particle;
  std::vector<Block> blocks_;
  Board player_;
  void AddRandomParticle();
};

}  // namespace idealgas
