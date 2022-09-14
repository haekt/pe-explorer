#include "hxdex.h"

void print_nt_section_h(_IMAGE_SECTION_HEADER* section_header, uint32_t number_of_sections){

	printf("\n\n\n============== [IMAGE_IMPORT_DESCRIPTER] ================\n");

	printf("\n  Number of Sections = %d \n", number_of_sections);

	for (int i = 0; i < number_of_sections; i++,section_header++)
	{
		printf("\n---------------- ( %s SECTION ) ----------------\n", section_header->Name);
		printf("-[%08X] ", offset_move(sizeof(section_header->Name)));
		printf("- VirtualSize[4byte]\t\t\t: %08X\n", section_header->Misc);
		printf("-[%08X] ", offset_move(sizeof(section_header->Misc)));
		printf("- VirtualAddress[4byte]\t\t\t: %08X\n", section_header->VirtualAddress);
		printf("-[%08X] ", offset_move(sizeof(section_header->VirtualAddress)));
		printf("- SizeOfRawData[4byte]\t\t\t: %08X\n", section_header->SizeOfRawData);
		printf("-[%08X] ", offset_move(sizeof(section_header->SizeOfRawData)));
		printf("- PointerToRawData[4byte]\t\t\t: %08X\n", section_header->PointerToRawData);
		printf("-[%08X] ", offset_move(sizeof(section_header->PointerToRawData)));
		printf("- PointerToRelocation[4byte]\t\t: %08X\n", section_header->PointerToRelocations);
		printf("-[%08X] ", offset_move(sizeof(section_header->PointerToRelocations)));
		printf("- PointerToLinenumbers[4byte]\t\t: %08X\n", section_header->PointerToLinenumbers);
		printf("-[%08X] ", offset_move(sizeof(section_header->PointerToLinenumbers)));
		printf("- NumberOfRelocation[2byte]\t\t\t: %04X\n", section_header->NumberOfRelocations);
		printf("-[%08X] ", offset_move(sizeof(section_header->NumberOfRelocations)));
		printf("- NumberOfLinenumbers[2byte]\t\t: %04X\n", section_header->NumberOfLinenumbers);
		printf("-[%08X] ", offset_move(sizeof(section_header->NumberOfLinenumbers)));
		printf("- Characteristics[4byte]\t\t\t: %08X\n", section_header->Characteristics);
		offset_move(sizeof(section_header->Characteristics));

		printf("---------------------------------------------------\n");

	}

	printf("\n\n=======================================================\n");

}