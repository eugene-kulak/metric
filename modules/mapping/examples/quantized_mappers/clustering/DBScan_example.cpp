
#include "../details/classification/metric_classification.hpp"

#include "assets/helpers.cpp" // csv reader

#include <variant>

#include <deque> // for Record test

#include "../details/classification/details/correlation_weighted_accuracy.hpp"
#include "../details/classification/details/3rdparty/metric_clustering/clustering.hpp"



int main()
{
	std::cout << "we have started" << std::endl;
	std::cout << '\n';

	std::vector<std::vector<float>> data{
		   {0, 0, 0, 0, 0},
		   {1.74120000000000, 4.07812000000000, -0.0927036000000, 41.7888000000000, 41.7888000000000},
		   {7.75309000000000, 16.2466000000000, 3.03956000000000, 186.074000000000, 186.074000000000},
		   {2.85493000000000, 3.25380000000000, 2.50559000000000, 68.5184000000000, 68.5184000000000},
		   {5.81414000000000, 8.14015000000000, 3.22950000000000, 139.539000000000, 139.539000000000},
		   {2.57927000000000, 2.63399000000000, 2.46802000000000, 61.9026000000000, 61.9026000000000} };

	auto[assignments, seeds, counts] = clustering::dbscan(data, (float) 64.0, 1); // clusters the data in 4 groups.


	std::cout << "assignments:" << std::endl;
	for (size_t i = 0; i < assignments.size(); i++)
	{
		if (i < assignments.size() - 1)
		{
			std::cout << assignments[i] << ", ";
		}
		else
		{
			std::cout << assignments[i] << std::endl;
		}
	}
	std::cout << '\n';

	std::cout << "seeds:" << std::endl;
	for (size_t i = 0; i < seeds.size(); i++)
	{
		if (i < seeds.size() - 1)
		{
			std::cout << seeds[i] << ", ";
		}
		else
		{
			std::cout << seeds[i] << std::endl;
		}
	}
	std::cout << '\n';

	std::cout << "counts:" << std::endl;
	for (size_t i = 0; i < counts.size(); i++)
	{
		if (i < counts.size() - 1)
		{
			std::cout << counts[i] << ", ";
		}
		else
		{
			std::cout << counts[i] << std::endl;
		}
	}
	std::cout << '\n' << std::endl;

	return 0;

}
