#ifndef __SINUS_H__
#define	__SINUS_H__

#include "Signal.hpp"

#include <cmath>

constexpr	float 	pi=3.14159265;

constexpr	float 	defaultA0 = 0;
constexpr	float 	defaultOmega = (2*pi);
constexpr	float 	defaultPhi0 = 0;

class Sinus:public Signal{
	private:
	
	
		
	// Signal caractéristics
	// sin_tn(tn) = A0 + amplitude * sin(omega*tn + phi0)
	float 	A0;		// Composante continue
	float 	Amplitude;	// Amplitude
	float 	Omega;	// pulsation en rad.s-1
	float 	Phi0;	// Phase à l'origine
	int		Compute()const ;
	
	public:
	Sinus():Sinus(defaultA0,defaultAmplitude,defaultOmega,defaultPhi0,defaulttStop,defaultNbPoints){};	// Default Ctor 1Hz sinus - A=1 - No CC using the delegated Ctor
	Sinus(float A0, float Amplitude, float Omega, float Phi0, float tStop=defaulttStop, unsigned int NbPoints=defaultNbPoints); // Delegated Ctor
	virtual ~Sinus(){};
	
	// Accessors
	void	setA0(float A0){this->A0 = A0;};
	float 	getA0()const{return this->A0;};
	
	void	setAmplitude(float Amplitude){this->Amplitude = Amplitude;this->needToCompute=true;};
	float 	getAmplitude()const{return(this->Amplitude);};
	
	void 	setOmega(float Omega){this->Omega = Omega;this->needToCompute=true;};
	float 	getOmega()const{return this->Omega;};
	
	void	setPhi0(float Phi0);	// Need to constraint between 0 and 2PI
	float	getPhi0()const{return this->Phi0;};
		
	
	
		
		
		
		
};
#endif

