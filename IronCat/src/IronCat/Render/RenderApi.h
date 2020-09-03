#pragma once

#include "IronCat/File/Image.h"
#include "IronCat/Render/Shader.h"
#include "IronCat/Render/Buffer.h"
#include "IronCat/Render/VertexArray.h"
#include "IronCat/Render/Texture.h"

#include <glm/glm.hpp>
#include <unordered_map>
namespace IronCat
{
	enum class SupportedRenderApiType
	{
		OpenGL = 0
	};

	class RenderApi
	{
	public:
		static void Init(SupportedRenderApiType apiType);
		static SupportedRenderApiType GetUsedApi() 
		{ 
			return _instance->_usedApi; 
		}

		static void SetClearColor(const glm::vec4& color)
		{
			_instance->SetClearColorImpl(color);
		}
		static void Clear()
		{
			_instance->ClearImpl();
		}

		static void DrawIndexed(const VertexArray& vertexArray)
		{
			_instance->DrawIndexedImpl(vertexArray);
		}
		static int ConvertImageInternalFormat(ImageInternalFormat format)
		{
			return _instance->ConvertImageInternalFormatImpl(format);
		}
        static int ConvertImageDataFormat(ImageDataFormat format)
		{
			return _instance->ConvertImageDataFormatImpl(format);
		}

		static Ref<IndexBuffer> CreateIndexBuffer(int* indices, unsigned int count)
		{
			return _instance->CreateIndexBufferImpl(indices, count);
		}
		static Ref<VertexBuffer> CreateVertexBuffer(float* vertices, unsigned int count)
		{
			return _instance->CreateVertexBufferImpl(vertices, count);
		}
		static Ref<VertexArray> CreateVertexArray()
		{
			return _instance->CreateVertexArrayImpl();
		}
		static Ref<Texture2D> CreteTexture2D(std::string name, const Image& image);
		static Ref<Shader> CreteShader(std::string name, const std::string filePath);
	protected:
		virtual void SetClearColorImpl(const glm::vec4& color) = 0;
		virtual void ClearImpl() = 0;

		virtual void DrawIndexedImpl(const VertexArray& vertexArray) = 0;
		virtual int ConvertImageInternalFormatImpl(ImageInternalFormat format) = 0;
		virtual int ConvertImageDataFormatImpl(ImageDataFormat format) = 0;

		//virtual Scope<GraphicsContext> CreateGraphicsContextImpl(Window& window) = 0;
		virtual Ref<IndexBuffer> CreateIndexBufferImpl(int* indices, unsigned int count) = 0;
		virtual Ref<VertexBuffer> CreateVertexBufferImpl(float* vertices, unsigned int count) = 0;
		virtual Ref<VertexArray> CreateVertexArrayImpl() = 0;
		virtual Ref<Texture2D> CreteTexture2DImpl(const Image& image) = 0;
		virtual Ref<Shader> CreteShaderImpl(const std::string filePath) = 0;
	private:
		 static Scope<RenderApi> _instance;
	private:
		 SupportedRenderApiType _usedApi;
	};

	class RenderApiLibrary
	{
	public:
		static void AddShader(std::string name, Ref<Shader> s_shader)
		{
			_shaders[name] = s_shader;
		}
		static Ref<Shader> GetShader(std::string name)
		{
			return _shaders[name];
		}

		static void AddTexture(std::string name, Ref<Texture2D> s_texture)
		{
			_textures[name] = s_texture;
		}
		static Ref<Texture> GetTexture(std::string name)
		{
			return _textures[name];
		}
	private:
		static std::unordered_map<std::string, Ref<Shader>> _shaders;
		static std::unordered_map<std::string, Ref<Texture2D>> _textures;
	};
}