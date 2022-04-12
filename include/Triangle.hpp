#ifndef __TRIANGLE_H__
#define	__TRIANGLE_H__

#include "Signal.hpp"


constexpr	float 	defaultTrise = 0.5;

class Triangle:public Signal{
	private:
	
	// Signal caractéristics
	
	float 	LowLevel;		// Niveau à l'état bas
	float 	HighLevel;		// Niveau à l'état haut
	mutable float 	Period;			// Période 
	mutable float 	Trise;			// temps de montée
	mutable float 	Symetry;		// tRise / T
	
	int		Compute()const ;	
	void	RefreshSymetry()const;
		
	public:
	Triangle():Triangle(defaultLowLevel,defaultHighLevel,defaultPeriod,defaultTrise,defaulttStop,defaultNbPoints){};	// Default Ctor 1Hz Square Wave - LowLevel = -1,  HighLevel = 1, using the delegated Ctor
	Triangle(float LowLevel, float HighLevel, float Period, float Trise, float tStop=defaulttStop, unsigned int NbPoints=defaultNbPoints); // Delegated Ctor
	virtual ~Triangle(){};
	

	// Accessors
	void	setLowLevel(float LowLevel){this->LowLevel = LowLevel;this->needToCompute=true;};
	float 	getLowLevel()const{return this->LowLevel;};
	
	void	setHighLevel(float HighLevel){this->HighLevel = HighLevel;this->needToCompute=true;};
	float 	getHighLevel()const{return this->HighLevel;};
	
	void 	setPeriod(float Period){this->Period = Period;this->needToCompute=true;};
	float 	getPeriod()const{return this->Period;};
	
	void 	setTrise(float Trise){this->Trise = Trise;this->needToCompute=true;};
	float 	getTrise()const{return this->Trise;};

	float 	getSymetry()const{this->RefreshSymetry();return this->Symetry;};

	
};
#endif

