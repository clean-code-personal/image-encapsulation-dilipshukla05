#pragma once
#include <cstdint>
#include <iostream>

class Image {
public:
	Image(uint16_t rows, uint16_t columns): m_rows(rows), m_columns(columns) {
		if ((m_columns <= 1024 && m_rows <= 1024)) 
		{
			//Allocate memory only if its in range
			pixels = new uint8_t[m_rows * m_columns];
		}
		else
		{
			pixels = nullptr;
		}

	}
	~Image() {
		
		if (pixels != nullptr) //Delete only if it contain a valid memory address
		{
			std::cout << "freeing pixel memory.\n";
			delete[] pixels;
			pixels = nullptr;
		}
	}
	const uint16_t m_rows;
	const uint16_t m_columns;
	uint8_t* pixels; // max 1k x 1k image
};
