#include "hxdex.h"

void NT_header(IMAGE_NT_HEADERS* NT_header){ // ******
	

	int bittype = 0;

	IMAGE_NT_HEADERS32* NT_header32;
	
	int bit = NT_header->FileHeader.Machine;
	if (0x014c == bit)
	{
		printf("\nThis Program is 32bit\n");
		bittype = 32;
		NT_header32 = (IMAGE_NT_HEADERS32*)NT_header;
	}
	else if (0x0200 == bit || 0x0284 == bit || 0x8664 == bit)
	{
		printf("\nThis Program is 64bit\n");
	}




	printf("\n============== [NT Header] ===============\n");
	printf("-[%08X] ", offset_move(0));
	printf("- Signature[4byte]\t\t\t\t: %08X\n", NT_header->Signature);
	offset_move(sizeof(NT_header->Signature));
	printf("- FileHeader[%dbyte]\t\t\t\n", (int)sizeof(NT_header->FileHeader));
	printf("- OptionalHeader[%dbyte]\t\t\t\n", (int)sizeof(NT_header->OptionalHeader));
	
	printf("\n------------------ (FileHeader) ------------------\n");
	printf("-[%08X] ", offset_move(0));
	printf("- Machine[2byte]\t\t\t\t: %04X\n", NT_header->FileHeader.Machine);
	printf("-[%08X] ", offset_move(sizeof(NT_header->FileHeader.Machine)));
	printf("- NumberOfSections[2byte]\t\t\t: %04X\n", NT_header->FileHeader.NumberOfSections);
	printf("-[%08X] ", offset_move(sizeof(NT_header->FileHeader.NumberOfSections)));
	printf("- TimeDateStamp[4byte]\t\t\t: %08X\n", NT_header->FileHeader.TimeDateStamp);
	printf("-[%08X] ", offset_move(sizeof(NT_header->FileHeader.TimeDateStamp)));
	printf("- PointerToSymbolTable[4byte]\t\t: %08X\n", NT_header->FileHeader.PointerToSymbolTable);
	printf("-[%08X] ", offset_move(sizeof(NT_header->FileHeader.PointerToSymbolTable)));
	printf("- NumberOfSymbols[4byte]\t\t\t: %08X\n", NT_header->FileHeader.NumberOfSymbols);
	printf("-[%08X] ", offset_move(sizeof(NT_header->FileHeader.NumberOfSymbols)));
	printf("- SizeOfOptionalHeader[2byte]\t\t: %04X\n", NT_header->FileHeader.SizeOfOptionalHeader);
	printf("-[%08X] ", offset_move(sizeof(NT_header->FileHeader.SizeOfOptionalHeader)));
	printf("- Characteristics[2byte]\t\t\t: %04X\n", NT_header->FileHeader.Characteristics);
	offset_move(sizeof(NT_header->FileHeader.Characteristics));

	printf("---------------------------------------------------\n");


	printf("\n---------------- (Optional Header) ----------------\n");
	printf("-[%08X] ", offset_move(0));
	printf("- Magic[2byte]\t\t\t\t: %04X\n", NT_header->OptionalHeader.Magic);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.Magic)));
	printf("- MajorLinkerVersion[1byte]\t\t\t: %02X\n", NT_header->OptionalHeader.MajorLinkerVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MajorLinkerVersion)));
	printf("- MinorLinkerVersion[1byte]\t\t\t: %02X\n", NT_header->OptionalHeader.MinorLinkerVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MinorLinkerVersion)));
	printf("- SizeOfCode[4byte]\t\t\t\t: %08X\n", NT_header->OptionalHeader.SizeOfCode);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfCode)));
	printf("- SizeOfInitializedData[4byte]\t\t: %08X\n", NT_header->OptionalHeader.SizeOfInitializedData);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfInitializedData)));
	printf("- SizeOfUnInitializedData[4byte]\t\t: %08X\n", NT_header->OptionalHeader.SizeOfUninitializedData);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfUninitializedData)));
	printf("- AddressOfEntryPoint[4byte]\t\t: %08X\n", NT_header->OptionalHeader.AddressOfEntryPoint);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.AddressOfEntryPoint)));
	printf("- BaseOfCode[4byte]\t\t\t\t: %08X\n", NT_header->OptionalHeader.BaseOfCode);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.BaseOfCode)));
	if (bittype == 32)
	{
		printf("- BaseOfData[4byte]\t\t\t: %08X\n", NT_header32->OptionalHeader.BaseOfData);
		printf("-[%08X] ", offset_move(sizeof(NT_header32->OptionalHeader.BaseOfData)));
		printf("- ImageBase[4byte]\t\t\t\t: %08X\n", NT_header32->OptionalHeader.ImageBase);
		printf("-[%08X] ", offset_move(sizeof(NT_header32->OptionalHeader.ImageBase)));
	}

	printf("- ImageBase[8byte]\t\t\t\t: %016llX\n", NT_header->OptionalHeader.ImageBase);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.ImageBase)));
	printf("- SectionAlignment[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.SectionAlignment);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SectionAlignment)));
	printf("- FileAligment[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.FileAlignment);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.FileAlignment)));
	printf("- MajorOperatingSystemVersion[2byte]\t: %04X\n", NT_header->OptionalHeader.MajorOperatingSystemVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MajorOperatingSystemVersion)));
	printf("- MinorOperatingSystemVersion[2byte]\t: %04X\n", NT_header->OptionalHeader.MinorOperatingSystemVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MinorOperatingSystemVersion)));
	printf("- MajorImageVersion[2byte]\t\t\t: %04X\n", NT_header->OptionalHeader.MajorImageVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MajorImageVersion)));
	printf("- MinorImageVersion[2byte]\t\t\t: %04X\n", NT_header->OptionalHeader.MinorImageVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MinorImageVersion)));
	printf("- MajorSubsystemVersion[2byte]\t\t: %04X\n", NT_header->OptionalHeader.MajorSubsystemVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MajorSubsystemVersion)));
	printf("- MinorSubsystemVersion[2byte]\t\t: %04X\n", NT_header->OptionalHeader.MinorSubsystemVersion);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.MinorSubsystemVersion)));
	printf("- Win32VersionValue[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.Win32VersionValue);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.Win32VersionValue)));
	printf("- SizeOfImage[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.SizeOfImage);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfImage)));
	printf("- SizeOfHeaders[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.SizeOfHeaders);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfHeaders)));
	printf("- CheckSum[4byte]\t\t\t\t: %08X\n", NT_header->OptionalHeader.CheckSum);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.CheckSum)));
	printf("- Subsystem[2byte]\t\t\t\t: %04X\n", NT_header->OptionalHeader.Subsystem);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.Subsystem)));
	printf("- DllCharacteristics[2byte]\t\t\t: %04X\n", NT_header->OptionalHeader.DllCharacteristics);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DllCharacteristics)));
	printf("- SizeOfStackReserve[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.SizeOfStackReserve);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfStackReserve)));
	printf("- SizeOfStackCommit[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.SizeOfStackCommit);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfStackCommit)));
	printf("- SizeOfHeapReserve[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.SizeOfHeapReserve);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfHeapReserve)));
	printf("- SizeOfHeapCommit[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.SizeOfHeapCommit);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.SizeOfHeapCommit)));
	printf("- LoaderFlags[4byte]\t\t\t: %08X\n", NT_header->OptionalHeader.LoaderFlags);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.LoaderFlags)));
	printf("- NumberOfRvaAndSizes[4byte]\t\t: %08X\n", NT_header->OptionalHeader.NumberOfRvaAndSizes);
	offset_move(sizeof(NT_header->OptionalHeader.NumberOfRvaAndSizes));
	printf("---------------------------------------------------\n");


	printf("\n----------------- (DataDirectory) -----------------\n");
	printf("-[%08X] ", offset_move(0));
	printf("-EXPORT Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[0]), NT_header->OptionalHeader.DataDirectory[0]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[0])));
	printf("-IMPORT Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[1]), NT_header->OptionalHeader.DataDirectory[1]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[1])));
	printf("-RESOURCE Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[2]), NT_header->OptionalHeader.DataDirectory[2]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[2])));
	printf("-EXCEPTION Directory [%dbyte]\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[3]), NT_header->OptionalHeader.DataDirectory[3]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[3])));
	printf("-SECURITY Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[4]), NT_header->OptionalHeader.DataDirectory[4]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[4])));
	printf("-BASERELOC Directory [%dbyte]\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[5]), NT_header->OptionalHeader.DataDirectory[5]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[5])));
	printf("-DEBUG Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[6]), NT_header->OptionalHeader.DataDirectory[6]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[6])));
	printf("-COPYRIGHT Directory [%dbyte]\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[7]), NT_header->OptionalHeader.DataDirectory[7]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[7])));
	printf("-GLOBAL Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[8]), NT_header->OptionalHeader.DataDirectory[8]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[8])));
	printf("-TLS Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[9]), NT_header->OptionalHeader.DataDirectory[9]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[9])));
	printf("-LOAD_CONFIG Directory [%dbyte]\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[10]), NT_header->OptionalHeader.DataDirectory[10]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[10])));
	printf("-BOUND_IMPORT Directory [%dbyte]\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[11]), NT_header->OptionalHeader.DataDirectory[11]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[11])));
	printf("-IAT Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[12]), NT_header->OptionalHeader.DataDirectory[12]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[12])));
	printf("-DELAY_IMPORT Directory [%dbyte]\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[13]), NT_header->OptionalHeader.DataDirectory[13]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[13])));
	printf("-COM_DESCRIPTOR Directory [%dbyte]\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[14]), NT_header->OptionalHeader.DataDirectory[14]);
	printf("-[%08X] ", offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[14])));
	printf("-Reserved Directory [%dbyte]\t\t\t: %016X\n", sizeof(NT_header->OptionalHeader.DataDirectory[15]), NT_header->OptionalHeader.DataDirectory[15]);
	offset_move(sizeof(NT_header->OptionalHeader.DataDirectory[15]));
	printf("---------------------------------------------------\n\n\n");
	printf("=========================================\n");
}