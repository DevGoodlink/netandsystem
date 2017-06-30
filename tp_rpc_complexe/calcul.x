struct complex{
	float a;
	float b;
};
struct operandes{
	complex x;
	complex y;
};
program MATH_CALCUL{
	version MATH_VERSION_1{
		complex ADDITION(operandes)=1;
		complex MULTI(operandes)=2;	
	}=1;
}=0x20000002;
