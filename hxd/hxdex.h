#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <stdint.h>

extern uint32_t offset;
void print_dos_h(_IMAGE_DOS_HEADER* dos_header);
void print_nt_h(IMAGE_NT_HEADERS* NT_header);
uint32_t offset_move(uint32_t membersize);
void print_nt_section_h(_IMAGE_SECTION_HEADER* section_header, uint32_t number_of_sections);
void print_image_import_descriptor(_IMAGE_IMPORT_DESCRIPTOR* import_des);
void RAW_to_RVA(_IMAGE_SECTION_HEADER* section_header, uint32_t number_of_sections, DWORD export_dir, DWORD import_dir);
