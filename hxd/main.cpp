
#include "hxdex.h"

uint32_t offset=0;

int main(int argc, char* argv[])
{
	
	FILE* file;
	uint32_t filesize;
	char* buffer;


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
	if (buffer==NULL)
	{
		printf("--!! ERROR !!--\n\tFile Read error\n");
	}
	

	//����ü ���� ���� 
	_IMAGE_DOS_HEADER* dos_h = (_IMAGE_DOS_HEADER*)buffer;

	IMAGE_NT_HEADERS* nt_h = (IMAGE_NT_HEADERS*)(buffer + dos_h->e_lfanew);

	IMAGE_SECTION_HEADER* section_h = (IMAGE_SECTION_HEADER*)(buffer + dos_h->e_lfanew + sizeof(nt_h->FileHeader) + sizeof(nt_h->OptionalHeader) + sizeof(nt_h->Signature));


	//���� ũ�� ���
	printf("\nfile size is : %d byte\n\n", filesize);
	
	print_dos_h(dos_h);
	
	print_nt_h(nt_h);
	offset = 0;
	print_nt_section_h(section_h,nt_h->FileHeader.NumberOfSections);
	
	RAW_to_RVA(section_h, nt_h->FileHeader.NumberOfSections, nt_h->OptionalHeader.DataDirectory[0].VirtualAddress, nt_h->OptionalHeader.DataDirectory[1].VirtualAddress);
	print_image_import_descriptor((_IMAGE_IMPORT_DESCRIPTOR*)(buffer+offset));


	// ������ ���� 
	fclose(file);

	return 0;
}

uint32_t offset_move(uint32_t membersize) {
	offset += membersize;
	return offset;
}


