#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

void print_dos_header(_IMAGE_DOS_HEADER* dos_header);
void NT_header(IMAGE_NT_HEADERS* NT_header);
int offset_move(int membersize);
void offset_define(int num);
void Image_section_h(_IMAGE_SECTION_HEADER* section_header);
void Image_des(_IMAGE_IMPORT_DESCRIPTOR* import_des);
