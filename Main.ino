#define HB_INPUT1_PIN 6
#define HB_INPUT2_PIN 10
#define HB_INPUT3_PIN 5
#define HB_INPUT4_PIN 9

int incomingByte = 0;
char data = 0;

void setup() {
	Serial.begin(9600);
	pinMode(HB_INPUT1_PIN, OUTPUT);
	digitalWrite(HB_INPUT1_PIN, LOW); // When not sending PWM, we want it low
	pinMode(HB_INPUT2_PIN, OUTPUT);
	digitalWrite(HB_INPUT2_PIN, LOW); // When not sending PWM, we want it low
	pinMode(HB_INPUT3_PIN, OUTPUT);
	digitalWrite(HB_INPUT3_PIN, LOW); // When not sending PWM, we want it low
	pinMode(HB_INPUT4_PIN, OUTPUT);
	digitalWrite(HB_INPUT4_PIN, LOW); // When not sending PWM, we want it low
}


void moveStop (int time) {
	analogWrite(HB_INPUT1_PIN, LOW);
	analogWrite(HB_INPUT2_PIN, LOW);
	analogWrite(HB_INPUT3_PIN, LOW);
	analogWrite(HB_INPUT4_PIN, LOW);
}

void moveRight (int time) {
	analogWrite(HB_INPUT1_PIN, 150);
	analogWrite(HB_INPUT2_PIN, LOW);
	analogWrite(HB_INPUT3_PIN, 150);
	analogWrite(HB_INPUT4_PIN, LOW);
	delay(time);
}

void moveLeft (int time) {
	analogWrite(HB_INPUT1_PIN, LOW);
	analogWrite(HB_INPUT2_PIN, 150);
	analogWrite(HB_INPUT3_PIN, LOW);
	analogWrite(HB_INPUT4_PIN, 150);
	delay(time);
}

void moveBack (int time) {
	analogWrite(HB_INPUT1_PIN, LOW);
	analogWrite(HB_INPUT2_PIN, 150);
	analogWrite(HB_INPUT3_PIN, 150);
	analogWrite(HB_INPUT4_PIN, LOW);
	delay(time);
}

void moveForward (int time) {
	analogWrite(HB_INPUT1_PIN, 150);
	analogWrite(HB_INPUT2_PIN, LOW);
	analogWrite(HB_INPUT3_PIN, LOW);
	analogWrite(HB_INPUT4_PIN, 150);
	delay(time);
}

void loop() {
	if (Serial.available() > 0) {
		data = Serial.read();
		Serial.print(data);
		Serial.print("\n");

		switch (data) {
			case 'F' :
				moveForward(500);
				break;
			case 'B' :
				moveBack(500);
				break;
			case 'L' :
				moveLeft(500);
				break;
			case 'R':
				moveRight(500);
				break;
			case 'S' :
				moveStop(0);
				break;
			default :
				moveStop(0);
		}
	}
	moveStop(0);
}
