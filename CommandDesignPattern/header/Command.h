#pragma once

#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include "Character.h"

class Command {
public:
	virtual void execute(Character& c) = 0;
	virtual void undo(Character& c) const = 0;
	virtual ~Command() = default;
};

#endif