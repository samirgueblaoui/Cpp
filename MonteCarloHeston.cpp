#include <iostream>
#include <vector>
#include "MonteCarloHeston.h"

//Impl�mentation du members constructor
MonteCarloH::MonteCarloH(size_t nb_sims, const PathSimulatorSVM& path_sim, const PayoffH& payoff)
	: _number_simulations(nb_sims), _path_simulator_ptr(path_sim.clone()), _payoff_ptr(payoff.clone())
{
}

//impl�mentation de la fonction membre price()
double MonteCarloH::price() const
{
	double price = 0.;

	for (size_t sim_idx = 0; sim_idx < _number_simulations; ++sim_idx)
		price += _payoff_ptr->path_price(_path_simulator_ptr->path());

	price /= _number_simulations;
	// renvoi la moyenne empirique des prix de l'option pour un m�me modele de Heston
	return price;


}


