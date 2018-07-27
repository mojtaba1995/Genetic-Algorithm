# Genetic-Algorithm

This code is a GA-based optimization algorithm to optimize a single objective function with integer inputs while it can handle several constraints.
The developed code is based on a project for system engineering course.	

## Getting Started

To compile the program you should run the [Source.cpp](src/Source.cpp) code and it is possible to modify the code using the following guidelines.


### Descriptions 

---------------------------------------------------------------------------------

Using defines that comes below you can control genetic algorithm .
```
define genenumber 2

define choromozomenumber 22

define generationnumber 200

define percent 5

define tops 2

define mutationnumber 2

define mutationrange 10
```
---------------------------------------------------------------------------------
func is your target function.
```
float func(choromozome input) {

	float result;
	
	int i;
	
	result = 0;
	
	result = input.getgene(0).getvalue() + 3 * input.getgene(1).getvalue();
	
  	return result;
  	
}
```
---------------------------------------------------------------------------------
By changing these lines you can change constraints.
```
if (chorome[i].getgene(0).getvalue() > 9) {
	z[i][0] = z[i][0] - 100000;
}
			
if (2 * chorome[i].getgene(0).getvalue() + chorome[i].getgene(1).getvalue() > 22) {
	z[i][0] = z[i][0] - 100000;
}
			
if (chorome[i].getgene(0).getvalue() + 4 * chorome[i].getgene(1).getvalue() > 32) {
	z[i][0] = z[i][0] - 100000;
}
			
if (chorome[i].getgene(0).getvalue() <= 0) {
	z[i][0] = z[i][0] - 100000;
}
			
if (chorome[i].getgene(1).getvalue() <= 0) {
	z[i][0] = z[i][0] - 100000;
}
```		


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


