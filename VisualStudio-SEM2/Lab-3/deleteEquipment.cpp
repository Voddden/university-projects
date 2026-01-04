#include "deleteEquipment.h"
#include "swapEquipment.h"

void deleteEquipment(Equipment* stack, int& size, int indexToDelete) {
	for (int i = indexToDelete; i < size; ++i) {
		swapEquipment(stack[i], stack[i + 1]);
	}
	--size;
}