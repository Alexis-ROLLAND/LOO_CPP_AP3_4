#ifndef __SIGNAL_H__
#define	__SIGNAL_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

constexpr	unsigned int	defaultNbPoints = 100;
constexpr	float 			defaulttStop = 1;

constexpr	float 	defaultAmplitude = 1;	// For Sinuses, Noises

constexpr	float 	defaultLowLevel = -1;	// For Rectangles, Triangles
constexpr	float 	defaultHighLevel = 1;	// For Rectangles, Triangles
constexpr	float 	defaultPeriod = 1;		// For Rectangles, Triangles

class Signal{
	private:
	
	virtual int		Compute()const = 0;
	
	
	protected:
	// Internal stuff
	mutable std::vector<float> tn;
	mutable std::vector<float> signal_tn;
	mutable float 	dt;
	
	// Simulation parameters
	const 	float 			tStart = 0;	 
	mutable	float 			tStop;
	mutable unsigned int	NbPoints;
	
	void	Refresh_dt()const;
	mutable bool	needToCompute;
	
	Signal& operator=(const Signal&);
	
	public:
	
	// Ctors - Dtor
	Signal(float tStop=defaulttStop, unsigned int NbPoints=defaultNbPoints);

	virtual ~Signal(){};
	
	// Accessors
	void	setNbPoints(int NbPoints){this->NbPoints = NbPoints;this->needToCompute=true;};
	unsigned int	getNbPoints()const{return this->NbPoints;};	
	
	void	settStop(float tStop){this->tStop = tStop;this->needToCompute=true;};
	float 	gettStop()const{return this->tStop;};
	
	float 	getdt()const{this->Refresh_dt();return this->dt;};		// Refresh dt before return the value,  be aware that needToCOmpute will be set to true 
	float 	getValtn(int Pos)const;
	float 	getValsignal_tn(int Pos)const;
	
	// Generate function
	int		Generate(std::string FileName="signal.data")const;	
		
};
#endif

