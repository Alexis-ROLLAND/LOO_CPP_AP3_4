#include <iostream>

#include "Sinus.hpp"
#include "Rectangle.hpp"
#include "Noise.hpp"
#include "Arbitrary.hpp"
#include "Triangle.hpp"


int main(){

	
	Sinus	MySinus(0,5,4*pi,pi/2,1,250);
	const Rectangle	MySquare(0,5,1,0.5,10,1000);
	Noise	MyNoise;
	
	
	//MySinus.Generate("sinus.data");
	
	//MySquare.Generate("square.data");
	
	//MyNoise.Generate("noise.data");
	
	//MyArb.Generate("arb.data");
	
	
	//Sinus	MySinusA,MySinusB;

	/*
	Triangle MyTriangle(0,5,1,0.5,10,1000);
	MyTriangle.Generate("Triangle.data");
	*/
	
	
	/*
	Arbitrary	MyFirstArb;
	MyFirstArb.Generate("sarb1.data");
	*/
	
	/*
	const Sinus	MySinus(0,5,4*pi,pi/2,1,250);
	Arbitrary	MySecondArb(MySinus);
	MySecondArb.Generate("sarb2.data");
	*/
	
	
	Arbitrary 	mainSignal(Rectangle(0,5,1,0.5,2,200));
	Noise		bloodyNoise(0,0.1,2,200);
	
	mainSignal.Generate("mainSignal.data");
	bloodyNoise.Generate("noise.data");
	
	mainSignal.Append(bloodyNoise);
	mainSignal.Generate("mainSignal_with_noise.data");
	
	
	/*
	const Sinus	MySinus(0,5,4*pi,0,1,250);
	Arbitrary 	mainSignal;
	
	mainSignal = MySinus;
	
	MySinus.Generate("sinus.data");
	mainSignal.Generate("mainSignal.data");	
	*/
	
	/*
	Arbitrary 	MainSignal;
	Arbitrary	bloodyNoise(Noise(0,0.1,1,100));
	Arbitrary	MySinus(Sinus(0,2,(4*pi),0,1,100));
	
	MainSignal=MySinus + bloodyNoise;
	
	MySinus.Generate("sinus.data");
	MainSignal.Generate("somme.data");
	*/
	
	/*
	Arbitrary	ArbFromFile(1,std::string("sarb2.data"));
	ArbFromFile.Generate("test.data");
	*/
	
	/*
	Arbitrary	ArbFromFile2(1,std::string("dummy.data"));
	ArbFromFile2.Generate("toto.data");
	*/
	
	
	return 0;
}


