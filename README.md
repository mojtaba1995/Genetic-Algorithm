# Genetic-Algorithm

This is a simple genetic algorithm code.

---------------------------------------------------------------------------------
Using defines that comes below you can control genetic algorithm 

define genenumber 2
define choromozomenumber 22
define generationnumber 200
define percent 5
define tops 2
define mutationnumber 2
define mutationrange 10
---------------------------------------------------------------------------------
func is your target function 

float func(choromozome input) {
	float result;
	int i;
	result = 0;
	result = input.getgene(0).getvalue() + 3 * input.getgene(1).getvalue();
  	return result;
}
---------------------------------------------------------------------------------
