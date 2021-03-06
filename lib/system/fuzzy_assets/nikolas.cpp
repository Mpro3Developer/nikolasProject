//--------------------------------------------------------------------------------
// Code generated by jFuzzyLogic
// jFuzzyLogic Version : JFuzzyLogic 3.3 (build 2015-04-09), by Pablo Cingolani 
// jFuzzyLogic creted by Pablo Cingolani
//--------------------------------------------------------------------------------


#include <stdio.h>

#include <stdlib.h>
double ruleAccumulationMethod_max(double defuzzifierValue, double valueToAggregate)	{ return ( defuzzifierValue > valueToAggregate ? defuzzifierValue : valueToAggregate ); }

double ruleActivationMethod_min(double degreeOfSupport, double membership)	{ return (degreeOfSupport < membership ? degreeOfSupport : membership); }

double ruleConnectionMethod_and(double antecedent1, double antecedent2)	{ return (antecedent1 < antecedent2 ? antecedent1 : antecedent2); }

class FunctionBlock_Nikolas_motor_speed {

	public: 
	// VAR_INPUT
	double left_midle_sensor;
	double left_sensor;
	double right_middle_sensor;
	double right_sensor;

	// VAR_OUTPUT
	double motor_left;
	double motor_right;

	private: 
	// FUZZIFY left_midle_sensor
	double left_midle_sensor_offline;
	double left_midle_sensor_online;
	double left_midle_sensor_warning;

	// FUZZIFY left_sensor
	double left_sensor_offline;
	double left_sensor_online;
	double left_sensor_warning;

	// FUZZIFY right_middle_sensor
	double right_middle_sensor_offline;
	double right_middle_sensor_online;
	double right_middle_sensor_warning;

	// FUZZIFY right_sensor
	double right_sensor_offline;
	double right_sensor_online;
	double right_sensor_warning;


	// DEFUZZIFY motor_left
	double defuzzify_motor_left[1000];

	// DEFUZZIFY motor_right
	double defuzzify_motor_right[1000];


	public:
	FunctionBlock_Nikolas_motor_speed();
	void calc();
	void print();

	private:
	void defuzzify();
	void fuzzify();
	void reset();
	double membership_left_midle_sensor_offline(double x);
	double membership_left_midle_sensor_online(double x);
	double membership_left_midle_sensor_warning(double x);
	double membership_left_sensor_offline(double x);
	double membership_left_sensor_online(double x);
	double membership_left_sensor_warning(double x);
	double membership_motor_left_fast(double x);
	double membership_motor_left_normal(double x);
	double membership_motor_left_slow(double x);
	double membership_motor_right_fast(double x);
	double membership_motor_right_normal(double x);
	double membership_motor_right_slow(double x);
	double membership_right_middle_sensor_offline(double x);
	double membership_right_middle_sensor_online(double x);
	double membership_right_middle_sensor_warning(double x);
	double membership_right_sensor_offline(double x);
	double membership_right_sensor_online(double x);
	double membership_right_sensor_warning(double x);
	void calc_No1();

};

// Constructor
FunctionBlock_Nikolas_motor_speed::FunctionBlock_Nikolas_motor_speed() {
	motor_left = 0.0;
	motor_right = 0.0;
}

// Calculate function block
void FunctionBlock_Nikolas_motor_speed::calc() {
	reset();
	fuzzify();
	calc_No1();
	defuzzify();
}

// RULEBLOCK No1
void FunctionBlock_Nikolas_motor_speed::calc_No1() {
	// RULE 1 : IF (((right_sensor IS online) AND (right_middle_sensor IS online)) AND (left_midle_sensor IS online)) AND (left_sensor IS online) THEN motor_left IS fast;
	double degreeOfSupport_1 = 1.0 * ( ruleConnectionMethod_and(ruleConnectionMethod_and(ruleConnectionMethod_and(right_sensor_online , right_middle_sensor_online) , left_midle_sensor_online) , left_sensor_online) );
	if( degreeOfSupport_1 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 0.0 + i * 0.255;
			double membership = membership_motor_left_fast(x);
			double y = ruleActivationMethod_min( degreeOfSupport_1 , membership );
			defuzzify_motor_left[i] += ruleAccumulationMethod_max( defuzzify_motor_left[i], y );
		}
	}

	// RULE 2 : IF (((right_sensor IS online) AND (right_middle_sensor IS online)) AND (left_midle_sensor IS online)) AND (left_sensor IS online) THEN motor_right IS fast;
	double degreeOfSupport_2 = 1.0 * ( ruleConnectionMethod_and(ruleConnectionMethod_and(ruleConnectionMethod_and(right_sensor_online , right_middle_sensor_online) , left_midle_sensor_online) , left_sensor_online) );
	if( degreeOfSupport_2 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 0.0 + i * 0.255;
			double membership = membership_motor_right_fast(x);
			double y = ruleActivationMethod_min( degreeOfSupport_2 , membership );
			defuzzify_motor_right[i] += ruleAccumulationMethod_max( defuzzify_motor_right[i], y );
		}
	}

}

