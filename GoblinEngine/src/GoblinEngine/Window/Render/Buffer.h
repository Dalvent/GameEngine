#pragma once

namespace GoblinEngine
{
	enum class ShaderDataType
	{
		None = 0, 
		Float, 
		Float2, 
		Float3, 
		Float4,
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
			case ShaderDataType::Float4:  return 16;
			case ShaderDataType::Mat3:	  return 36;
			case ShaderDataType::Mat4:	  return 64;
			case ShaderDataType::Int:	  return 4;
			case ShaderDataType::Int2:	  return 8;
			case ShaderDataType::Int3:	  return 12;
			case ShaderDataType::Int4:	  return 16;
			case ShaderDataType::Bool:	  return 1;
		}

		GE_LOG_CORE_ERROR("Unkown ShaderDataType!");
		return 0;
	}

	struct BufferElement
	{
		std::string name;
		ShaderDataType type;
		unsigned int size;
		unsigned int offset;
		bool normalized;

		BufferElement() = default;
		BufferElement(const std::string& name, ShaderDataType type, bool normalized = false)
			: name(name), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized)
		{
		}

		unsigned int GetComponentCount() const
		{
			switch (type)
			{
				case ShaderDataType::Float:   return 1;
				case ShaderDataType::Float2:  return 2;
				case ShaderDataType::Float3:  return 3;
				case ShaderDataType::Float4:  return 4;
				case ShaderDataType::Mat3:	  return 9;
				case ShaderDataType::Mat4:	  return 16;
				case ShaderDataType::Int:	  return 1;
				case ShaderDataType::Int2:	  return 2;
				case ShaderDataType::Int3:	  return 3;
				case ShaderDataType::Int4:	  return 4;
				case ShaderDataType::Bool:	  return 1;
			}

			GE_LOG_CORE_ERROR("Unkown ShaderDataType!");
			return 0;
		}
	};

	class BufferElementsLayout
	{
	public:
		BufferElementsLayout() {}
		BufferElementsLayout(const std::initializer_list<BufferElement>& elements)
			: _elements(elements)
		{
			unsigned int offset = 0;
			_stride = 0;
			for (auto& element : _elements)
			{
				element.offset = offset;
				offset += element.size;
				_stride += element.size;
				std::cout << _stride << std::endl;
			}
		}

		unsigned int GetStride() const { return _stride; }
		const std::vector<BufferElement>& GetElemnets() const { return _elements; }

		std::vector<BufferElement>::iterator begin() { return _elements.begin(); }
		std::vector<BufferElement>::iterator end() { return _elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return _elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return _elements.end(); }
	private:
		std::vector<BufferElement> _elements;
		unsigned int _stride;
	};

	class VertexBuffer
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const Ref<BufferElementsLayout> GetLayout() const { return _layout; }
		virtual void SetLayout(const Ref<BufferElementsLayout>& layout) { _layout = layout; }
	protected:
		Ref<BufferElementsLayout> _layout;
	};

	class IndexBuffer
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned int GetCount() const = 0;
	};
}