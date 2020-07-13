//
// Created by Florian on 12.07.2020.
//

#ifndef GDCAPI_PLAYERINFO_H
#define GDCAPI_PLAYERINFO_H

#include "__gdcapimain.h"
#include "GdHandle.h"
#include "HAPIH.h"

namespace gdcapi {

    enum Gamemode {
        Cube = 0,
        Ship = 1,
        Ball = 2,
        UFO = 3,
        Wave = 4,
        Robot = 5,
        Spider = 6
    };

    class PlayerInfo {
    private:
        GdHandle* handle;

    public:
        PlayerInfo(GdHandle* gd);

        bool isPlayerDead();

        Gamemode getGameMode();

        float getX();

        float getY();

        int getCurrentAttempt();

        bool isInPracticeMode();

        std::string& getPlayerName();
    };
}

#endif //GDCAPI_PLAYERINFO_H
