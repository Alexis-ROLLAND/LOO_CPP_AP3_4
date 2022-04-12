#include "Noise.hpp"

int		Noise::Compute()const{

	float real_t;
	float tmp;
	
	this->Refresh_dt();
	
	this->tn.clear();
	this->signal_tn.clear();
	
	for (int t=0;t<NbPoints;t++){
		real_t = t*dt;
		this->tn.push_back(real_t);
		
		tmp = (float)std::rand() / (float)RAND_MAX;	// float number between 0 and 1
		tmp = tmp * 2 * this->Amplitude;					// Scalling to Peak to Peak
		tmp += (this->Mean-this->Amplitude);					// Offset
		
		this->signal_tn.push_back(tmp);
	}
	this->needToCompute=false;
	return 0;	
}



