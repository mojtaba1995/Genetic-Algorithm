#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>
#define genenumber 2
#define choromozomenumber 22
#define generationnumber 200
#define percent 5
#define tops 2
#define mutationnumber 2
#define mutationrange 10

using namespace std;
class gene;
class choromozome;
class generation;
float func(choromozome);
choromozome child(choromozome, choromozome, int);
choromozome child2(choromozome, choromozome, int);
generation nextgen(generation);
generation randompick(generation);
generation children(generation);
generation mutate(generation);


class gene {
public:
	float value;

	float getvalue() {
		return value;
	}
	void setvalue(float setvalue) {
		value = setvalue;
	}

	void mutate(float mutationvalue) {
		value = value + mutationvalue;
	}
	void mutate() {
		float random;
		// random has problem
		random = rand() / (RAND_MAX / 100);
		value = value + random;
	}

};

class choromozome {
public:
	gene value[genenumber];

	void setgene(int genenumber1, float genevalue) {
		value[genenumber1].setvalue(genevalue);
	}
	void setgene(gene gene, int position) {
		value[position].setvalue(gene.getvalue());

	}
	void setchorome(choromozome a) {
		int i;
		for (i = 0; i < genenumber; ++i) {
			value[i] = (a.getgene(i));
		}

	}

	gene getgene(int genenumber1) {
		return value[genenumber1];
	}

	void genemutate(int genenum, float mutationvalue) {
		value[genenum].mutate(mutationvalue);
	}
	void fillrandom() {
		int i;
		int random;
		for (i = 0; i < genenumber; ++i) {
			random = rand() / (RAND_MAX / 100);
			//we need float not int
			value[i].setvalue(random);
		}
	}
	void fillone() {
		int i;
		for (i = 0; i < genenumber; ++i) {
			value[i].setvalue(6);
		}
	}


};


class generation {
public:
	choromozome chorome[choromozomenumber];

	choromozome getchorome(int i) {
		return chorome[i];
	}
	void setchorome(choromozome a, int b) {
		chorome[b].setchorome(a);

	}


	void setgeneration(generation a) {
		int i;
		for (i = 0; i < choromozomenumber; ++i) {
			chorome[i].setchorome(a.getchorome(i));
		}
	}


	void fillrandom() {
		int i, random;
		for (i = 0; i < choromozomenumber; ++i) {
			random = rand() / (RAND_MAX / 100);
			chorome[i].fillrandom();
		}
	}
	void fillone() {
		int i;
		for (i = 0; i < choromozomenumber; ++i) {
			chorome[i].fillone();
		}

	}
	void showall() {
		int i, j;
		float k;
		for (i = 0; i < choromozomenumber; ++i) {
			cout << "\n";
			for (j = 0; j < genenumber; ++j) {
				k = chorome[i].getgene(j).getvalue();
				cout << k << " ";
			}
		}
	}
	void mutate() {
		int random, random2, random3, random4;
		int i;
		for (i = 0; i < mutationnumber; ++i) {
			random = rand() / (RAND_MAX / choromozomenumber);
			random2 = rand() / (RAND_MAX / genenumber);
			random3 = rand() / (RAND_MAX / mutationrange);
			random4 = rand() / (RAND_MAX / 2);
			//cout << random3 << "\n";
			//cout << random4<<"\n";
			if (random4 == 1) {
				chorome[random].genemutate(random2, random3);
				//chorome[random].getgene(random2).setvalue(7);
				//cout << "\n" << a.getchorome(random).getgene(1).getvalue() << "\n";
				//a.showall();

			}
			else {
				chorome[random].genemutate(random2, -random3);

			}
			//a.showall();

		}

	}
	float findmax() {
		int n, c, d;
		int i;
		float swap, swap2;
		//choromozome ch[choromozomenumber];
		float z[choromozomenumber][2];

		for (i = 0; i < choromozomenumber; ++i) {
			//ch[i].setchorome(a.getchorome(i));

			z[i][0] = func(chorome[i]);
			z[i][1] = i;
			//st functions 
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
		}


		n = choromozomenumber;
		for (c = 0; c < (n - 1); c++)
		{
			for (d = 0; d < n - c - 1; d++)
			{
				if (z[d][0] > z[d + 1][0])
				{

					swap = z[d][0];
					z[d][0] = z[d + 1][0];
					z[d + 1][0] = swap;

					swap2 = z[d][1];
					z[d][1] = z[d + 1][1];
					z[d + 1][1] = swap2;
				}
			}
		}
		i = z[choromozomenumber - 1][1];
		//cout << z[0][0] << "\n";
		//cout << z[0][0] << "\n";
		return z[choromozomenumber - 1][0];
	}
};





int main() {
	generation gen[generationnumber];
	int i;
	// for real random num generating 
	srand(time(NULL));
	//filling generation with random numbers
	//	for(i=0;i<generationnumber;++i){
	//	random = rand ()/(RAND_MAX/100);
	gen[0].fillrandom();
	//gen[0].fillone();

	//	}
	//making second generation
	//gen[1].nextgen 
	for (i = 0; i < generationnumber - 1; ++i) {
		// get some of choromozomes
		gen[i + 1].setgeneration(randompick(gen[i]));
		// make childeren
		gen[i + 1].setgeneration(children(gen[i + 1]));
		//mutation
		//gen[i + 1].showall();
		//gen[i+1].setgeneration(mutate(gen[i+1]));
		gen[i + 1].mutate();
		//cout << "\n" << "--------------";
		//gen[i + 1].showall();
	}

	//cout << gen[1].getchorome(0).getgene(0).getvalue();
	//cout << '\n';


	cout << '\n';

	//cout <<"max = "<< findmax(gen[generationnumber-1]);
	gen[generationnumber - 1].showall();
	cout << "\n";
	cout << "max = " << gen[generationnumber - 1].findmax();
	cin >> i;
	return 0;
}


float func(choromozome input) {
	float result;
	int i;
	result = 0;
	result = input.getgene(0).getvalue() + 3 * input.getgene(1).getvalue();
	return result;
}

generation children(generation a) {
	generation b;
	choromozome c1, c2;
	int i;
	int random;

	for (i = 0; i < choromozomenumber; i = i + 2) {
		random = rand() / (RAND_MAX / genenumber);

		c1.setchorome(child(a.getchorome(i), a.getchorome(i + 1), random));
		c2.setchorome(child2(a.getchorome(i), a.getchorome(i + 1), random));
		b.setchorome(c1, i);
		if (i + 1 < choromozomenumber) {
			b.setchorome(c2, i + 1);
		}
	}

	return b;
}

choromozome child(choromozome a, choromozome b, int d) {
	choromozome c;
	int i;
	for (i = 0; i < d; ++i) {
		c.setgene(a.getgene(i), i);
	}
	for (i = d; i < genenumber; ++i) {
		c.setgene(b.getgene(i), i);
	}
	return c;
}

choromozome child2(choromozome a, choromozome b, int d) {
	choromozome c;
	//	int random ;
	int i;
	//		random = rand //()/(RAND_MAX/genenumber);
	for (i = 0; i < d; ++i) {
		c.setgene(b.getgene(i), i);
	}
	for (i = d; i < genenumber; ++i) {
		c.setgene(a.getgene(i), i);
	}
	return c;

}


