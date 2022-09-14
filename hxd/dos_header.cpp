#include "hxdex.h"

void print_dos_header(_IMAGE_DOS_HEADER* dos_header){


	printf("============= [Dos Header] ==============\n");
	printf("-[%08X] ", offset_move(0));
	printf("- e_magic[2byte]\t\t\t: %04X\n", dos_header->e_magic);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_magic)));
	printf("- e_cblp[2byte]\t\t\t: %04X\n", dos_header->e_cblp);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_cblp)));
	printf("- e_cp[2byte]\t\t\t: %04X\n", dos_header->e_cp);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_cp)));
	printf("- e_crlc[2byte]\t\t\t: %04X\n", dos_header->e_crlc);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_crlc)));
	printf("- e_cparhdr[2byte]\t\t\t: %04X\n", dos_header->e_cparhdr);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_cparhdr)));
	printf("- e_minalloc[2byte]\t\t\t: %04X\n", dos_header->e_minalloc);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_minalloc)));
	printf("- e_maxalloc[2byte]\t\t\t: %04X\n", dos_header->e_maxalloc);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_maxalloc)));
	printf("- e_ss[2byte]\t\t\t: %04X\n", dos_header->e_ss);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_ss)));
	printf("- e_sp[2byte]\t\t\t: %04X\n", dos_header->e_sp);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_sp)));
	printf("- e_csum[2byte]\t\t\t: %04X\n", dos_header->e_csum);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_csum)));
	printf("- e_ip[2byte]\t\t\t: %04X\n", dos_header->e_ip);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_ip)));
	printf("- e_cs[2byte]\t\t\t: %04X\n", dos_header->e_cs);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_cs)));
	printf("- e_lfarlc[2byte]\t\t\t: %04X\n", dos_header->e_lfarlc);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_lfarlc)));
	printf("- e_ovno[2byte]\t\t\t: %04X\n", dos_header->e_ovno);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_ovno)));
	printf("- e_res[0][2byte]\t\t\t: %04X\n", dos_header->e_res[0]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res[0])));
	printf("- e_res[1][2byte]\t\t\t: %04X\n", dos_header->e_res[1]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res[1])));
	printf("- e_res[2][2byte]\t\t\t: %04X\n", dos_header->e_res[2]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res[2])));
	printf("- e_res[3][2byte]\t\t\t: %04X\n", dos_header->e_res[3]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res[3])));
	printf("- e_oemid[2byte]\t\t\t: %04X\n", dos_header->e_oemid);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_oemid)));
	printf("- e_oeminfo[2byte]\t\t\t: %04X\n", dos_header->e_oeminfo);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_oeminfo)));
	printf("- e_res2[0][2byte]\t\t\t: %04X\n", dos_header->e_res2[0]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[0])));
	printf("- e_res2[1][2byte]\t\t\t: %04X\n", dos_header->e_res2[1]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[1])));
	printf("- e_res2[2][2byte]\t\t\t: %04X\n", dos_header->e_res2[2]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[2])));
	printf("- e_res2[3][2byte]\t\t\t: %04X\n", dos_header->e_res2[3]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[3])));
	printf("- e_res2[4][2byte]\t\t\t: %04X\n", dos_header->e_res2[4]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[4])));
	printf("- e_res2[5][2byte]\t\t\t: %04X\n", dos_header->e_res2[5]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[5])));
	printf("- e_res2[6][2byte]\t\t\t: %04X\n", dos_header->e_res2[6]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[6])));
	printf("- e_res2[7][2byte]\t\t\t: %04X\n", dos_header->e_res2[7]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[7])));
	printf("- e_res2[8][2byte]\t\t\t: %04X\n", dos_header->e_res2[8]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[8])));
	printf("- e_res2[9][2byte]\t\t\t: %04X\n", dos_header->e_res2[9]);
	printf("-[%08X] ", offset_move(sizeof(dos_header->e_res2[9])));
	printf("- e_lfanew[4byte]\t\t\t: %08X\n", dos_header->e_lfanew);
	offset_define(dos_header->e_lfanew);
	printf("=========================================\n");
	
	
}