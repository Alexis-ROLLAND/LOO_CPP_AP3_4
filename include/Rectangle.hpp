#ifndef __RECTANGLE_H__
#define	__RECTANGLE_H__

#include "Signal.hpp"

constexpr	float 	defaultTon = 0.5;

class Rectangle:public Signal{
	private:
	
	// Signal caractéristics
	
	float 	LowLevel;		// Niveau à l'état bas
	float 	HighLevel;		// Niveau à l'état haut
	mutable float 	Period;			// Période 
	mutable float 	Ton;			// Durée de l'état haut
	mutable float 	Alpha;			// Rapport Cyclique (read-only)
	
	int		Compute()const ;	
	void	RefreshAlpha()const;
		
	public:
	Rectangle():Rectangle(defaultLowLevel,defaultHighLevel,defaultPeriod,defaultTon,defaulttStop,defaultNbPoints){};	// Default Ctor 1Hz Square Wave - LowLevel = -1,  HighLevel = 1, using the delegated Ctor
	Rectangle(float LowLevel, float HighLevel, float Period, float Ton, float tStop=defaulttStop, unsigned int NbPoints=defaultNbPoints); // Delegated Ctor
	virtual ~Rectangle(){};
	

	// Accessors
	void	setLowLevel(float LowLevel){this->LowLevel = LowLevel;this->needToCompute=true;};
	float 	getLowLevel()const{return this->LowLevel;};
	
	void	setHighLevel(float HighLevel){this->HighLevel = HighLevel;this->needToCompute=true;};
	float 	getHighLevel()const{return this->HighLevel;};
	
	void 	setPeriod(float Period){this->Period = Period;this->needToCompute=true;};
	float 	getPeriod()const{return this->Period;};
	
	void 	setTon(float Ton){this->Ton = Ton;this->needToCompute=true;};
	float 	getTon()const{return this->Ton;};

	float 	getAlpha()const{this->RefreshAlpha();return this->Alpha;};

	
};
#endif

