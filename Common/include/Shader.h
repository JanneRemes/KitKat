#ifndef SHADER_H
#define SHADER_H

#ifdef _WIN32
#include <OpenGL.h>
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif

#include <glm/glm.hpp>

#include <string>

namespace KitKat
{
	class Shader
	{
	public:
		Shader(const std::string& vertex, const std::string& fragment, bool loadFromFile = true);
		~Shader();

		GLuint program();

		GLint getAttribLocation(const std::string& name) const;
		GLint getUniformLocation(const std::string& name) const;
		void setUniform(const std::string& name, glm::mat4 matrix) const;

		void use();
	private:
		GLuint _program;
		GLuint _vertexShader, _fragmentShader;

		void create(const std::string& vertexCode, const std::string& fragmentCode);
		void destroy();

		// Creates the OpenGL program
		void createProgram();
		// Link shaders to the program
		void linkProgram();

		GLuint createShader(const GLenum shaderType, const std::string& code);		
		void compileShader(const GLuint shader, const char* code);
		void attachShader(const GLuint shader);
	};
}

#endif