
#include "hxdex.h"

int offset=0;

int main(int argc, char* argv[])
{
	
	FILE* file;
	int filesize;
	char* buffer;
	long NT_headeroffset=0;

	// ����� �Է� ������ rb�� �ҷ���
	file =fopen(argv[1],"rb");
	
	// ������ �����͸� ������ �̵�
	fseek(file, 0, SEEK_END);
	
	// �������� ��ġ�� ��ȯ
	filesize = ftell(file);
	//������ ��ġ �ʱ�ȭ
	rewind(file);
	// ������ ũ�⸸ŭ ������ ũ�� �Ҵ�
	buffer = (char*)malloc(sizeof(char) * filesize);

	// ���ۿ� file �� ������ 1����Ʈ�� filesize ��ŭ �ҷ��� 
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



	

	// ������ ���� 
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

