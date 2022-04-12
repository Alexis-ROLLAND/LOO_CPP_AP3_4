#include "Rectangle.hpp"

//----------------------------------------------------------------------
Rectangle::Rectangle(float LowLevel, float HighLevel, float Period, float Ton, float tStop, unsigned int NbPoints):Signal(tStop,NbPoints),LowLevel{LowLevel},HighLevel{HighLevel},Period{Period},Ton{Ton}{
	
	RefreshAlpha();
}
//----------------------------------------------------------------------
void	Rectangle::RefreshAlpha()const{

if (this->Period <= 0) this->Period = defaultPeriod;
if (this->Ton < 0) this->Ton=0;

this->Alpha = this->Ton / this->Period;
if (this ->Alpha > 1) this->Alpha = 1;


}
//----------------------------------------------------------------------
int		Rectangle::Compute()const{
	
	float real_t;
	float tmp;
	
	this->Refresh_dt();
	
	this->tn.clear();
	this->signal_tn.clear();
	
	for (int t=0;t<this->NbPoints;t++){
		real_t = t*dt;
		this->tn.push_back(real_t);
		
		if (fmod(real_t,this->Period) <= this->Ton) tmp = this->HighLevel;	// Use fmod to calculate with a "real t" inside [0;Period]
		else tmp = this->LowLevel;
		
		this->signal_tn.push_back(tmp);
		}
	
	this->needToCompute=false;
	return 0;
} 
//----------------------------------------------------------------------


