
#include "Sinus.hpp"

//----------------------------------------------------------------------
Sinus::Sinus(float A0, float Amplitude, float Omega, float Phi0, float tStop, unsigned int NbPoints):Signal(tStop,NbPoints),A0{A0},Amplitude{Amplitude},Omega{Omega},Phi0{Phi0}{
	
	while(this->Phi0 > (2*pi)) this->Phi0 -= (2*pi); 	// Phi0 ramenée, si nécessaire dans [0;2PI] 
}

//----------------------------------------------------------------------
void	Sinus::setPhi0(float Phi0){
	
	this->Phi0 = Phi0;
	
	while(this->Phi0 > (2*pi)) this->Phi0 -= (2*pi); 	// Phi0 ramenée, si nécessaire dans [0;2PI] 
	this->needToCompute=true;
}
//----------------------------------------------------------------------
int		Sinus::Compute()const{
	float real_t;
	float tmp;
	
	this->Refresh_dt();
	
	this->tn.clear();
	this->signal_tn.clear();
	
	for (int t=0;t<NbPoints;t++){
		real_t = t*dt;
		this->tn.push_back(real_t);
		
		tmp = (Omega * real_t) + this->Phi0;
		tmp = sin(tmp);
		tmp *= this->Amplitude;
		tmp += this->A0;
		
		this->signal_tn.push_back(tmp);
	}
	
	this->needToCompute=false;
	return 0;
}

