
#include "hxdex.h"

uint32_t offset=0;

int main(int argc, char* argv[])
{
	
	FILE* file;
	uint32_t filesize;
	char* buffer;


	// 사용자 입력 파일을 rb로 불러옴
	file =fopen(argv[1],"rb");
	
	// 파일의 포인터를 끝으로 이동
	fseek(file, 0, SEEK_END);
	
	// 포인터의 위치를 반환
	filesize = ftell(file);
	//포인터 위치 초기화
	rewind(file);
	// 파일의 크기만큼 버퍼의 크기 할당
	buffer = (char*)malloc(sizeof(char) * filesize);

	// 버퍼에 file 의 정보를 1바이트씩 filesize 만큼 불러옴 
	fread(buffer,1,filesize,file);
	if (buffer==NULL)
	{
		printf("--!! ERROR !!--\n\tFile Read error\n");
	}
	

	//구조체 변수 선언 
	_IMAGE_DOS_HEADER* dos_h = (_IMAGE_DOS_HEADER*)buffer;

	IMAGE_NT_HEADERS* nt_h = (IMAGE_NT_HEADERS*)(buffer + dos_h->e_lfanew);

	IMAGE_SECTION_HEADER* section_h = (IMAGE_SECTION_HEADER*)(buffer + dos_h->e_lfanew + sizeof(nt_h->FileHeader) + sizeof(nt_h->OptionalHeader) + sizeof(nt_h->Signature));


	//파일 크기 출력
	printf("\nfile size is : %d byte\n\n", filesize);
	
	print_dos_h(dos_h);
	
	print_nt_h(nt_h);
	offset = 0;
	print_nt_section_h(section_h,nt_h->FileHeader.NumberOfSections);
	
	RAW_to_RVA(section_h, nt_h->FileHeader.NumberOfSections, nt_h->OptionalHeader.DataDirectory[0].VirtualAddress, nt_h->OptionalHeader.DataDirectory[1].VirtualAddress);
	print_image_import_descriptor((_IMAGE_IMPORT_DESCRIPTOR*)(buffer+offset));


	// 파일을 닫음 
	fclose(file);

	return 0;
}

uint32_t offset_move(uint32_t membersize) {
	offset += membersize;
	return offset;
}


