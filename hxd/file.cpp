
#include "hxdex.h"

int offset=0;

int main(int argc, char* argv[])
{
	
	FILE* file;
	int filesize;
	char* buffer;
	long NT_headeroffset=0;

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
	
	printf("\nfile size is : %d byte\n\n", filesize);
	
	print_dos_header((_IMAGE_DOS_HEADER*)buffer);
	
	NT_header((IMAGE_NT_HEADERS*)(buffer + offset));

	printf("\n\n\n============== [IMAGE_SECTION_HEADER] ================\n");
	for (int i = 0; i < 7; i++)
	{
		Image_section_h((IMAGE_SECTION_HEADER*)(buffer + offset));
	}
	printf("\n\n======================================================\n");
	
	Image_des((_IMAGE_IMPORT_DESCRIPTOR*)(buffer+offset));



	

	// 파일을 닫음 
	fclose(file);

	return 0;
}

int offset_move(int membersize) {
	offset += membersize;
	return offset;
}

void offset_define(int num){
	offset = num;
}

