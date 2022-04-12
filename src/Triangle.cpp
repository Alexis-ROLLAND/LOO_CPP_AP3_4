#include "Triangle.hpp"

//----------------------------------------------------------------------
Triangle::Triangle(float LowLevel, float HighLevel, float Period, float Trise, float tStop, unsigned int NbPoints):Signal(tStop,NbPoints),LowLevel{LowLevel},HighLevel{HighLevel},Period{Period},Trise{Trise}{
	
	RefreshSymetry();
}
//----------------------------------------------------------------------
void	Triangle::RefreshSymetry()const{

if (this->Period <= 0) this->Period = defaultPeriod;
if (this->Trise < 0) this->Trise=this->Period;

this->Symetry = Trise / Period;
if (this ->Symetry > 1) this->Symetry = 1;


}
//----------------------------------------------------------------------
int		Triangle::Compute()const{
	
	float real_t;
	float tmp;
	float a_rise, a_fall,b;
	
	this->Refresh_dt();
	
	this->tn.clear();
	this->signal_tn.clear();
	
	a_rise = (this->HighLevel - this->LowLevel) / this->Trise ;
	a_fall = -((this->HighLevel - this->LowLevel)/(this->Period - this->Trise));
		
	b = this->HighLevel - (a_fall * this->Trise);
	
	
	for (int t=0;t<this->NbPoints;t++){
		real_t = t*dt;
		this->tn.push_back(real_t);
		
		// Calcul - using fmod to prevent tStop > Period
		if (fmod(real_t,this->Period) <= this->Trise){
			tmp = (  a_rise * fmod(real_t,this->Period) ) + this->LowLevel;
			
		}
		else{
			tmp = a_fall * fmod(real_t,this->Period) + b;
		}	
		this->signal_tn.push_back(tmp);
	}
	this->needToCompute=false;
	return 0;
} 
//----------------------------------------------------------------------


