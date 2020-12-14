#pragma once

#include <string>

#include "vec3.h"

class Exporter
{
protected:
	unsigned width, height;
	Color *image;

	Exporter(unsigned width, unsigned height, Color *buf)
		: width(width), height(height), image(buf) {}

public:
	virtual bool export_image(void) const = 0;
	virtual ~Exporter() {};
};

// TODO: P6 instead of P3
class NetPBM : public Exporter
{
	std::string filename;
	unsigned range;

public:
	NetPBM(std::string filename, unsigned width, unsigned height,
		   Color *buf, unsigned range = 255)
		: Exporter(width, height, buf),
		  filename(filename), range(range) {}

	bool export_image(void) const override;

	~NetPBM() override {};
};
