#pragma once

#ifndef MOVE_H
#define MOVE_H

#include "Command.h"

class Move : public Command{

public:
	void execute(Character& c) override;
	void undo(Character& c) const override;
private:
	int m_X, m_Y;
};

#endif

