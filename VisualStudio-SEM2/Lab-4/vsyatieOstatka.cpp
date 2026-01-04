struct ostatok
{
	int num2 : 5;
};

int vzyatieOstatka(int number, int argv1) {
	ostatok ost;
	ost.num2 = number;
	//ost.num2 = argv1;
	return ost.num2;
}