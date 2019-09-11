#include "..\..\inc\loop\Game.hpp"
void Game::start() {
	sf::Music music;
	if (!music.openFromFile("res/music/rubiks_cube.wav")) {
		std::cout << "error" << std::endl;
	}
	music.play();
	music.setLoop(true);
	sf::RenderWindow window(
		sf::VideoMode(GameParameters::SCREEN_WIDTH, GameParameters::SCREEN_HEIGHT),
		"Rubiks Game",
		sf::Style::Fullscreen
	);
	window.setActive(false);
	std::list<ActionObject*> actionObjectPtrs;
	setupInitialObjects(actionObjectPtrs);
	std::mutex deletionMutex;
	std::thread thread(RenderLoop::start, std::ref(window), std::ref(actionObjectPtrs), std::ref(deletionMutex));
	ActionLoop::start(window, actionObjectPtrs, deletionMutex);
	thread.join();
}

void Game::setupInitialObjects(std::list<ActionObject*>& actionSpritesPtrs) {
	RubiksCube* rubiks = new RubiksCube();
	setupRubiksObjects(actionSpritesPtrs, rubiks);
	actionSpritesPtrs.emplace_back(new InstructionsButton());
	actionSpritesPtrs.emplace_back(new InstructionsText());
	actionSpritesPtrs.emplace_back(new BeginButton());
	actionSpritesPtrs.emplace_back(new BeginText());
	actionSpritesPtrs.emplace_back(new TitleShape());
	actionSpritesPtrs.emplace_back(new Title(rubiks));
}

void Game::setupRubiksObjects(std::list<ActionObject*>& actionSpritesPtrs, RubiksCube* rubiks) {
	int midXScreen = (GameParameters::SCREEN_WIDTH - 50) / 2;
	int midYScreen = (GameParameters::SCREEN_HEIGHT - 50) / 2;
	for (int face = FRONT_FACE; face < NUM_FACES; face++) {
		placeFace(actionSpritesPtrs, rubiks, static_cast<Faces>(face));
	}
}

void Game::placeFace(std::list<ActionObject*>& actionSpritesPtrs, RubiksCube* rubiks, Faces face) {
	int xFaceOffset = 0;
	int yFaceOffset = 0;
	switch (face) {
	case TOP_FACE:
		yFaceOffset -= 150;
		break;
	case LEFT_FACE:
		xFaceOffset -= 150;
		break;
	case FRONT_FACE:
		break;
	case RIGHT_FACE:
		xFaceOffset += 150;
		break;
	case BACK_FACE:
		xFaceOffset += 300;
		break;
	case BOTTOM_FACE:
		yFaceOffset += 150;
		break;
	}
	Game::placeSquares(actionSpritesPtrs, rubiks, xFaceOffset, yFaceOffset, face);
}

void Game::placeSquares(std::list<ActionObject*>& actionSpritesPtrs, RubiksCube* rubiks, int xFaceOffset, int yFaceOffset, Faces face) {
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		switch (position) {
		case TOP_LEFT:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset - 50, 
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset - 50, 
				rubiks->thisCube[face][position]));
			break;
		case TOP:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset - 50,
				rubiks->thisCube[face][position]));
			break;
		case TOP_RIGHT:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset + 50,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset - 50,
				rubiks->thisCube[face][position]));
			break;
		case LEFT:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset - 50,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset,
				rubiks->thisCube[face][position]));
			break;
		case CENTER:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset,
				rubiks->thisCube[face][position]));
			break;
		case RIGHT:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset + 50,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset,
				rubiks->thisCube[face][position]));
			break;
		case BOTTOM_LEFT:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset - 50,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset + 50,
				rubiks->thisCube[face][position]));
			break;
		case BOTTOM:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset + 50,
				rubiks->thisCube[face][position]));
			break;
		case BOTTOM_RIGHT:
			actionSpritesPtrs.emplace_back(new RubiksSquare(
				(GameParameters::SCREEN_WIDTH - 50) / 2 + xFaceOffset + 50,
				(GameParameters::SCREEN_HEIGHT - 50) / 2 + yFaceOffset + 50,
				rubiks->thisCube[face][position]));
			break;
		}
	}
}

