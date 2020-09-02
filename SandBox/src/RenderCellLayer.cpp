#include "RenderCellLayer.h"
#include <GoblinEngine/Window/Platforms/OpenGL/OpenGLShader.h>
#include <GoblinEngine/Window/Platforms/OpenGL/OpenGLTexture.h>

using namespace GoblinEngine;

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
	auto vertexBuffer = GE_RENDER_API.CreateVertexBuffer(vertices, sizeof(vertices) / sizeof(float));

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
	auto indexBuffer = GE_RENDER_API.CreateIndexBuffer(indices, 6);

	s_vertexArray = GE_RENDER_API.CreateVertexArray();
	s_vertexArray->AddVertexBuffer(vertexBuffer);
	s_vertexArray->SetIndexBuffer(indexBuffer);

	TextFile shaderFile("C:\\dev\\GoblinEngine\\Sandbox\\src\\Assets\\staticOpjectShader.glsl");
	shaderFile.Load();
	s_shader.reset(new GoblinEngine::OpenGLShader(shaderFile));
	
	Image textureFile("C:\\dev\\GoblinEngine\\Sandbox\\src\\Assets\\waterTexture.jpg");
	textureFile.Load();
	s_texture = GE_RENDER_API.CreteTexture2D(textureFile);
	s_texture->Bind();
	std::static_pointer_cast<OpenGLShader>(s_shader)->SetUniformInt("u_Texture", 0);
}

void RenderCellLayer::OnUpdate()
{
	GoblinEngine::Renderer::BeginScene(*s_camera);
	for (size_t i = 0; i < MAX_TRANSFORMS * MAX_TRANSFORMS; i++)
	{
		GoblinEngine::Renderer::Submit(*s_vertexArray, *s_shader, _transforms[i].GetWorldMatrix());
	}
	GoblinEngine::Renderer::EndScene();
}

void RenderCellLayer::OnDetach()
{
}

GoblinEngine::Transform* RenderCellLayer::CreateTransforms()
{
	auto* result = new GoblinEngine::Transform[MAX_TRANSFORMS * MAX_TRANSFORMS];

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