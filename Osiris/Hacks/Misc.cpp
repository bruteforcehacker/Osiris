#include "../Config.h"
#include "../Memory.h"
#include "Misc.h"

void Misc::autoStrafe(UserCmd* cmd)
{
    
}

void Misc::bunnyHop(UserCmd* cmd)
{
    if (config.misc.bunnyHop) {
        static auto bJumped = false;
        static auto bFake = false;
        if (!bJumped && bFake) {
            bFake = false;
            cmd->buttons |= 2;
        }
        else if (cmd->buttons & 2) {
            if (*((*memory.localPlayer)->getFlags()) & 1) {
                bJumped = true;
                bFake = true;
            }
            else {
                cmd->buttons &= ~2;
                bJumped = false;
            }
        }
        else {
            bJumped = false;
            bFake = false;
        }
    }
}