#include "hxdex.h"

void print_image_import_descriptor(_IMAGE_IMPORT_DESCRIPTOR *import_des)
{
	printf("\n\n\n============== [IMAGE_IMPORT_DESCRIPTER] ================\n");
	printf("-[%08X] ", offset_move(0));
	printf("- OriginalFirstThunk[4byte]\t\t\t\t: %08X\n", import_des->OriginalFirstThunk);

	printf("\n\n======================================================\n");

}