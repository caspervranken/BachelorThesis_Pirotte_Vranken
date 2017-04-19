#include "collisions/Paths.h"
#include "ist/Sphere.h"
#include <vector>
#include <iostream>

using namespace std;

namespace chai3d {

	Paths::Paths(int aantalVrijheidsgraden) {
		this->aantalVrijheidsgraden = aantalVrijheidsgraden;
	}

	Paths::~Paths() {}

	vector<Sphere*> Paths::get(int index, bool a) {
		if (a) {
			return pathsA[index];
		}
		return pathsB[index];
	}

	vector<Sphere*> Paths::getA(int index) {
		return this->get(index, true);
	}

	vector<Sphere*> Paths::getB(int index) {
		return this->get(index, false);
	}

	vector<Sphere*> Paths::getSpheresAtDepth(int index, bool a) {

		vector<Sphere*> spheres;

		for (int i = 0; i < aantalVrijheidsgraden; i++) {
			if (this->get(i, a).size() <= (index)) continue;
			spheres.push_back(this->get(i, a)[index]);
		}

		return spheres;
	}

	vector<Sphere*> Paths::getSpheresAtDepthA(int index) {
		return this->getSpheresAtDepth(index, true);
	}

	vector<Sphere*> Paths::getSpheresAtDepthB(int index) {
		return this->getSpheresAtDepth(index, false);
	}

	void Paths::popBack(int index, bool a) {
		this->get(index, a).pop_back();
	}

	void Paths::popBackA(int index) {
		this->popBack(index, true);
	}

	void Paths::popBackB(int index) {
		this->popBack(index, false);
	}

	void Paths::pushBack(Sphere* s, int index, bool a) {
		this->get(index, a).push_back(s);
	}

	void Paths::pushBackA(Sphere* s, int index) {
		this->pushBack(s, index, true);
	}

	void Paths::pushBackB(Sphere* s, int index) {
		this->pushBack(s, index, false);
	}

} // chai3d