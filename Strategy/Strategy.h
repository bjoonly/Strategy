#pragma once

class Strategy {
public:
	virtual ~Strategy() {}
	virtual int Move() = 0;
};

class StrategyPlus7 :public Strategy {
public:
	int Move() {
		return 7;
	}
};
class StrategyPlus4 :public Strategy {
public:
	int Move() {
		return 4;
	}
};
class StrategyPlus2 :public Strategy {
public:
	int Move() {
		return 2;
	}
};
class StrategyMinus1 :public Strategy {
public:
	int Move() {
		return -1;
	}
};
class StrategyMinus3 :public Strategy {
public:
	int Move() {
		return -3;
	}
};
class StrategyMinus6 :public Strategy {
public:
	int Move() {
		return -6;
	}
};
