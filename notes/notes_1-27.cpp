** NOTES 1-27 **

Inheritance 

Example: Bird class 

class Bird { 
	float bodyTemp; 
	int hue; 
	int color; 

	public: 
		Bird(); // default constructor
		Bird(Bird& bird) {  // copy constructor 
			body temp = bird.bodyTemp; 
		} 
		~Bird()
		void fly(); 
		Egg layEgg(); 
		bool isCompatible(bird& bird) // recall passing bird& means you will be passing by value 
} 


class Ostrich {
	float bodyTemp;
	int hue;
	int color;
	int weight;

	public: 
		Ostrich ();
		Ostrich(ostrich&);
		~Ostrich();
		Egg& layegg(); 
}

//////////
/* This allows an ostrich to inherit everything that is in bird */ 
class ostrich:public bird {
	int weight;
	public
			ostrich(ostrich& ost); 


problem....we don't want an ostrich to fly 
	SOLUTION: Use protected access modifier in bird class

	ostrich(float temp):bird(temp); // first call bird(temp) then call ostrich(temp) . if you didnt do this, it would only call bird default constructor 

multiple inheritance exists 
	
class baby: public mom, public dad {
	
}





