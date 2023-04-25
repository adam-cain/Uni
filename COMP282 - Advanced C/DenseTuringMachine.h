#ifndef DENSETURINGMACHINE_H_
#define DENSETURINGMACHINE_H_
#include "TuringMachine.h"
#include <vector>
class DenseTuringMachine : public TuringMachine {
public:
	DenseTuringMachine(int x, int y);
	TuringMachineState* find(int x,int y);
	void add(TuringMachineState& s);
	std::vector<TuringMachineState>* getAll();
};

#endif /* DENSETURINGMACHINE_H_ */
