#include "Character.h"
#include "Move.h"
#include <vector>
int main() {
	srand(time(NULL));
	std::vector<std::unique_ptr<Command>> command_queue;
	Character bot("Micheal");
	std::unique_ptr<Move> m1 = std::make_unique<Move>();
	std::unique_ptr<Move> m2 = std::make_unique<Move>();
	std::unique_ptr<Move> m3 = std::make_unique<Move>();
	std::unique_ptr<Move> m4 = std::make_unique<Move>();
	
	command_queue.emplace_back(std::move(m1));
	command_queue.emplace_back(std::move(m2));
	command_queue.emplace_back(std::move(m3));
	command_queue.emplace_back(std::move(m4));

	for (int i = 0; i < command_queue.size(); i++) {
		command_queue[i]->execute(bot);
	}

	for (int i = command_queue.size()-1; i >= 0; i--) {
		command_queue[i]->undo(bot);
	}

	return 0;

}