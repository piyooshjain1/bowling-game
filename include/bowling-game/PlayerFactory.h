#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "Player.h"

class PlayerFactory {
public:
    static Player* createPlayer(const std::string& name);
};

#endif // PLAYERFACTORY_H