// Defuzzify 
void FunctionBlock_Nikolas_motor_speed::defuzzify() {
	double sum_motor_left = 0.0;
	double wsum_motor_left = 0.0;
	for (int i = 0; i < 1000 ; i++ ) {
		double x = 0.0 + i * 0.255;
		sum_motor_left += defuzzify_motor_left[i];
		wsum_motor_left += x * defuzzify_motor_left[i];
	}
	motor_left = wsum_motor_left / sum_motor_left;
	double sum_motor_right = 0.0;
	double wsum_motor_right = 0.0;
	for (int i = 0; i < 1000 ; i++ ) {
		double x = 0.0 + i * 0.255;
		sum_motor_right += defuzzify_motor_right[i];
		wsum_motor_right += x * defuzzify_motor_right[i];
	}
	motor_right = wsum_motor_right / sum_motor_right;
}

// Fuzzify all variables
void FunctionBlock_Nikolas_motor_speed::fuzzify() {
	left_midle_sensor_offline = membership_left_midle_sensor_offline(left_midle_sensor);
	left_midle_sensor_online = membership_left_midle_sensor_online(left_midle_sensor);
	left_midle_sensor_warning = membership_left_midle_sensor_warning(left_midle_sensor);
	left_sensor_offline = membership_left_sensor_offline(left_sensor);
	left_sensor_online = membership_left_sensor_online(left_sensor);
	left_sensor_warning = membership_left_sensor_warning(left_sensor);
	right_middle_sensor_offline = membership_right_middle_sensor_offline(right_middle_sensor);
	right_middle_sensor_online = membership_right_middle_sensor_online(right_middle_sensor);
	right_middle_sensor_warning = membership_right_middle_sensor_warning(right_middle_sensor);
	right_sensor_offline = membership_right_sensor_offline(right_sensor);
	right_sensor_online = membership_right_sensor_online(right_sensor);
	right_sensor_warning = membership_right_sensor_warning(right_sensor);
}

