#include "vector"

struct vec3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;
};

struct vec2
{
	float x = 0.0f, y = 0.0f;
};

struct vertex
{
	vec3 position, normal;
	vec2 texcoord;
};

struct texture
{
	unsigned char* ptextures = 0;
	int width = 0;
	int height = 0;
	int channels = 0;
};

struct model
{
	vec3 position;
	const char* file_path;
	std::vector<vertex>* pvertices;
	std::vector<unsigned>* pindices;
	texture diffuse;
	texture specular;
	~model() 
	{
		delete file_path;
		delete pvertices;
		delete pindices;
	}
};