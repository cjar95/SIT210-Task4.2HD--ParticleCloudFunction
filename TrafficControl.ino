//Define LED pins
int RED_LED = D7;
int YELLOW_LED = D4;
int GREEN_LED = D2;

// allows the code to run before the cloud is connected
SYSTEM_THREAD(ENABLED);

void setup() {
    
  pinMode(RED_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	
  //Declare particle function
	Particle.function("led", trafficToggle);
	
	//Begin with all lights OFF
	digitalWrite(RED_LED, LOW);
	digitalWrite(YELLOW_LED, LOW);
	digitalWrite(GREEN_LED, LOW);


}

void loop() {

}

int trafficToggle(String command)
{
    if (command == "on1")
    {
        digitalWrite(RED_LED, HIGH);
	    digitalWrite(YELLOW_LED, LOW);
	    digitalWrite(GREEN_LED, LOW);
	    return 1;
    }
    else if (command == "on2")
    {
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(RED_LED, LOW);
    	digitalWrite(GREEN_LED, LOW);
    	return 0;
    }
    else if (command == "on3")
    {
        digitalWrite(GREEN_LED, HIGH);
	    digitalWrite(YELLOW_LED, LOW);
	    digitalWrite(RED_LED, LOW);
	    return 0;
    }
    else
    {
        return -1;
    }
}
