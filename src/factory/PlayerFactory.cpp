#include "PlayerFactory.h"
#include "Player.h"

PlayerFactory::PlayerFactory() {}

Player* PlayerFactory::createPlayer(const std::string& name) {
    return new Player(name);
}