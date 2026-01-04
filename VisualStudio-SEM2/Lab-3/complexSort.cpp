#include "complexSort.h"
#include "sortEquipment.h"

// 0 - IDsort, 1 - NAMEsort, 2 - TYPEsort, 3 - QUANTITYSORT, 4 - DATEsort

int complexSort(Equipment* list, int& size) {
	int sorts[5] = {};
	printf("INSERT\n0 - don't include sort, 1 - include\n");
	sorts[0] = inputNaturalAnd0("IDsort - "); 
	if (sorts[0] != 0 && sorts[0] != 1)
		return -1;
	sorts[1] = inputNaturalAnd0("NAMEsort - ");
	if (sorts[1] != 0 && sorts[1] != 1)
		return -1;
	sorts[2] = inputNaturalAnd0("TYPEsort - ");
	if (sorts[2] != 0 && sorts[2] != 1)
		return -1;
	sorts[3] = inputNaturalAnd0("QUANTITYsort - ");
	if (sorts[3] != 0 && sorts[3] != 1)
		return -1;
	sorts[4] = inputNaturalAnd0("DATEsort - ");
	if (sorts[4] != 0 && sorts[4] != 1)
		return -1;

	if (sorts[0])
		sortById(list, size);
	if (sorts[1])
		sortByName(list, size);
	if (sorts[2])
		sortByType(list, size);
	if (sorts[3])
		sortByQuantity(list, size);
	if (sorts[4])
		sortByDate(list, size);

	return 0;
}