#ifndef __NOISE_H__
#define	__NOISE_H__

#include <ctime>

#include "Signal.hpp"

constexpr	float 	defaultMean = 0;

class Noise:public Signal{
	private:
	
	// Signal caractéristics
	float 	Mean;		// Composante continue
	float 	Amplitude;	// Amplitude (Max = Mean+Amplitude, Min = Mean-Amplitude)
	int		Compute()const ;
	
	public:
	Noise():Noise(defaultMean,defaultAmplitude,defaulttStop,defaultNbPoints){};	// Default Ctor CC=0, Amplitude=1, using the delegated Ctor
	Noise(float Mean, float Amplitude, float tStop=defaulttStop, unsigned int NbPoints=defaultNbPoints):Signal(tStop,NbPoints),Mean{Mean},Amplitude{Amplitude}{std::srand(std::time(nullptr));}; // use current time as seed for random generator - Delegated Ctor
	virtual ~Noise(){};
	
	// Accessors
	void	setMean(float Mean){this->Mean = Mean;this->needToCompute=true;};
	float 	getMean()const{return this->Mean;};
	
	void	setAmplitude(float Amplitude){this->Amplitude = Amplitude;this->needToCompute=true;};
	float 	getAmplitude()const{return this->Amplitude;};
};

#endif