// Membership functions 
double FunctionBlock_Nikolas_motor_speed::membership_left_midle_sensor_offline(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 512.0 )	return 0.0;
	if ( x <= 256.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 256.0 - 0.0 ) );
	if ( x <= 512.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_left_midle_sensor_online(double x) {
	if ( x <= 512.0 )	return 0.0;
	if ( x > 1024.0 )	return 1.0;
	if ( x <= 768.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
	if ( x <= 1024.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 768.0 ) / ( 1024.0 - 768.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_left_midle_sensor_warning(double x) {
	if ( x <= 256.0 )	return 0.0;
	if ( x > 768.0 )	return 0.0;
	if ( x <= 512.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
	if ( x <= 768.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_left_sensor_offline(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 512.0 )	return 0.0;
	if ( x <= 256.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 256.0 - 0.0 ) );
	if ( x <= 512.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_left_sensor_online(double x) {
	if ( x <= 512.0 )	return 0.0;
	if ( x > 1024.0 )	return 1.0;
	if ( x <= 768.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
	if ( x <= 1024.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 768.0 ) / ( 1024.0 - 768.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_left_sensor_warning(double x) {
	if ( x <= 256.0 )	return 0.0;
	if ( x > 768.0 )	return 0.0;
	if ( x <= 512.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
	if ( x <= 768.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_motor_left_fast(double x) {
	if ( x <= 128.0 )	return 0.0;
	if ( x > 255.0 )	return 1.0;
	if ( x <= 192.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 128.0 ) / ( 192.0 - 128.0 ) );
	if ( x <= 255.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 192.0 ) / ( 255.0 - 192.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_motor_left_normal(double x) {
	if ( x <= 64.0 )	return 0.0;
	if ( x > 192.0 )	return 0.0;
	if ( x <= 128.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 64.0 ) / ( 128.0 - 64.0 ) );
	if ( x <= 192.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 128.0 ) / ( 192.0 - 128.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_motor_left_slow(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 128.0 )	return 0.0;
	if ( x <= 64.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 64.0 - 0.0 ) );
	if ( x <= 128.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 64.0 ) / ( 128.0 - 64.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_motor_right_fast(double x) {
	if ( x <= 128.0 )	return 0.0;
	if ( x > 255.0 )	return 1.0;
	if ( x <= 192.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 128.0 ) / ( 192.0 - 128.0 ) );
	if ( x <= 255.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 192.0 ) / ( 255.0 - 192.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_motor_right_normal(double x) {
	if ( x <= 64.0 )	return 0.0;
	if ( x > 192.0 )	return 0.0;
	if ( x <= 128.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 64.0 ) / ( 128.0 - 64.0 ) );
	if ( x <= 192.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 128.0 ) / ( 192.0 - 128.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_motor_right_slow(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 128.0 )	return 0.0;
	if ( x <= 64.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 64.0 - 0.0 ) );
	if ( x <= 128.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 64.0 ) / ( 128.0 - 64.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_right_middle_sensor_offline(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 512.0 )	return 0.0;
	if ( x <= 256.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 256.0 - 0.0 ) );
	if ( x <= 512.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_right_middle_sensor_online(double x) {
	if ( x <= 512.0 )	return 0.0;
	if ( x > 1024.0 )	return 1.0;
	if ( x <= 768.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
	if ( x <= 1024.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 768.0 ) / ( 1024.0 - 768.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_right_middle_sensor_warning(double x) {
	if ( x <= 256.0 )	return 0.0;
	if ( x > 768.0 )	return 0.0;
	if ( x <= 512.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
	if ( x <= 768.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_right_sensor_offline(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 512.0 )	return 0.0;
	if ( x <= 256.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 256.0 - 0.0 ) );
	if ( x <= 512.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_right_sensor_online(double x) {
	if ( x <= 512.0 )	return 0.0;
	if ( x > 1024.0 )	return 1.0;
	if ( x <= 768.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
	if ( x <= 1024.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 768.0 ) / ( 1024.0 - 768.0 ) );
}

double FunctionBlock_Nikolas_motor_speed::membership_right_sensor_warning(double x) {
	if ( x <= 256.0 )	return 0.0;
	if ( x > 768.0 )	return 0.0;
	if ( x <= 512.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 256.0 ) / ( 512.0 - 256.0 ) );
	if ( x <= 768.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 512.0 ) / ( 768.0 - 512.0 ) );
}


// Print 
void FunctionBlock_Nikolas_motor_speed::print() {
	printf("Function block Nikolas_motor_speed:\n");
	printf("	Input  %20s : %f\n", "left_midle_sensor" , left_midle_sensor);
	printf("	       %20s : %f\n", "left_midle_sensor_offline" , left_midle_sensor_offline);
	printf("	       %20s : %f\n", "left_midle_sensor_online" , left_midle_sensor_online);
	printf("	       %20s : %f\n", "left_midle_sensor_warning" , left_midle_sensor_warning);
	printf("	Input  %20s : %f\n", "left_sensor" , left_sensor);
	printf("	       %20s : %f\n", "left_sensor_offline" , left_sensor_offline);
	printf("	       %20s : %f\n", "left_sensor_online" , left_sensor_online);
	printf("	       %20s : %f\n", "left_sensor_warning" , left_sensor_warning);
	printf("	Output %20s : %f\n", "motor_left" , motor_left);
	printf("	Output %20s : %f\n", "motor_right" , motor_right);
	printf("	Input  %20s : %f\n", "right_middle_sensor" , right_middle_sensor);
	printf("	       %20s : %f\n", "right_middle_sensor_offline" , right_middle_sensor_offline);
	printf("	       %20s : %f\n", "right_middle_sensor_online" , right_middle_sensor_online);
	printf("	       %20s : %f\n", "right_middle_sensor_warning" , right_middle_sensor_warning);
	printf("	Input  %20s : %f\n", "right_sensor" , right_sensor);
	printf("	       %20s : %f\n", "right_sensor_offline" , right_sensor_offline);
	printf("	       %20s : %f\n", "right_sensor_online" , right_sensor_online);
	printf("	       %20s : %f\n", "right_sensor_warning" , right_sensor_warning);
}

// Reset output
void FunctionBlock_Nikolas_motor_speed::reset() {
	for( int i=0 ; i < 1000 ; i++ )	{ defuzzify_motor_left[i] = 0.0; }
	for( int i=0 ; i < 1000 ; i++ )	{ defuzzify_motor_right[i] = 0.0; }
}

int main(int argc, char *argv[]) {
	// Create function blocks
	FunctionBlock_Nikolas_motor_speed Nikolas_motor_speed;

	// Parse input
	if( argc > 1 ) { Nikolas_motor_speed.left_midle_sensor = atof(argv[1]); }
	if( argc > 2 ) { Nikolas_motor_speed.left_sensor = atof(argv[2]); }
	if( argc > 3 ) { Nikolas_motor_speed.right_middle_sensor = atof(argv[3]); }
	if( argc > 4 ) { Nikolas_motor_speed.right_sensor = atof(argv[4]); }

	// Calculate
	Nikolas_motor_speed.calc();

	// Show results
	Nikolas_motor_speed.print();
}
