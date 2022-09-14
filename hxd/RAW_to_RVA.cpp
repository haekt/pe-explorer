#include "hxdex.h"

void RAW_to_RVA(_IMAGE_SECTION_HEADER* section_header, uint32_t number_of_sections, DWORD export_dir, DWORD import_dir){
	int flag = 0;
	for (int i = 0; i < number_of_sections; i++, section_header++)
	{
		if (import_dir > section_header->VirtualAddress && import_dir < section_header->Misc.VirtualSize + section_header->VirtualAddress && flag == 0) {
			flag = 1; offset = import_dir - section_header->VirtualAddress + section_header->PointerToRawData;
			printf("^");
		}
	}
}