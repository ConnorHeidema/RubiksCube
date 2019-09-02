#pragma once
#include "AlgorithmStep.hpp"
class AlignBottomCornerStep :
	public AlgorithmStep {
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual  std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed) override;
	bool alignCorner(std::list<std::string>& , InteractableCube& cube, int maxMovesAllowed);

	void movements1(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements2(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements3(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements4(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements5(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements6(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements7(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements8(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements9(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements10(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
	void movements11(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed);
};
