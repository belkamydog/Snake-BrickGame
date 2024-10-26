#include "BrickGameController.h"

s21::BrickGameController::BrickGameController() {
    if (current_game_ == TetrisGame){
        game_ = init_new_game();
    }
    else{
        snake_.initNewGame();
    }
    std::cerr << game_.pause << tetris_.game_status;
}

s21::BrickGameController::~BrickGameController() {
    end_and_clear_game();
}

GameInfo_t s21::BrickGameController::sendDataToGui() {
  updateGameState();
  return game_;
}

void s21::BrickGameController::getUserActionFromGui(UserAction_t action) {
    if (current_game_ == SnakeGame){
        snake_.userInput(action);
    }
    else {
        userInput(action);
    }
}

void s21::BrickGameController::setCurrentGame(GamesList_t game) {
    current_game_ = game;
}

void s21::BrickGameController::resetGames() {
    if (current_game_ == TetrisGame){
        game_ = init_new_game();
    }
    else{
        snake_.initNewGame();
    }
}

GameInfo_t s21::BrickGameController::getGameInfo() { return game_; }

void s21::BrickGameController::updateGameState() {
    if (current_game_ == SnakeGame) {
    game_ = snake_.updateCurrentState();
  } else {
    game_ = updateCurrentState();
  }
}
