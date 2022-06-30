#include <iostream>
#include <vector>
#include <random>

using std::cout, std::endl;

int main() {
	const int PRISONER_COUNT = 100;
	const int N = 1000000;


	std::random_device rd;
	std::default_random_engine rng(rd());

	std::vector<int> numbers;
	for (int i = 0; i < PRISONER_COUNT; i++)
		numbers.push_back(i);

	auto runExperiment = [](const std::vector<int> &numbers){
		for (int j = 0; j < PRISONER_COUNT; j++){
			int nextBox = j;
			bool success = false;
			for (int i = 0; i < PRISONER_COUNT / 2; i++){
				nextBox = numbers[nextBox];
				if (nextBox == j){

					if (i == PRISONER_COUNT / 2 - 1)
						return true;

					success = true;
					break;
				}
			}
			if (!success) return false;
		}
		return true;
	};

	int success = 0;
	for (int i = 0; i < N; i++){
		std::shuffle(numbers.begin(), numbers.end(), rng);
		if (runExperiment(numbers)) success++;
	}
	cout << double(success) / N << endl;

	return 0;
}
