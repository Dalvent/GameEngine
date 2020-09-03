#include "RenderCellLayer.h"
#include <IronCat\Platforms\OpenGL\OpenGLShader.h>

using namespace IronCat;

#define MAX_TRANSFORMS 1

void RenderCellLayer::OnAttach()
{
	_transforms = CreateTransforms();

	float vertices[] = {
		 1.0f,  1.0f, 0.0f,    1.0f,  1.0f,
		 1.0f, -1.0f, 0.0f,	   1.0f,  0.0f,
		-1.0f, -1.0f, 0.0f,	   0.0f,  0.0f,
		-1.0f,  1.0f, 0.0f,	   0.0f,  1.0f
	};
	auto vertexBuffer = RenderApi::CreateVertexBuffer(vertices, sizeof(vertices) / sizeof(float));

	vertexBuffer->SetLayout(Ref<BufferElementsLayout>(
		Ref<BufferElementsLayout>
			(new BufferElementsLayout(
				std::initializer_list<BufferElement> {
					{ "a_Position", ShaderDataType::Float3 },
					{ "a_TexCoord", ShaderDataType::Float2 }
				}
			)
		)
	));

	int indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	auto indexBuffer = RenderApi::CreateIndexBuffer(indices, 6);

	s_vertexArray = RenderApi::CreateVertexArray();
	s_vertexArray->AddVertexBuffer(vertexBuffer);
	s_vertexArray->SetIndexBuffer(indexBuffer);

	std::string shaderPath = "C:\\dev\\IronCat\\Sandbox\\src\\Assets\\staticOpjectShader.glsl";
	s_shader = RenderApi::CreteShader(shaderPath);
	
	Image textureFile("C:\\dev\\IronCat\\Sandbox\\src\\Assets\\waterTexture.jpg");
	s_texture = RenderApi::CreteTexture2D(textureFile);
	s_texture->Bind();
	std::static_pointer_cast<OpenGLShader>(s_shader)->SetUniformInt("u_Texture", 0);
}

void RenderCellLayer::OnUpdate()
{
	Renderer::BeginScene(*s_camera);
	for (size_t i = 0; i < MAX_TRANSFORMS * MAX_TRANSFORMS; i++)
	{
		Renderer::Submit(*s_vertexArray, *s_shader, _transforms[i].GetWorldMatrix());
	}
	Renderer::EndScene();
}

void RenderCellLayer::OnDetach()
{
}

Transform* RenderCellLayer::CreateTransforms()
{
	auto* result = new Transform[MAX_TRANSFORMS * MAX_TRANSFORMS];

	for (size_t i = 0; i < MAX_TRANSFORMS; i++)
	{
		for (size_t j = 0; j < MAX_TRANSFORMS; j++)
		{
			int index = i * MAX_TRANSFORMS + j;
			result[index].SetPosition(glm::vec3(j * 0.23f, i * 0.23f, 0));
			result[index].SetScale(glm::vec3(0.6f));
		}
	}

	return result;
}