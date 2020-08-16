#pragma once

namespace GoblinEngine
{
	enum class ShaderDataType
	{
		None = 0, 
		Float, 
		Float2, 
		Float3, 
		Floa4, 
		Mat3, 
		Mat4, 
		Int, 
		Int2, 
		Int3, 
		Int4, 
		Bool
	};

	static unsigned int ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:   return 4;	
		case ShaderDataType::Float2:  return 8;
		case ShaderDataType::Float3:  return 12;
		case ShaderDataType::Floa4:	  return 16;
		case ShaderDataType::Mat3:	  return 36;
		case ShaderDataType::Mat4:	  return 64;
		case ShaderDataType::Int:	  return 4;
		case ShaderDataType::Int2:	  return 8;
		case ShaderDataType::Int3:	  return 12;
		case ShaderDataType::Int4:	  return 16;
		case ShaderDataType::Bool:	  return 1;
		}

		GE_CORE_ERROR("Unkown ShaderDataType!");
		return 0;
	}

	struct BufferElement
	{
		std::string Name;
		ShaderDataType Type;
		unsigned int Size;
		unsigned int Offset;

		BufferElement(const std::string& name, ShaderDataType type)
			: Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0)
		{
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout(std::vector<BufferElement> element) {}
		const std::vector<BufferElement>& GetElemnets() const { return _elements; }
	private:
		std::vector<BufferElement> _elements;
	};

	class IVertexBuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;
	};

	class IIndexBuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};
}